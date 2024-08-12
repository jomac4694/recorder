#include "robot_impl.h"
#include "ApplicationServices/ApplicationServices.h"
#include <iostream>
namespace mr
{
    uint16_t InputKeyToVirtualKey(Input::KeyBoard::Key key)
    {
        switch (key)
        {
        case Input::KeyBoard::A:
            return kVK_ANSI_A;
        case Input::KeyBoard::B:
            return kVK_ANSI_B;
        case Input::KeyBoard::C:
            return kVK_ANSI_C;
        case Input::KeyBoard::D:
            return kVK_ANSI_D;
        case Input::KeyBoard::E:
            return kVK_ANSI_E;
        case Input::KeyBoard::F:
            return kVK_ANSI_F;
        case Input::KeyBoard::G:
            return kVK_ANSI_G;
        case Input::KeyBoard::H:
            return kVK_ANSI_H;
        case Input::KeyBoard::I:
            return kVK_ANSI_I;
        case Input::KeyBoard::J:
            return kVK_ANSI_J;
        case Input::KeyBoard::K:
            return kVK_ANSI_K;
        case Input::KeyBoard::L:
            return kVK_ANSI_L;
        case Input::KeyBoard::M:
            return kVK_ANSI_M;
        case Input::KeyBoard::N:
            return kVK_ANSI_N;
        case Input::KeyBoard::O:
            return kVK_ANSI_O;
        case Input::KeyBoard::P:
            return kVK_ANSI_P;
        case Input::KeyBoard::Q:
            return kVK_ANSI_Q;
        case Input::KeyBoard::R:
            return kVK_ANSI_R;
        case Input::KeyBoard::S:
            return kVK_ANSI_S;
        case Input::KeyBoard::T:
            return kVK_ANSI_T;
        case Input::KeyBoard::U:
            return kVK_ANSI_U;
        case Input::KeyBoard::V:
            return kVK_ANSI_V;
        case Input::KeyBoard::W:
            return kVK_ANSI_W;
        case Input::KeyBoard::X:
            return kVK_ANSI_X;
        case Input::KeyBoard::Y:
            return kVK_ANSI_Y;
        case Input::KeyBoard::Z:
            return kVK_ANSI_Z;
        case Input::KeyBoard::Num0:
            return kVK_ANSI_0;
        case Input::KeyBoard::Num1:
            return kVK_ANSI_1;
        case Input::KeyBoard::Num2:
            return kVK_ANSI_2;
        case Input::KeyBoard::Num3:
            return kVK_ANSI_3;
        case Input::KeyBoard::Num4:
            return kVK_ANSI_4;
        case Input::KeyBoard::Num5:
            return kVK_ANSI_5;
        case Input::KeyBoard::Num6:
            return kVK_ANSI_6;
        case Input::KeyBoard::Num7:
            return kVK_ANSI_7;
        case Input::KeyBoard::Num8:
            return kVK_ANSI_8;
        case Input::KeyBoard::Num9:
            return kVK_ANSI_9;
        case Input::KeyBoard::Escape:
            return kVK_Escape;
        // case Input::KeyBoard::LControl:	return kVK_ANSI_LCONTROL;
        // case Input::KeyBoard::LShift:	return kVK_ANSI_LSHIFT;
        // case Input::KeyBoard::LAlt:	return kVK_ANSI_LMENU;
        // case Input::KeyBoard::LSystem:	return kVK_ANSI_LWIN;
        case Input::KeyBoard::RControl:
            return kVK_RightControl;
        case Input::KeyBoard::RShift:
            return kVK_RightShift;
        // case Input::KeyBoard::RAlt:	return kVK_ANSI_RMENU;
        // case Input::KeyBoard::RSystem:	return kVK_ANSI_RWIN;
        // case Input::KeyBoard::Menu:	return kVK_ANSI_APPS;
        case Input::KeyBoard::LBracket:
            return kVK_ANSI_LeftBracket;
        case Input::KeyBoard::RBracket:
            return kVK_ANSI_RightBracket;
        case Input::KeyBoard::Semicolon:
            return kVK_ANSI_Semicolon;
        case Input::KeyBoard::Comma:
            return kVK_ANSI_Comma;
        case Input::KeyBoard::Period:
            return kVK_ANSI_Period;
        // case Input::KeyBoard::Apostrophe:	return kVK_ANSI_OEM_7;
        case Input::KeyBoard::Slash:
            return kVK_ANSI_Slash;
        case Input::KeyBoard::Backslash:
            return kVK_ANSI_Backslash;
        // case Input::KeyBoard::Grave:	return kVK_ANSI_OEM_3;
        case Input::KeyBoard::Equal:
            return kVK_ANSI_Equal;
        case Input::KeyBoard::Hyphen:
            return kVK_ANSI_Minus;
        case Input::KeyBoard::Space:
            return kVK_Space;
        case Input::KeyBoard::Enter:
            return kVK_Return;
        case Input::KeyBoard::Backspace:
            return kVK_Delete;
        case Input::KeyBoard::Tab:
            return kVK_Tab;
        case Input::KeyBoard::PageUp:
            return kVK_PageUp;
        case Input::KeyBoard::PageDown:
            return kVK_PageDown;
        case Input::KeyBoard::End:
            return kVK_End;
        case Input::KeyBoard::Home:
            return kVK_Home;
        //  case Input::KeyBoard::Insert:	return kVK_ANSI_INSERT;
        case Input::KeyBoard::Add:
            return kVK_ANSI_KeypadPlus;
        case Input::KeyBoard::Subtract:
            return kVK_ANSI_KeypadMinus;
        case Input::KeyBoard::Multiply:
            return kVK_ANSI_KeypadMultiply;
        case Input::KeyBoard::Divide:
            return kVK_ANSI_KeypadDivide;
        case Input::KeyBoard::Left:
            return kVK_LeftArrow;
        case Input::KeyBoard::Right:
            return kVK_RightArrow;
        case Input::KeyBoard::Up:
            return kVK_UpArrow;
        case Input::KeyBoard::Down:
            return kVK_DownArrow;
        case Input::KeyBoard::Numpad0:
            return kVK_ANSI_Keypad0;
        case Input::KeyBoard::Numpad1:
            return kVK_ANSI_Keypad1;
        case Input::KeyBoard::Numpad2:
            return kVK_ANSI_Keypad2;
        case Input::KeyBoard::Numpad3:
            return kVK_ANSI_Keypad3;
        case Input::KeyBoard::Numpad4:
            return kVK_ANSI_Keypad4;
        case Input::KeyBoard::Numpad5:
            return kVK_ANSI_Keypad5;
        case Input::KeyBoard::Numpad6:
            return kVK_ANSI_Keypad6;
        case Input::KeyBoard::Numpad7:
            return kVK_ANSI_Keypad7;
        case Input::KeyBoard::Numpad8:
            return kVK_ANSI_Keypad8;
        case Input::KeyBoard::Numpad9:
            return kVK_ANSI_Keypad9;
        case Input::KeyBoard::F1:
            return kVK_F1;
        case Input::KeyBoard::F2:
            return kVK_F2;
        case Input::KeyBoard::F3:
            return kVK_F3;
        case Input::KeyBoard::F4:
            return kVK_F4;
        case Input::KeyBoard::F5:
            return kVK_F5;
        case Input::KeyBoard::F6:
            return kVK_F6;
        case Input::KeyBoard::F7:
            return kVK_F7;
        case Input::KeyBoard::F8:
            return kVK_F8;
        case Input::KeyBoard::F9:
            return kVK_F9;
        case Input::KeyBoard::F10:
            return kVK_F10;
        case Input::KeyBoard::F11:
            return kVK_F11;
        case Input::KeyBoard::F12:
            return kVK_F12;
        case Input::KeyBoard::F13:
            return kVK_F13;
        case Input::KeyBoard::F14:
            return kVK_F14;
        case Input::KeyBoard::F15:
            return kVK_F15;
        default:
            // case Input::KeyBoard::Pause:	return kVK_PAUSE;
        }
    }

