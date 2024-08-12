#include "recorder.h"
#include "global_logger.h"
#include "robot_impl.h"
#include "utils.h"
#include "playback.h"

Recorder::Recorder() :
mPlaybackEvents(new std::vector<EventPtr>())
{
    auto cb = std::bind(&Recorder::HandleMouseMoveEvent, this, std::placeholders::_1);
    RegisterEvent(cb, EventName::MOUSE_MOVE_EVENT);
    RegisterEvent(std::bind(&Recorder::HandleKeyEvent, this, std::placeholders::_1), EventName::KEY_EVENT); 
    RegisterEvent(std::bind(&Recorder::HandleMouseButtonEvent, this, std::placeholders::_1), EventName::MOUSE_BUTTON_EVENT);
}

void Recorder::Activate()
{
    LOG("Activating Recorder")
}


void Recorder::HandleKeyEvent(EventPtr e)
{

    std::stringstream ss;
    auto action = e->GetField<uint16_t>(EventName::KEY_ACTION);
    auto key = e->GetField<Input::KeyBoard::Key>(EventName::KEY_KEY);
    if (mPlayback.IsRunning() && key != 57)
        return;
    if (key == 57 && (Input::KeyBoard::Action) action == Input::KeyBoard::Action::PRESS) 
        return;
    if (key == 57 && (Input::KeyBoard::Action) action == Input::KeyBoard::Action::RELEASE)
    {
        if (!mPlayback.IsRunning())
            mPlayback.Start(mPlaybackEvents);
        else if (mPlayback.IsRunning() && !mPlayback.IsPaused())
            mPlayback.Pause();
        else if (mPlayback.IsRunning() && mPlayback.IsPaused())    
            mPlayback.Start(mPlaybackEvents);
        return;
    }
    auto ts = e->GetField<std::string>(EventName::TIMESTAMP);
    ss << "TestComp2 KeyEvent " << "key: " << key << " action: " << action << " ts: " << ts;
    LOG(ss.str())
    mPlaybackEvents->push_back(e);
    LOG("QUEUE SIZE: " + std::to_string(mPlaybackEvents->size()))
}

void Recorder::HandleMouseMoveEvent(EventPtr e)
{
    if (mPlayback.IsRunning())
        return; 
    std::stringstream ss;
    auto x = e->GetField<float>(EventName::MOUSE_X);
    auto y = e->GetField<float>(EventName::MOUSE_Y);
    auto string_field = e->GetField<std::string>(EventName::TIMESTAMP);
    ss << "TestComp2 " << "f1: " << x << " f2: " << y << " f3: " << string_field; 
    LOG(ss.str())
    mPlaybackEvents->push_back(e);
}

void Recorder::HandleMouseButtonEvent(EventPtr e)
{
    if (mPlayback.IsRunning())
        return; 
    
    mPlaybackEvents->push_back(e);
}