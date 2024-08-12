#include "test_comp.h"
#include <iostream>
#include "global_logger.h"
#include "robot_impl.h"
#include "boost/date_time/posix_time/posix_time.hpp"
TestComp::TestComp()
{
    auto cb = std::bind(&TestComp::HandleTestEvent, this, std::placeholders::_1);
    RegisterEvent(cb, EventName::TEST_EVENT);
}

void TestComp::Activate()
{
    LOG("Starting Test Component 1")
}

void TestComp::HandleTestEvent(EventPtr e)
{
    std::stringstream ss;
    auto int_field = e->GetField<int32_t>(EventName::INT32_FIELD);
    auto dbl_field = e->GetField<double>(EventName::DOUBLE_FIELD);
    auto string_field = e->GetField<std::string>(EventName::STRING_FIELD);
    ss << "TestComp1 " << "f1: " << int_field << " f2: " << dbl_field << " f3: " << string_field; 
    LOG(ss.str())
}

TestComp2::TestComp2()
{
    auto cb = std::bind(&TestComp2::HandleMouseMoveEvent, this, std::placeholders::_1);
    RegisterEvent(cb, EventName::MOUSE_MOVE_EVENT);
    RegisterEvent(std::bind(&TestComp2::HandleKeyEvent, this, std::placeholders::_1), EventName::KEY_EVENT);
}

void TestComp2::Activate()
{
    LOG("Starting Test Component 2")
}

uint64_t NowMilli()
{
    using namespace std::chrono;
    return duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
}

void TestComp2::DoPlayback()
{
    LOG("Doing playback loop")

   // mPlayRunning.store(true);
    if (mPlaybackEvents.size() == 0)
        return;
    for (int i = 0; i < mPlaybackEvents.size() - 2; i++)
    {

      //  std::lock_guard<std::mutex> lock(mLock);
        auto evt = mPlaybackEvents[i];
        if (evt->GetName() == EventName::MOUSE_MOVE_EVENT)
        {
            auto ts = boost::posix_time::from_iso_string(evt->GetField<std::string>(EventName::MOUSE_MOVE_TS));
            auto ts_next = boost::posix_time::from_iso_string(mPlaybackEvents[i+1]->GetField<std::string>(EventName::MOUSE_MOVE_TS));
            auto wait_til = NowMilli() + (ts_next - ts).total_milliseconds();
            long num = 0;
            mr::RobotImpl::MouseMove(evt);
            auto now = NowMilli();
            while (now < wait_til)
                now = NowMilli();
        }
        
    }
    
    mPlayRunning.store(false);
    LOG("Playbac loop done")
  //  auto p2 = std::shared_ptr<Event>(new PlaybackStatus());
  //  p2->SetField(EventName::PLAYBACK_STATUS, false);
  //  SendEvent(p2);
   // std::this_thread::yield();
    mPlaybackEvents.clear();
}
void TestComp2::HandleKeyEvent(EventPtr e)
{
    std::stringstream ss;
    auto action = e->GetField<uint16_t>(EventName::KEY_ACTION);
    auto key = e->GetField<uint16_t>(EventName::KEY_KEY);
    if (key == 57 && !mPlayRunning.load())
    {
        mPlaybackThread = std::thread(std::bind(&TestComp2::DoPlayback, this));
        mPlaybackThread.detach();
        mPlayRunning.store(true);
        return;
    }
    auto ts = e->GetField<std::string>(EventName::KEY_EVENT_TS);
    ss << "TestComp2 KeyEvent " << "key: " << key << " action: " << action << " ts: " << ts;
    LOG(ss.str())
   // mPlaybackEvents.push_back(e);
}

void TestComp2::HandleMouseMoveEvent(EventPtr e)
{
    if (mPlayRunning.load())
        return; 
    std::stringstream ss;
    auto x = e->GetField<float>(EventName::MOUSE_X);
    auto y = e->GetField<float>(EventName::MOUSE_Y);
    auto string_field = e->GetField<std::string>(EventName::MOUSE_MOVE_TS);
    ss << "TestComp2 " << "f1: " << x << " f2: " << y << " f3: " << string_field; 
    LOG(ss.str())
    mPlaybackEvents.push_back(e);
}