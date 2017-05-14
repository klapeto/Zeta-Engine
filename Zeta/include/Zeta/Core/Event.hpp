/*
 * Event.hpp
 *
 *  Created on: 17 Δεκ 2013
 *      Author: klapeto
 */

/*	This file is Part of Zeta Engine
 *
 *	The MIT License
 *
 * Copyright (c) 2014 Ioannis G. Panagiotopoulos (AKA Klapeto)
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated
 * documentation files (the "Software"), to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software,
 * and to permit persons to whom the Software is furnished to do so, subject to the following conditions.
 *
 * The above copyright notice and this permission notice shall be included in all copies or substantial
 * portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE
 * AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
 * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 */

#ifndef EVENT_HPP_
#define EVENT_HPP_

#include <Zeta/Core/ZetaConfig.hpp>

namespace Zeta {

/**
 * Event Base class to Wrap Library-Specific
 * Events.
 */
class Event {
public:

	struct DisplayEvent {
		int x, y;
		int width, height;
	};

	struct KeyboardEvent {
		KeyboardKey key;
		int unichar;
		unsigned int modifiers;
	};
	struct MouseEvent {
		int x, y, wheel;
		MouseButton button;
		float pressure;
		int dx, dy;
	};

	EventType type;

	union {
		DisplayEvent display;
		KeyboardEvent keyboard;
		MouseEvent mouse;
	};

	void toNoEvent() {
		type = EventType::Ignore;
	}

	void toDisplayEvent(EventType type, int x, int y, int width, int height) {
		this->type = type;
		display.height = height;
		display.width = width;
		display.x = x;
		display.y = y;
	}

	void toMouseEvent(EventType type, int x, int y, int wheel,
			MouseButton button, float pressure, int dx = 0, int dy = 0) {
		this->type = type;
		mouse.x = x;
		mouse.y = y;
		mouse.wheel = wheel;
		mouse.button = button;
		mouse.pressure = pressure;
		mouse.dx = dx;
		mouse.dy = dy;
	}

	void toKeyboardEvent(EventType type, KeyboardKey key, int unichar,
			unsigned int modifiers) {
		this->type = type;
		keyboard.key = key;
		keyboard.unichar = unichar;
		keyboard.modifiers = modifiers;
	}

	virtual ~Event() {

	}
};

}
/* namespace Zeta */

#endif /* EVENT_HPP_ */
