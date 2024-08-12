#pragma once
#include "input_enums.h"
#include "event.h"

namespace mr::RobotImpl
{
   	void KeyPress(EventPtr e);

	void KeyRelease(EventPtr e);

	void MouseMove(EventPtr e);

	void MousePress(EventPtr e);

	void MouseRelease(EventPtr e); 
}