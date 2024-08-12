#include "event_queue.h"


EventPtr EventQueue::front()
{
    std::lock_guard<std::mutex> guard(mQueuetex);
    return mQueue.front();
}

void EventQueue::enqueue(EventPtr e)
{
    std::lock_guard<std::mutex> guard(mQueuetex);
    mQueue.push_back(e);
}

uint64_t EventQueue::size()
{
    std::lock_guard<std::mutex> guard(mQueuetex);
    return mQueue.size();
}

EventPtr EventQueue::deque()
{
    std::lock_guard<std::mutex> guard(mQueuetex);
    auto front = mQueue.front();
    mQueue.pop_front();
    return front;
}