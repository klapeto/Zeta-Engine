/*
 * Color.hpp
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

#ifndef COLOR_HPP_
#define COLOR_HPP_

namespace Zeta {

/**
 * Color helper Class to be used
 * inside the Core.
 */
class Color {
public:

	/**
	 * Helper pre-Defined colors
	 */
	static const Color Transperancy;
	static const Color White;
	static const Color Black;
	static const Color Red;
	static const Color Green;
	static const Color Blue;
	static const Color Yellow;
	static const Color Cyan;
	static const Color Magenta;

	/**
	 * The color channels
	 */
	unsigned char a, b, g, r;

	/**
	 * Assigns the color represented by the integer
	 * E.g Color c = 0xED12CAFF;
	 * Will set R=ED, G=12, B=CA, Alpha=FF
	 * @param RGBA the number to be assigned
	 */
	Color& operator=(unsigned int RGBA) {
		a = RGBA;
		b = RGBA >> 8;
		g = RGBA >> 16;
		r = RGBA >> 24;
		return *this;
	}

	/**
	 * Constructs a default color
	 * The color is 0xFFFFFFFF (White)
	 */
	constexpr Color() :
			a(255), b(255), g(255), r(255) {

	}

	/**
	 * Constructs a Color
	 * @param r Red number
	 * @param g Green Number
	 * @param b Blue Number
	 * @param a Alpha Number
	 */
	constexpr Color(unsigned char r, unsigned char g, unsigned char b,
			unsigned char a) :
			a(a), b(b), g(g), r(r) {
	}

	/**
	 * Constructs the color represented by the integer
	 * E.g Color c(0xED12CAFF);
	 * Will set R=ED, G=12, B=CA, Alpha=FF
	 * @param RGBA the number to be assigned
	 */
	constexpr Color(unsigned int RGBA) :
			a(RGBA), b(RGBA >> 8), g(RGBA >> 16), r(RGBA >> 24) {
	}

	/**
	 * Copy assignment operator
	 */
	Color& operator=(const Color& other) = default;

	/**
	 * Move assignment operator
	 */
	Color& operator=(Color&& other) = default;

	/**
	 * Copy Constructor
	 */
	Color(const Color& other) = default;

	/**
	 * Move Constructor
	 */
	Color(Color&& other) = default;

	~Color() {

	}
};

} /* namespace Zeta */

#endif /* COLOR_HPP_ */
