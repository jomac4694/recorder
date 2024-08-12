#ifndef EVENT_QUEUE_H
#define EVENT_QUEUE_H

#include "event.h"
#include <deque>
#include <mutex>

// Very simple syncrhonized event queue for bus and messaging threads
class EventQueue
{
    public:
        EventQueue() = default;
        ~EventQueue() = default;

        std::deque<EventPtr> mQueue;
        EventPtr front();
        void enqueue(EventPtr e);
        EventPtr deque();
        uint64_t size();
    private:
        std::mutex mQueuetex;
};

#endif