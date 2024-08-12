#ifndef TEST_COMP_H
#define TEST_COMP_H
#include "messaging_thread.h"

class TestComp : public MessagingThread
{
    public:
        TestComp();
        ~TestComp() = default;
        void HandleTestEvent(EventPtr event);
    protected:
        void Activate() override;
    private:

};

class TestComp2 : public MessagingThread
{
    public:
        TestComp2();
        ~TestComp2() = default;
        void HandleMouseMoveEvent(EventPtr event);
        void HandleKeyEvent(EventPtr event);
        void DoPlayback();
    protected:
        void Activate() override;
    private:
        std::vector<EventPtr> mPlaybackEvents;
        std::thread mPlaybackThread;
        std::atomic_bool mPlayRunning{false};
        std::mutex mLock;
};
#endif