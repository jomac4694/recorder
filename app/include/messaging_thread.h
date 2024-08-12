#ifndef MESSAGING_THREAD_H
#define MESSAGING_THREAD_H

#include "event.h"
#include <deque>
#include <functional>
#include <map>
#include <thread>
#include "event_queue.h"
#include <condition_variable>

typedef std::function<void(EventPtr)> Callback;
typedef std::map<std::string, Callback> CallbackMap;

// Message threads/queue BaseClass used to make components
class MessagingThread
{
    public:
        MessagingThread();
        ~MessagingThread() = default;
        void QueueEvent(EventPtr);
        void StartLoop();
    protected:
        void RegisterEvent(Callback callback, const std::string& event_name);
        void SendEvent(EventPtr);
        virtual void Activate() = 0;
    private:
        void EventLoop();
        EventQueue mEventQueue;
        CallbackMap mCallbacks;
        std::thread mMsgThread;
        std::mutex mEventWaitLock;
        std::condition_variable mEventWaitCV;

};

typedef std::shared_ptr<MessagingThread> MsgThreadPtr;
#endif