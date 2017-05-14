/*
 * EftihiaConfig.hpp
 *
 *  Created on: 16 Δεκ 2013
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

#ifndef ZETACONFIG_HPP_
#define ZETACONFIG_HPP_

#define ZETA_USE_VECTOR_2D_TABLES

#define strTo10(str) strtol(str, nullptr, 0)
#define strToHex(str) strtol(str, nullptr, 16)

struct lua_State;
typedef int lua_Object;
typedef int (*lua_CFunction) (lua_State *L);

namespace Zeta {

typedef float Float;
typedef float AttributeValue;

enum class EventType {
	Window_Close,
	Window_Resize,
	Window_Lost_Focus,
	Window_Got_Focus,
	Mouse_Button_Down,
	Mouse_Button_Up,
	Mouse_Move,
	Keyboard_Key_Down,
	Keyboard_Key_Up,
	Keyboard_Char_Pressed,
	Ignore
};

/*
 * These key Codes are directly taken from CEGUI::Key:Scan
 * to provide static compability with CEGUI.
 */
enum class KeyboardKey {
	Unknown = 0x00,
	Escape = 0x01,
	One = 0x02,
	Two = 0x03,
	Three = 0x04,
	Four = 0x05,
	Five = 0x06,
	Six = 0x07,
	Seven = 0x08,
	Eight = 0x09,
	Nine = 0x0A,
	Zero = 0x0B,
	Minus = 0x0C,
	Equals = 0x0D,
	Backspace = 0x0E,
	Tab = 0x0F,
	Q = 0x10,
	W = 0x11,
	E = 0x12,
	R = 0x13,
	T = 0x14,
	Y = 0x15,
	U = 0x16,
	I = 0x17,
	O = 0x18,
	P = 0x19,
	LeftBracket = 0x1A,
	RightBracket = 0x1B,
	Return = 0x1C,
	LeftControl = 0x1D,
	A = 0x1E,
	S = 0x1F,
	D = 0x20,
	F = 0x21,
	G = 0x22,
	H = 0x23,
	J = 0x24,
	K = 0x25,
	L = 0x26,
	Semicolon = 0x27,
	Apostrophe = 0x28,
	Grave = 0x29,
	LeftShift = 0x2A,
	Backslash = 0x2B,
	Z = 0x2C,
	X = 0x2D,
	C = 0x2E,
	V = 0x2F,
	B = 0x30,
	N = 0x31,
	M = 0x32,
	Comma = 0x33,
	Period = 0x34,
	Slash = 0x35,
	RightShift = 0x36,
	Multiply = 0x37,
	LeftAlt = 0x38,
	Space = 0x39,
	Capital = 0x3A,
	F1 = 0x3B,
	F2 = 0x3C,
	F3 = 0x3D,
	F4 = 0x3E,
	F5 = 0x3F,
	F6 = 0x40,
	F7 = 0x41,
	F8 = 0x42,
	F9 = 0x43,
	F10 = 0x44,
	NumLock = 0x45,
	ScrollLock = 0x46,
	Numpad7 = 0x47,
	Numpad8 = 0x48,
	Numpad9 = 0x49,
	Subtract = 0x4A,
	Numpad4 = 0x4B,
	Numpad5 = 0x4C,
	Numpad6 = 0x4D,
	Add = 0x4E,
	Numpad1 = 0x4F,
	Numpad2 = 0x50,
	Numpad3 = 0x51,
	Numpad0 = 0x52,
	Decimal = 0x53,
	OEM_102 = 0x56,
	F11 = 0x57,
	F12 = 0x58,
	F13 = 0x64,
	F14 = 0x65,
	F15 = 0x66,
	Kana = 0x70,
	ABNT_C1 = 0x73,
	Convert = 0x79,
	NoConvert = 0x7B,
	Yen = 0x7D,
	ABNT_C2 = 0x7E,
	NumpadEquals = 0x8D,
	PrevTrack = 0x90,
	At = 0x91,
	Colon = 0x92,
	Underline = 0x93,
	Kanji = 0x94,
	Stop = 0x95,
	AX = 0x96,
	Unlabeled = 0x97,
	NextTrack = 0x99,
	NumpadEnter = 0x9C,
	RightControl = 0x9D,
	Mute = 0xA0,
	Calculator = 0xA1,
	PlayPause = 0xA2,
	MediaStop = 0xA4,
	VolumeDown = 0xAE,
	VolumeUp = 0xB0,
	WebHome = 0xB2,
	NumpadComma = 0xB3,
	Divide = 0xB5,
	SysRq = 0xB7,
	RightAlt = 0xB8,
	Pause = 0xC5,
	Home = 0xC7,
	ArrowUp = 0xC8,
	PageUp = 0xC9,
	ArrowLeft = 0xCB,
	ArrowRight = 0xCD,
	End = 0xCF,
	ArrowDown = 0xD0,
	PageDown = 0xD1,
	Insert = 0xD2,
	Delete = 0xD3,
	LeftWindows = 0xDB,
	RightWindows = 0xDC,
	AppMenu = 0xDD,
	Power = 0xDE,
	Sleep = 0xDF,
	Wake = 0xE3,
	WebSearch = 0xE5,
	WebFavorites = 0xE6,
	WebRefresh = 0xE7,
	WebStop = 0xE8,
	WebForward = 0xE9,
	WebBack = 0xEA,
	MyComputer = 0xEB,
	Mail = 0xEC,
	MediaSelect = 0xED

};

enum class KeyModifiers {
	Shift = 0x00001,
	Ctrl = 0x00002,
	Alt = 0x00004,
	Lwin = 0x00008,
	Rwin = 0x00010,
	Menu = 0x00020,
	Alt_Gr = 0x00040,
	Command = 0x00080,
	Scroll_Lock = 0x00100,
	Num_Lock = 0x00200,
	Caps_Lock = 0x00400,
	In_Alt_Seq = 0x00800,
	Accent1 = 0x01000,
	Accent2 = 0x02000,
	Accent3 = 0x04000,
	Accent4 = 0x08000
};

enum class MouseButton {
	LeftButton, RightButton, MiddleButton, X1Button, X2Button
};

enum class WindowFlag {
	Normal, No_Frame, Full_Screen, Full_Screen_Windowed
};

}  // namespace Zeta

#endif /* ZETACONFIG_HPP_ */
