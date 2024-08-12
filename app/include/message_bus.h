#ifndef MESSAGE_BUS_H
#define MESSAGE_BUS_H
#include "messaging_thread.h"
#include <vector>

// Simple message bus which manages N number of MessagingThreads
class MessageBus
{
    public:
        MessageBus() = default;
        ~MessageBus() = default;
        static MessageBus& Instance();
        void StartBus();
        void QueueEvent(EventPtr);
        void AddMessage(MsgThreadPtr msg_thread);
    private:
        std::vector<MsgThreadPtr> mMsgThreads;
        EventQueue mBusQueue;
        std::mutex mEventWaitLock;
        std::condition_variable mEventWaitCV;
};

#endif