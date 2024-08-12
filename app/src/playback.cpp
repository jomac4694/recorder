#include "playback.h"
#include "robot_impl.h"
#include "global_logger.h"
Playback::Playback()
{

}

Playback::~Playback()
{

}

void Playback::PlaybackLoop()
{
    LOG("Doing playback loop")

    mRunning.store(true);
    if (mPlaybackEvents->size() == 0)
    {
        mRunning.store(true);
        return;
    }
    for (int i = 0; i < mPlaybackEvents->size() - 1; i++)
    {
        if (mPaused.load())
            return;
      //  std::lock_guard<std::mutex> lock(mLock);
        auto evt = mPlaybackEvents->at(i);
        if (evt->GetName() == EventName::MOUSE_MOVE_EVENT)
        {
            mr::RobotImpl::MouseMove(evt);
        }
        else if (evt->GetName() == EventName::MOUSE_BUTTON_EVENT)
        {
            LOG("Playback: mouse BUTTON event")
            Input::Mouse::Action action = (Input::Mouse::Action) evt->GetField<uint16_t>(EventName::MOUSE_ACTION);
            if (action == Input::Mouse::Action::PRESS)
            {
                LOG("Playback: mouse BUTTON event PRESS")
                mr::RobotImpl::MousePress(evt);
            }
            else if (action == Input::Mouse::Action::RELEASE)
            {
                LOG("Playback: mouse BUTTON event RELEASE")
                mr::RobotImpl::MouseRelease(evt);
            }
        }
        else if (evt->GetName() == EventName::KEY_EVENT)
        {
            Input::KeyBoard::Action action = (Input::KeyBoard::Action) evt->GetField<uint16_t>(EventName::KEY_ACTION);
            if (action == Input::KeyBoard::Action::PRESS)
            {
                mr::RobotImpl::KeyPress(evt);
            }
            else if (action == Input::KeyBoard::Action::RELEASE)
            {
                mr::RobotImpl::KeyRelease(evt);
            }
        }

        auto ts = boost::posix_time::from_iso_string(evt->GetField<std::string>(EventName::TIMESTAMP));
        auto ts_next = boost::posix_time::from_iso_string(mPlaybackEvents->at(i+1)->GetField<std::string>(EventName::TIMESTAMP));
        auto wait_til = Utils::NowMilli() + (ts_next - ts).total_milliseconds();
        std::chrono::duration<int64_t, std::milli> dur(wait_til);
        auto tp = std::chrono::system_clock::time_point(
                std::chrono::duration_cast<std::chrono::system_clock::duration>(dur));
        std::this_thread::sleep_until(tp);
        
        std::unique_lock<std::mutex> lock(mPauseCVLock);
        LOG("Hitting WAIT")
        mPauseCV.wait(lock, [this] {
            return !this->mPaused.load();
        });
        LOG("Passed the WAIT")
    }
    
  //  mPlayRunning.store(false);
    LOG("Playbac loop done")
  //  auto p2 = std::shared_ptr<Event>(new PlaybackStatus());
  //  p2->SetField(EventName::PLAYBACK_STATUS, false);
  //  SendEvent(p2);
   // std::this_thread::yield();
    mPaused.store(false);
    mRunning.store(false);
    mPlaybackEvents->clear();
}

void Playback::Start(std::shared_ptr<std::vector<EventPtr>> events)
{
    if (mPaused.load())
    {
        mPaused.store(false);
        std::unique_lock<std::mutex> lock(mPauseCVLock);
        mPauseCV.notify_one();
        return;
    }
    mPlaybackEvents = events;
    if (!mRunning.load())
    {
        mPlaybackThread.reset(new std::thread(std::bind(&Playback::PlaybackLoop, this)));
        mPlaybackThread->detach();
    }
}

void Playback::Pause()
{
    mPaused.store(true);
}

bool Playback::IsPaused()
{
    return mPaused.load();
}

bool Playback::IsRunning()
{
    return mRunning.load();
}