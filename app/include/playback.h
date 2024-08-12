#ifndef PLAYBACK_H
#define PLAYBACK_H
#include <thread>
#include "event.h"
class Playback
{
    public:
        Playback();
        ~Playback();
        void Start(std::shared_ptr<std::vector<EventPtr>> events);
        void Pause();
        bool IsRunning();
        bool IsPaused();
    private:
        void PlaybackLoop();
        std::shared_ptr<std::vector<EventPtr>> mPlaybackEvents;
        std::unique_ptr<std::thread> mPlaybackThread;
        uint32_t mCurrEvent{0};
        std::atomic_bool mPaused{false};
        std::atomic_bool mRunning{false};
        std::condition_variable mPauseCV;
        std::mutex mPauseCVLock;
};
#endif