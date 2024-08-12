#include "message_bus.h"
#include <thread>
#include <iostream>
#include "global_logger.h"


MessageBus& MessageBus::Instance()
{
    static MessageBus bus;
    return bus;
}

void MessageBus::AddMessage(MsgThreadPtr msg_thread)
{
    mMsgThreads.push_back(msg_thread);
}

void MessageBus::QueueEvent(EventPtr evt)
{
    mBusQueue.enqueue(evt);
    mEventWaitCV.notify_one();
}

void MessageBus::StartBus()
{
    for (auto& thread : mMsgThreads)
        thread->StartLoop();
    while (true)
    {
        if (mBusQueue.size() >= 1)
        {
            auto evt = mBusQueue.deque();
            for (auto& thread : mMsgThreads)
                thread->QueueEvent(evt);
        }
        else
        {
         //   LOG("Bus waiting for events")
            std::unique_lock<std::mutex> lock(mEventWaitLock);
            mEventWaitCV.wait(lock, [this] { return this->mBusQueue.size() >= 1;});
        }
    }
}