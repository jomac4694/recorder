#include "mac_global_listener.h"
#include <chrono>
#include <iostream>
#include "boost/date_time/posix_time/posix_time.hpp"
#include "input_enums.h"
namespace mr
{
    
        Input::KeyBoard::Key virtualKeyToInputKey(uint16_t virtualKey)
    {
        // clang-format off
        switch (virtualKey)
        {
        case kVK_ANSI_A:           return Input::KeyBoard::A;
        case kVK_ANSI_B:           return Input::KeyBoard::B;
        case kVK_ANSI_C:           return Input::KeyBoard::C;
        case kVK_ANSI_D:           return Input::KeyBoard::D;
        case kVK_ANSI_E:           return Input::KeyBoard::E;
        case kVK_ANSI_F:           return Input::KeyBoard::F;
        case kVK_ANSI_G:           return Input::KeyBoard::G;
        case kVK_ANSI_H:           return Input::KeyBoard::H;
        case kVK_ANSI_I:           return Input::KeyBoard::I;
        case kVK_ANSI_J:           return Input::KeyBoard::J;
        case kVK_ANSI_K:           return Input::KeyBoard::K;
        case kVK_ANSI_L:           return Input::KeyBoard::L;
        case kVK_ANSI_M:           return Input::KeyBoard::M;
        case kVK_ANSI_N:           return Input::KeyBoard::N;
        case kVK_ANSI_O:           return Input::KeyBoard::O;
        case kVK_ANSI_P:           return Input::KeyBoard::P;
        case kVK_ANSI_Q:           return Input::KeyBoard::Q;
        case kVK_ANSI_R:           return Input::KeyBoard::R;
        case kVK_ANSI_S:           return Input::KeyBoard::S;
        case kVK_ANSI_T:           return Input::KeyBoard::T;
        case kVK_ANSI_U:           return Input::KeyBoard::U;
        case kVK_ANSI_V:           return Input::KeyBoard::V;
        case kVK_ANSI_W:           return Input::KeyBoard::W;
        case kVK_ANSI_X:           return Input::KeyBoard::X;
        case kVK_ANSI_Y:           return Input::KeyBoard::Y;
        case kVK_ANSI_Z:           return Input::KeyBoard::Z;
        case kVK_ANSI_0:           return Input::KeyBoard::Num0;
        case kVK_ANSI_1:           return Input::KeyBoard::Num1;
        case kVK_ANSI_2:           return Input::KeyBoard::Num2;
        case kVK_ANSI_3:           return Input::KeyBoard::Num3;
        case kVK_ANSI_4:           return Input::KeyBoard::Num4;
        case kVK_ANSI_5:           return Input::KeyBoard::Num5;
        case kVK_ANSI_6:           return Input::KeyBoard::Num6;
        case kVK_ANSI_7:           return Input::KeyBoard::Num7;
        case kVK_ANSI_8:           return Input::KeyBoard::Num8;
        case kVK_ANSI_9:           return Input::KeyBoard::Num9;
        case kVK_Escape:     return Input::KeyBoard::Escape;
       // case kVK_ANSI_LCONTROL:   return Input::KeyBoard::LControl;
       // case kVK_ANSI_LSHIFT:     return Input::KeyBoard::LShift;
       // case kVK_ANSI_LMENU:      return Input::KeyBoard::LAlt;
        //case kVK_ANSI_LWIN:       return Input::KeyBoard::LSystem;
        case kVK_RightControl:   return Input::KeyBoard::RControl;
        case kVK_RightShift:     return Input::KeyBoard::RShift;
      //  case kVK_ANSI_RMENU:      return Input::KeyBoard::RAlt;
      //  case kVK_ANSI_RWIN:       return Input::KeyBoard::RSystem;
      //  case kVK_ANSI_APPS:       return Input::KeyBoard::Menu;
        case kVK_ANSI_LeftBracket:      return Input::KeyBoard::LBracket;
        case kVK_ANSI_RightBracket:      return Input::KeyBoard::RBracket;
        case kVK_ANSI_Semicolon:      return Input::KeyBoard::Semicolon;
        case kVK_ANSI_Comma:  return Input::KeyBoard::Comma;
        case kVK_ANSI_Period: return Input::KeyBoard::Period;
       // case kVK_ANSI_OEM_7:      return Input::KeyBoard::Apostrophe;
        case kVK_ANSI_Slash:      return Input::KeyBoard::Slash;
        case kVK_ANSI_Backslash:      return Input::KeyBoard::Backslash;
       // case kVK_ANSI_OEM_3:      return Input::KeyBoard::Grave;
        case kVK_ANSI_Equal:   return Input::KeyBoard::Equal;
        case kVK_ANSI_Minus:  return Input::KeyBoard::Hyphen;
        case kVK_Space:      return Input::KeyBoard::Space;
        case kVK_Return:     return Input::KeyBoard::Enter;
        case kVK_Delete:       return Input::KeyBoard::Backspace;
        case kVK_Tab:        return Input::KeyBoard::Tab;
        case kVK_PageUp:      return Input::KeyBoard::PageUp;
        case kVK_PageDown:       return Input::KeyBoard::PageDown;
        case kVK_End:        return Input::KeyBoard::End;
        case kVK_Home:       return Input::KeyBoard::Home;
     //   case kVK_ANSI_INSERT:     return Input::KeyBoard::Insert;
        case kVK_ANSI_KeypadPlus:        return Input::KeyBoard::Add;
        case kVK_ANSI_KeypadMinus:   return Input::KeyBoard::Subtract;
        case kVK_ANSI_KeypadMultiply:   return Input::KeyBoard::Multiply;
        case kVK_ANSI_KeypadDivide:     return Input::KeyBoard::Divide;
        case kVK_LeftArrow:       return Input::KeyBoard::Left;
        case kVK_RightArrow:      return Input::KeyBoard::Right;
        case kVK_UpArrow:         return Input::KeyBoard::Up;
        case kVK_DownArrow:       return Input::KeyBoard::Down;
        case kVK_ANSI_Keypad0:    return Input::KeyBoard::Numpad0;
        case kVK_ANSI_Keypad1:    return Input::KeyBoard::Numpad1;
        case kVK_ANSI_Keypad2:    return Input::KeyBoard::Numpad2;
        case kVK_ANSI_Keypad3:    return Input::KeyBoard::Numpad3;
        case kVK_ANSI_Keypad4:    return Input::KeyBoard::Numpad4;
        case kVK_ANSI_Keypad5:    return Input::KeyBoard::Numpad5;
        case kVK_ANSI_Keypad6:    return Input::KeyBoard::Numpad6;
        case kVK_ANSI_Keypad7:    return Input::KeyBoard::Numpad7;
        case kVK_ANSI_Keypad8:    return Input::KeyBoard::Numpad8;
        case kVK_ANSI_Keypad9:    return Input::KeyBoard::Numpad9;
        case kVK_F1:         return Input::KeyBoard::F1;
        case kVK_F2:         return Input::KeyBoard::F2;
        case kVK_F3:         return Input::KeyBoard::F3;
        case kVK_F4:         return Input::KeyBoard::F4;
        case kVK_F5:         return Input::KeyBoard::F5;
        case kVK_F6:         return Input::KeyBoard::F6;
        case kVK_F7:         return Input::KeyBoard::F7;
        case kVK_F8:         return Input::KeyBoard::F8;
        case kVK_F9:         return Input::KeyBoard::F9;
        case kVK_F10:        return Input::KeyBoard::F10;
        case kVK_F11:        return Input::KeyBoard::F11;
        case kVK_F12:        return Input::KeyBoard::F12;
        case kVK_F13:        return Input::KeyBoard::F13;
        case kVK_F14:        return Input::KeyBoard::F14;
        case kVK_F15:        return Input::KeyBoard::F15;
       // case kVK_PAUSE:      return Input::KeyBoard::Pause;
        default:            return Input::KeyBoard::Unknown;
        }
        // clang-format on
    }
    
}
MacGlobalListener::MacGlobalListener()
{
    RegisterEvent(std::bind(&MacGlobalListener::HandlePlaybackStatus, this, std::placeholders::_1), EventName::PLAYBACK_STATUS_EVENT);
}

