/*
 * Vector2.hpp
 *
 *  Created on: 19 Μαρ 2014
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

#ifndef VECTOR2_HPP_
#define VECTOR2_HPP_

#include <Zeta/Core/LuaPushable.hpp>
#include <Zeta/Core/ZetaConfig.hpp>
#include <cmath>

namespace Zeta {

class Vector2: public LuaPushable {
public:

	inline Float getX() const {
		return x;
	}

	inline void setX(Float x) {
		this->x = x;
	}

	inline Float getY() const {
		return y;
	}

	inline void setY(Float y) {
		this->y = y;
	}

	inline void set(Float x, Float y) {
		this->x = x;
		this->y = y;
	}

	inline void offset(Float dx, Float dy) {
		x += dx;
		y += dy;
	}

	inline void offset(const Vector2 other) {
		x += other.x;
		y += other.y;
	}

	Vector2 operator+(const Vector2& other) const {
		return Vector2(x + other.x, y + other.y);
	}

	Vector2 operator-(const Vector2& other) const {
		return Vector2(x - other.x, y - other.y);
	}

	Vector2 operator*(Float m) const {
		return Vector2(x * m, y * m);
	}

	Vector2& operator*=(Float m) {
		x *= m;
		y *= m;
		return *this;
	}

	Float getLength() const {
		return std::sqrt((x * x) + (y * y));
	}

	Float getDistance(const Vector2& other) const {
		Float dx = x - other.x;
		Float dy = y - other.y;
		return std::sqrt(dx * dx + dy * dy);
	}

	void normalize() {
		Float len = getLength();
		x /= len;
		y /= len;
	}

	void round() {
		x = std::ceil(x + 0.5f);
		y = std::ceil(y + 0.5f);
	}

	void pushToLua(lua_State* lstate);

	Vector2() :
			x(0), y(0) {

	}

	Vector2(Float x, Float y) :
			x(x), y(y) {

	}

	Vector2(const Vector2& other) = default;
	Vector2(Vector2&& other) = default;
	Vector2& operator=(const Vector2& other) = default;

	~Vector2() {

	}

	Float x;
	Float y;

};

} /* namespace Zeta */

#endif /* VECTOR2_HPP_ */
