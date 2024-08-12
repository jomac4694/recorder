#ifndef RECORDER_H
#define RECORDER_H
#include "playback.h"
#include "messaging_thread.h"
class Recorder : public MessagingThread
{
    public:
        Recorder();
        ~Recorder() = default;
        void HandleMouseMoveEvent(EventPtr event);
        void HandleKeyEvent(EventPtr event);
        void HandleMouseButtonEvent(EventPtr event);
        void DoPlayback();
    protected:
        void Activate() override;
    private:
        std::shared_ptr<std::vector<EventPtr>> mPlaybackEvents;
        Playback mPlayback;
        std::mutex mLock;        
};

#endif