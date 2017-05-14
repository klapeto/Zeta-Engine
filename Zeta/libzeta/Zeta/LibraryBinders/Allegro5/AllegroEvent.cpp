/*
 * AllegroEvent.cpp
 *
 *  Created on: 5 Σεπ 2014
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

#include <allegro5/altime.h>
#include <allegro5/events.h>
#include <allegro5/keycodes.h>
#include <Zeta/Core/ZetaConfig.hpp>
#include <Zeta/LibraryBinders/Allegro5/AllegroEvent.hpp>

namespace Zeta {

static KeyboardKey translateKey(int key) {
	switch (key) {
	case ALLEGRO_KEY_A:
		return KeyboardKey::A;
		break;
	case ALLEGRO_KEY_B:
		return KeyboardKey::B;
		break;
	case ALLEGRO_KEY_C:
		return KeyboardKey::C;
		break;
	case ALLEGRO_KEY_D:
		return KeyboardKey::D;
		break;
	case ALLEGRO_KEY_E:
		return KeyboardKey::E;
		break;
	case ALLEGRO_KEY_F:
		return KeyboardKey::F;
		break;
	case ALLEGRO_KEY_G:
		return KeyboardKey::G;
		break;
	case ALLEGRO_KEY_H:
		return KeyboardKey::H;
		break;
	case ALLEGRO_KEY_I:
		return KeyboardKey::I;
		break;
	case ALLEGRO_KEY_J:
		return KeyboardKey::J;
		break;
	case ALLEGRO_KEY_K:
		return KeyboardKey::K;
		break;
	case ALLEGRO_KEY_L:
		return KeyboardKey::L;
		break;
	case ALLEGRO_KEY_M:
		return KeyboardKey::M;
		break;
	case ALLEGRO_KEY_N:
		return KeyboardKey::N;
		break;
	case ALLEGRO_KEY_O:
		return KeyboardKey::O;
		break;
	case ALLEGRO_KEY_P:
		return KeyboardKey::P;
		break;
	case ALLEGRO_KEY_Q:
		return KeyboardKey::Q;
		break;
	case ALLEGRO_KEY_R:
		return KeyboardKey::R;
		break;
	case ALLEGRO_KEY_S:
		return KeyboardKey::S;
		break;
	case ALLEGRO_KEY_T:
		return KeyboardKey::T;
		break;
	case ALLEGRO_KEY_U:
		return KeyboardKey::U;
		break;
	case ALLEGRO_KEY_V:
		return KeyboardKey::V;
		break;
	case ALLEGRO_KEY_W:
		return KeyboardKey::W;
		break;
	case ALLEGRO_KEY_X:
		return KeyboardKey::X;
		break;
	case ALLEGRO_KEY_Y:
		return KeyboardKey::Y;
		break;
	case ALLEGRO_KEY_Z:
		return KeyboardKey::Z;
		break;
	case ALLEGRO_KEY_0:
		return KeyboardKey::Zero;
		break;
	case ALLEGRO_KEY_1:
		return KeyboardKey::One;
		break;
	case ALLEGRO_KEY_2:
		return KeyboardKey::Two;
		break;
	case ALLEGRO_KEY_3:
		return KeyboardKey::Three;
		break;
	case ALLEGRO_KEY_4:
		return KeyboardKey::Four;
		break;
	case ALLEGRO_KEY_5:
		return KeyboardKey::Five;
		break;
	case ALLEGRO_KEY_6:
		return KeyboardKey::Six;
		break;
	case ALLEGRO_KEY_7:
		return KeyboardKey::Seven;
		break;
	case ALLEGRO_KEY_8:
		return KeyboardKey::Eight;
		break;
	case ALLEGRO_KEY_9:
		return KeyboardKey::Nine;
		break;
	case ALLEGRO_KEY_PAD_0:
		return KeyboardKey::Numpad0;
		break;
	case ALLEGRO_KEY_PAD_1:
		return KeyboardKey::Numpad1;
		break;
	case ALLEGRO_KEY_PAD_2:
		return KeyboardKey::Numpad2;
		break;
	case ALLEGRO_KEY_PAD_3:
		return KeyboardKey::Numpad3;
		break;
	case ALLEGRO_KEY_PAD_4:
		return KeyboardKey::Numpad4;
		break;
	case ALLEGRO_KEY_PAD_5:
		return KeyboardKey::Numpad5;
		break;
	case ALLEGRO_KEY_PAD_6:
		return KeyboardKey::Numpad6;
		break;
	case ALLEGRO_KEY_PAD_7:
		return KeyboardKey::Numpad7;
		break;
	case ALLEGRO_KEY_PAD_8:
		return KeyboardKey::Numpad8;
		break;
	case ALLEGRO_KEY_PAD_9:
		return KeyboardKey::Numpad9;
		break;
	case ALLEGRO_KEY_F1:
		return KeyboardKey::F1;
		break;
	case ALLEGRO_KEY_F2:
		return KeyboardKey::F2;
		break;
	case ALLEGRO_KEY_F3:
		return KeyboardKey::F3;
		break;
	case ALLEGRO_KEY_F4:
		return KeyboardKey::F4;
		break;
	case ALLEGRO_KEY_F5:
		return KeyboardKey::F5;
		break;
	case ALLEGRO_KEY_F6:
		return KeyboardKey::F6;
		break;
	case ALLEGRO_KEY_F7:
		return KeyboardKey::F7;
		break;
	case ALLEGRO_KEY_F8:
		return KeyboardKey::F8;
		break;
	case ALLEGRO_KEY_F9:
		return KeyboardKey::F9;
		break;
	case ALLEGRO_KEY_F10:
		return KeyboardKey::F10;
		break;
	case ALLEGRO_KEY_F11:
		return KeyboardKey::F11;
		break;
	case ALLEGRO_KEY_F12:
		return KeyboardKey::F12;
		break;
	case ALLEGRO_KEY_ESCAPE:
		return KeyboardKey::Escape;
		break;
	case ALLEGRO_KEY_TILDE:
		return KeyboardKey::Unknown;
		break;
	case ALLEGRO_KEY_MINUS:
		return KeyboardKey::Minus;
		break;
	case ALLEGRO_KEY_EQUALS:
		return KeyboardKey::Equals;
		break;
	case ALLEGRO_KEY_BACKSPACE:
		return KeyboardKey::Backspace;
		break;
	case ALLEGRO_KEY_TAB:
		return KeyboardKey::Tab;
		break;
	case ALLEGRO_KEY_OPENBRACE:
		return KeyboardKey::RightBracket;
		break;
	case ALLEGRO_KEY_CLOSEBRACE:
		return KeyboardKey::LeftBracket;
		break;
	case ALLEGRO_KEY_ENTER:
		return KeyboardKey::Return;
		break;
	case ALLEGRO_KEY_SEMICOLON:
		return KeyboardKey::Semicolon;
		break;
	case ALLEGRO_KEY_QUOTE:
		return KeyboardKey::Apostrophe;
		break;
	case ALLEGRO_KEY_BACKSLASH:
		return KeyboardKey::Backslash;
		break;
	case ALLEGRO_KEY_BACKSLASH2:
		return KeyboardKey::Unknown;
		break;
	case ALLEGRO_KEY_COMMA:
		return KeyboardKey::Comma;
		break;
	case ALLEGRO_KEY_FULLSTOP:
		return KeyboardKey::Period;
		break;
	case ALLEGRO_KEY_SLASH:
		return KeyboardKey::Slash;
		break;
	case ALLEGRO_KEY_SPACE:
		return KeyboardKey::Space;
		break;
	case ALLEGRO_KEY_INSERT:
		return KeyboardKey::Insert;
		break;
	case ALLEGRO_KEY_DELETE:
		return KeyboardKey::Delete;
		break;
	case ALLEGRO_KEY_HOME:
		return KeyboardKey::Home;
		break;
	case ALLEGRO_KEY_END:
		return KeyboardKey::End;
		break;
	case ALLEGRO_KEY_PGUP:
		return KeyboardKey::PageUp;
		break;
	case ALLEGRO_KEY_PGDN:
		return KeyboardKey::PageDown;
		break;
	case ALLEGRO_KEY_LEFT:
		return KeyboardKey::ArrowLeft;
		break;
	case ALLEGRO_KEY_RIGHT:
		return KeyboardKey::ArrowRight;
		break;
	case ALLEGRO_KEY_UP:
		return KeyboardKey::ArrowUp;
		break;
	case ALLEGRO_KEY_DOWN:
		return KeyboardKey::ArrowDown;
		break;
	case ALLEGRO_KEY_PAD_SLASH:
		return KeyboardKey::Divide;
		break;
	case ALLEGRO_KEY_PAD_ASTERISK:
		return KeyboardKey::Multiply;
		break;
	case ALLEGRO_KEY_PAD_MINUS:
		return KeyboardKey::Minus;
		break;
	case ALLEGRO_KEY_PAD_PLUS:
		return KeyboardKey::Add;
		break;
	case ALLEGRO_KEY_PAD_DELETE:
		return KeyboardKey::Delete;
		break;
	case ALLEGRO_KEY_PAD_ENTER:
		return KeyboardKey::NumpadEnter;
		break;
	case ALLEGRO_KEY_PRINTSCREEN:
		return KeyboardKey::Unknown;
		break;
	case ALLEGRO_KEY_PAUSE:
		return KeyboardKey::Pause;
		break;
	case ALLEGRO_KEY_ABNT_C1:
		return KeyboardKey::ABNT_C1;
		break;
	case ALLEGRO_KEY_YEN:
		return KeyboardKey::Yen;
		break;
	case ALLEGRO_KEY_KANA:
		return KeyboardKey::Kana;
		break;
	case ALLEGRO_KEY_CONVERT:
		return KeyboardKey::Convert;
		break;
	case ALLEGRO_KEY_NOCONVERT:
		return KeyboardKey::NoConvert;
		break;
	case ALLEGRO_KEY_AT:
		return KeyboardKey::At;
		break;
	case ALLEGRO_KEY_CIRCUMFLEX:
		return KeyboardKey::Unknown;
		break;
	case ALLEGRO_KEY_COLON2:
		return KeyboardKey::Colon;
		break;
	case ALLEGRO_KEY_KANJI:
		return KeyboardKey::Kanji;
		break;
	case ALLEGRO_KEY_PAD_EQUALS:
		return KeyboardKey::NumpadEquals;
		break;
	case ALLEGRO_KEY_BACKQUOTE:
		return KeyboardKey::Unknown;
		break;
	case ALLEGRO_KEY_SEMICOLON2:
		return KeyboardKey::Unknown;
		break;
	case ALLEGRO_KEY_COMMAND:
		return KeyboardKey::Unknown;
		break;
	case ALLEGRO_KEY_UNKNOWN:
		return KeyboardKey::Unknown;
		break;
	default:
		return KeyboardKey::Unknown;
		break;
	}
}

static MouseButton translateMouseButton(unsigned int button) {
	switch (button) {
	case 1:
		return MouseButton::LeftButton;
		break;
	case 2:
		return MouseButton::RightButton;
		break;
	case 3:
		return MouseButton::MiddleButton;
		break;
	default:
		return MouseButton::LeftButton;
		break;
	}

}

AllegroEvent::AllegroEvent(ALLEGRO_EVENT& event) {

	switch (event.type) {
	case ALLEGRO_EVENT_DISPLAY_CLOSE:
		toDisplayEvent(EventType::Window_Close, event.display.x,
				event.display.y, event.display.width, event.display.height);
		break;
	case ALLEGRO_EVENT_DISPLAY_SWITCH_IN:
		toDisplayEvent(EventType::Window_Got_Focus, event.display.x,
				event.display.y, event.display.width, event.display.height);
		break;
	case ALLEGRO_EVENT_DISPLAY_SWITCH_OUT:
		toDisplayEvent(EventType::Window_Lost_Focus, event.display.x,
				event.display.y, event.display.width, event.display.height);
		break;
	case ALLEGRO_EVENT_KEY_CHAR:
		toKeyboardEvent(EventType::Keyboard_Char_Pressed,
				translateKey(event.keyboard.keycode), event.keyboard.unichar,
				event.keyboard.modifiers);
		break;
	case ALLEGRO_EVENT_KEY_DOWN:
		toKeyboardEvent(EventType::Keyboard_Key_Down,
				translateKey(event.keyboard.keycode), event.keyboard.unichar,
				event.keyboard.modifiers);
		break;
	case ALLEGRO_EVENT_KEY_UP:
		toKeyboardEvent(EventType::Keyboard_Key_Up,
				translateKey(event.keyboard.keycode), event.keyboard.unichar,
				event.keyboard.modifiers);
		break;
	case ALLEGRO_EVENT_MOUSE_AXES:
		toMouseEvent(EventType::Mouse_Move, event.mouse.x, event.mouse.y,
				event.mouse.dz, translateMouseButton(event.mouse.button),
				event.mouse.pressure, event.mouse.dx, event.mouse.dy);
		break;
	case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN:
		toMouseEvent(EventType::Mouse_Button_Down, event.mouse.x, event.mouse.y,
				event.mouse.dz, translateMouseButton(event.mouse.button),
				event.mouse.pressure, event.mouse.dx, event.mouse.dy);
		break;
	case ALLEGRO_EVENT_MOUSE_BUTTON_UP:
		toMouseEvent(EventType::Mouse_Button_Up, event.mouse.x, event.mouse.y,
				event.mouse.dz, translateMouseButton(event.mouse.button),
				event.mouse.pressure, event.mouse.dx, event.mouse.dy);
		break;
	default:
		this->type = EventType::Ignore;
		break;
	}
}

} /* namespace Zeta */