    void PostKeyEvent(uint16_t key, bool key_down)
    {
            // Create an HID hardware event source
    CGEventSourceRef src = CGEventSourceCreate(kCGEventSourceStateHIDSystemState);

    // Create a new keyboard key release event
    CGEventRef evt = CGEventCreateKeyboardEvent(src, (CGKeyCode) key, key_down);

    // Post keyboard event and release
    CGEventPost (kCGHIDEventTap, evt);
    CFRelease (evt); 
    CFRelease (src);
    }
    void PostMouseEvent(CGMouseButton button, CGEventType type, CGPoint location)
    {
        CGEventRef event = CGEventCreateMouseEvent(NULL, type, location, button);
        CGEventSetType(event, type);
        CGEventPost(kCGHIDEventTap, event);
        CFRelease(event);
    }
}

namespace mr::RobotImpl
{
    void KeyPress(EventPtr e)
    {
       // std::cout << "Mac Key press" << std::endl;
        PostKeyEvent(InputKeyToVirtualKey(e->GetField<Input::KeyBoard::Key>(EventName::KEY_KEY)), true);
    }

    void KeyRelease(EventPtr e)
    {
      //  std::cout << "Mac key release" << std::endl;
        PostKeyEvent(InputKeyToVirtualKey(e->GetField<Input::KeyBoard::Key>(EventName::KEY_KEY)), false);
    }

    void MouseMove(EventPtr e)
    {
        auto x = e->GetField<float>(EventName::MOUSE_X);
        auto y = e->GetField<float>(EventName::MOUSE_Y);
     //   std::cout << "Bout to do call" << std::endl;
        CGPoint location = CGPointMake(x, y);
        mr::PostMouseEvent(kCGMouseButtonLeft, kCGEventMouseMoved, location);
    }

    void MousePress(EventPtr e)
    {
        auto x = e->GetField<float>(EventName::MOUSE_X);
        auto y = e->GetField<float>(EventName::MOUSE_Y);
        auto b = (Input::Mouse::Button) e->GetField<uint16_t>(EventName::MOUSE_BUTTON);
        CGEventType type = b == Input::Mouse::Button::Left ? kCGEventLeftMouseDown : kCGEventRightMouseDown;
        CGMouseButton button = b == Input::Mouse::Button::Left ? kCGMouseButtonLeft : kCGMouseButtonRight;
        CGPoint location;
        location.x = x;
        location.y = y;
        PostMouseEvent(button, type, location);
    }

    void MouseRelease(EventPtr e)
    {
        auto x = e->GetField<float>(EventName::MOUSE_X);
        auto y = e->GetField<float>(EventName::MOUSE_Y);
        auto b = (Input::Mouse::Button) e->GetField<uint16_t>(EventName::MOUSE_BUTTON);
        CGEventType type = b == Input::Mouse::Button::Left ? kCGEventLeftMouseUp : kCGEventRightMouseUp;
        CGMouseButton button = b == Input::Mouse::Button::Left ? kCGMouseButtonLeft : kCGMouseButtonRight;
        CGPoint location;
        location.x = x;
        location.y = y;
        PostMouseEvent(button, type, location);
    }
    
}