void MacGlobalListener::HandlePlaybackStatus(EventPtr e)
{
    mPlaybackRunning = e->GetField<bool>(EventName::PLAYBACK_STATUS);
}

void MacGlobalListener::Activate()
{
    mListenThread = std::thread([this]{
           CFRunLoopRef ref = CFRunLoopGetCurrent();

    CFMachPortRef tap =
        CGEventTapCreate(kCGHIDEventTap, kCGHeadInsertEventTap,
                         kCGEventTapOptionDefault, kCGEventMaskForAllEvents, OnInput, this);

    
    CFRunLoopSourceRef source =
        CFMachPortCreateRunLoopSource(kCFAllocatorDefault, tap, 0);
    CFRunLoopAddSource(ref, source, kCFRunLoopCommonModes);
    CGEventTapEnable(tap, true);

    CFRunLoopRun();
    //CFRunLoopRemoveSource(ref, source, kCFRunLoopCommonModes);
    //CFRelease(source);
    //CFRelease(tap);
    });
}



CGEventRef MacGlobalListener::OnInput(CGEventTapProxy proxy, CGEventType type, CGEventRef event, void *userInfo)
{
  //  std::cout << "got a input event" << std::endl;

    MacGlobalListener* ls = (MacGlobalListener*) userInfo;

   // auto t1 = std::shared_ptr<TestEvent>(new TestEvent());
   // t1->SetField(EventName::STRING_FIELD, "Input Received");

    //std::cout << "in here now" << std::endl;
    if (type == kCGEventLeftMouseUp)
    {
        //std::cout << "left mouse is up" << std::endl;
        CGPoint p = CGEventGetLocation(event);
        auto t1 = std::shared_ptr<Event>(new MouseButtonEvent());
        t1->SetField(EventName::MOUSE_ACTION, (uint16_t) Input::Mouse::Action::RELEASE);
        t1->SetField(EventName::MOUSE_BUTTON, (uint16_t) Input::Mouse::Button::Left);
        t1->SetField(EventName::MOUSE_X, static_cast<float>(p.x));
        t1->SetField(EventName::MOUSE_Y, static_cast<float>(p.y));
        auto timeUTC = boost::posix_time::microsec_clock::universal_time();
        t1->SetField(EventName::TIMESTAMP, to_iso_string(timeUTC));
        ls->SendEvent(t1);
    }
    else if (type == kCGEventLeftMouseDown)
    {
        CGPoint p = CGEventGetLocation(event);
        auto t1 = std::shared_ptr<Event>(new MouseButtonEvent());
        t1->SetField(EventName::MOUSE_ACTION, (uint16_t) Input::Mouse::Action::PRESS);
        t1->SetField(EventName::MOUSE_BUTTON, (uint16_t) Input::Mouse::Button::Left);
        t1->SetField(EventName::MOUSE_X, static_cast<float>(p.x));
        t1->SetField(EventName::MOUSE_Y, static_cast<float>(p.y));
        auto timeUTC = boost::posix_time::microsec_clock::universal_time();
        t1->SetField(EventName::TIMESTAMP, to_iso_string(timeUTC));
        ls->SendEvent(t1);
    }
    else if (type == kCGEventKeyUp)
    {
        
        CGKeyCode code = CGEventGetIntegerValueField(event, kCGKeyboardEventKeycode);
       // if ((uint16_t) mr::virtualKeyToInputKey(code) == 57)
       // {
       //       auto p2 = std::shared_ptr<Event>(new PlaybackStatus());
     //         p2->SetField(EventName::PLAYBACK_STATUS, false);
   //           SendEvent(p2);
     //   }
     //   UniCharCount c = 1;
     //   UniChar ch[1];
      //  CGEventKeyboardGetUnicodeString(event, 1,  &c, ch);
        auto t1 = std::shared_ptr<Event>(new KeyEvent());
        t1->SetField(EventName::KEY_ACTION, (uint16_t) Input::KeyBoard::Action::RELEASE);
        t1->SetField(EventName::KEY_KEY, mr::virtualKeyToInputKey(code));
        auto timeUTC = boost::posix_time::microsec_clock::universal_time();
        t1->SetField(EventName::TIMESTAMP, to_iso_string(timeUTC));
        ls->SendEvent(t1);
    }
    else if (type == kCGEventKeyDown)
    {
        CGKeyCode code = CGEventGetIntegerValueField(event, kCGKeyboardEventKeycode);
        std::cout << "key=" << code << std::endl;
        UniCharCount c = 1;
        UniChar ch[1];
        CGEventKeyboardGetUnicodeString(event, 1,  &c, ch);
        std::cout << "key1=" << ch[0] << std::endl;
        auto t1 = make_event_ptr<KeyEvent>();
        t1->SetField(EventName::KEY_ACTION, (uint16_t) Input::KeyBoard::Action::PRESS);
        t1->SetField(EventName::KEY_KEY, mr::virtualKeyToInputKey(code));
        ls->SendEvent(t1);
    }
    else if (type == kCGEventMouseMoved)
    {

      //  std::cout << "mouse moving" << std::endl;
        CGPoint p = CGEventGetLocation(event);
        auto t1 = make_event_ptr<MouseMoveEvent>();
        t1->SetField(EventName::MOUSE_X, static_cast<float>(p.x));
        t1->SetField(EventName::MOUSE_Y, static_cast<float>(p.y));
        ls->SendEvent(t1);
    }
    return event;
}


