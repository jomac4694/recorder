#ifndef MY_EVENT_H
#define MY_EVENT_H
#include <string>
#include <map>
#include "event_macros.h"
#include "utils.h"
#include "input_enums.h"

typedef std::variant<
    std::string,
    uint16_t,
    int16_t,
    int32_t,
    uint32_t,
    bool,
    double, 
    float, 
    int8_t, 
    uint8_t, 
    uint64_t, 
    int64_t,
    Input::KeyBoard::Key,
    Input::Mouse::Action,
    Input::KeyBoard::Action,
    Input::Mouse::Button> EventType;

// Probably much better ways to do this but it works for these purposes.
namespace EventName
{
    // Event Header Fields
    constexpr char* TIMESTAMP = "TIMESTAMP";
    // Test Event/Fields
    constexpr char* TEST_EVENT = "TEST_EVENT";
    constexpr char* INT32_FIELD = "INT_FIELD";
    constexpr char* UINT32_FIELD = "UINT32_FIELD";
    constexpr char* FLOAT_FIELD = "FLOAT_FIELD";
    constexpr char* DOUBLE_FIELD = "DOUBLE_FIELD";
    constexpr char* STRING_FIELD = "STRING_FIELD";
    // Logging Event/Fields
    constexpr char* LOG_EVENT = "LOG_EVENT";
    constexpr char* LOG_MSG = "LOG_MSG";
    // MouseMoveEvent
    constexpr char* MOUSE_MOVE_EVENT = "MOUSE_MOVE_EVENT";
    constexpr char* MOUSE_X = "MOUSE_X";
    constexpr char* MOUSE_Y = "MOUSE_Y";
    constexpr char* MOUSE_MOVE_TS = "MOUSE_MOVE_TS";
    // MouseButtonEvent
    constexpr char* MOUSE_BUTTON_EVENT = "MOUSE_BUTTON_EVENT";
    constexpr char* MOUSE_BUTTON = "MOUSE_BUTTON";
    constexpr char* MOUSE_ACTION = "MOUSE_ACTION";
    constexpr char* MOUSE_BUTTON_TS = "MOUSE_BUTTON_TS";
    // KeyEvent
    constexpr char* KEY_EVENT = "KEY_EVENT";
    constexpr char* KEY_ACTION = "KEY_ACTION";
    constexpr char* KEY_KEY = "KEY_KEY";
    constexpr char* KEY_EVENT_TS = "KEY_EVENT_TS";
    // Playback Status
    constexpr char* PLAYBACK_STATUS_EVENT = "PLAYBACK_STATUS_EVENT";
    constexpr char* PLAYBACK_STATUS = "PLAYBACK_STATUS";

}

enum PbStatus
{
    INACTIVE,
    PAUSED,
    RUNNING
};

class Event
{
    public:
        Event(const std::string& name) : mName(name) {}
        virtual std::string GetName() = 0;
        template<typename T>
        T GetField(const std::string& f_name)
        {
            auto itr = mFieldsMap.find(f_name);
            if (itr != mFieldsMap.end())
            {
                auto variant = itr->second;
                return std::get<T>(variant);
            }
            else
            {
                throw std::runtime_error("GET Field does not exist for " + f_name);
            }
        }
        template<typename T>
        void SetField(const std::string& f_name, T val)
        {
            auto itr = mFieldsMap.find(f_name);
            if (itr != mFieldsMap.end())
            {
                EventType t = val;
                itr->second.swap(t);
            }
            else
            {
                throw std::runtime_error("SET Field does not exist for " + f_name);
            }
        }
    protected:
        std::string mName;
        std::map<std::string, EventType> mFieldsMap;

};

/*

// Use macros to more easily create new Event and Fields
// Resulting Event looks like this:

class LogEvent : public Event
{
    public:
        LogEvent() : Event(EventName::LOG_EVENT) {
            mFieldsMap = 
            {
                {EventName::LOG_MSG, std::string()},
            };
        }
        std::string GetName() override { return mName; }
};
*/

BEGIN_NEW_EVENT(TestEvent, TEST_EVENT)
ADD_FIELD(INT32_FIELD, int())
ADD_FIELD(UINT32_FIELD, uint32_t())
ADD_FIELD(FLOAT_FIELD, float())
ADD_FIELD(DOUBLE_FIELD, double())
ADD_FIELD(STRING_FIELD, std::string())
END_NEW_EVENT()

BEGIN_NEW_EVENT(LogEvent, LOG_EVENT)
ADD_FIELD(LOG_MSG, std::string())
END_NEW_EVENT()

BEGIN_NEW_EVENT(MouseMoveEvent, MOUSE_MOVE_EVENT)
ADD_FIELD(MOUSE_X, float())
ADD_FIELD(MOUSE_Y, float())
END_NEW_EVENT()

BEGIN_NEW_EVENT(KeyEvent, KEY_EVENT)
ADD_FIELD(KEY_ACTION, uint16_t())
ADD_FIELD(KEY_KEY, Input::KeyBoard::Key())
END_NEW_EVENT()

BEGIN_NEW_EVENT(PlaybackStatus, PLAYBACK_STATUS_EVENT)
ADD_FIELD(PLAYBACK_STATUS, uint8_t())
END_NEW_EVENT()

BEGIN_NEW_EVENT(MouseButtonEvent, MOUSE_BUTTON_EVENT)
ADD_FIELD(MOUSE_BUTTON, uint16_t())
ADD_FIELD(MOUSE_ACTION, uint16_t())
ADD_FIELD(MOUSE_X, float())
ADD_FIELD(MOUSE_Y, float())
END_NEW_EVENT()

typedef std::shared_ptr<Event> EventPtr;

template<typename T> 
EventPtr make_event_ptr()
{
    auto e = std::shared_ptr<Event>(new T());
    e->SetField(EventName::TIMESTAMP, Utils::NowString());
    return e;
}
#endif