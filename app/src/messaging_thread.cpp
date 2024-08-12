#include "messaging_thread.h"
#include <iostream>
#include "global_logger.h"
#include "message_bus.h"
MessagingThread::MessagingThread()
{

}

void MessagingThread::StartLoop()
{
        mMsgThread = std::thread(&MessagingThread::EventLoop, this);
        Activate();
}
void MessagingThread::EventLoop()
{
    while (true)
    {
        if (mEventQueue.size() >= 1)
        {
            auto evt = mEventQueue.deque();
            auto itr = mCallbacks.find(evt->GetName());

            if (itr != mCallbacks.end())
            {
                std::stringstream ss;
                ss << "Executing callback for Event: " << evt->GetName()
                << " on Thread: " << mMsgThread.get_id();
                auto evt_callback = itr->second;
                evt_callback(evt);
            }
            else
            {
                std::stringstream ss;
                ss << "No callback registered for Event: " << evt->GetName() << std::endl;
            }
        }
        else
        {
         //   LOG("Queue is empty, sleeping")
            std::unique_lock<std::mutex> lock(mEventWaitLock);
            mEventWaitCV.wait(lock, [this] {return this->mEventQueue.size() >= 1;});
        }
    }
}
void MessagingThread::RegisterEvent(Callback callback, const std::string& event_name)
{
    mCallbacks.insert({event_name, callback});
}

void MessagingThread::QueueEvent(EventPtr evt)
{
  //  LOG("Queue Event happening")
    mEventQueue.enqueue(evt);
    mEventWaitCV.notify_one();
}

void MessagingThread::SendEvent(EventPtr e)
{
    MessageBus::Instance().QueueEvent(e);
}