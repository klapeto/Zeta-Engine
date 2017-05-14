/*
 * Rectangle.hpp
 *
 *  Created on: 23 Δεκ 2013
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

#ifndef RECTANGLE_HPP_
#define RECTANGLE_HPP_

#include <Zeta/Core/UtilityClasses/Shape.hpp>
#include <Zeta/Core/UtilityClasses/Vector2.hpp>
#include <Zeta/Core/ZetaConfig.hpp>

namespace Zeta {

class Rectangle: public Shape, public LuaPushable {
public:

	enum class Surface {
		Top, Left, Right, Bottom, Every
	};

	inline Float getWidth() const {
		return width;
	}

	inline Float getHeight() const {
		return height;
	}

	void setHeight(Float height) {
		this->height = height;
	}

	void setWidth(Float width) {
		this->width = width;
	}

	void setSize(Float width, Float height) {
		this->height = height;
		this->width = width;
	}

	// TODO: Optimize
	inline bool overlapsPoint(Float x, Float y) const {
		return (x >= position.x) && (y >= position.y)
				&& ((position.x + width) >= x) && ((position.y + height) >= y);
	}

	inline bool overlapsPoint(const Vector2& point) const {
		return (point.x > position.x) && (point.y > position.y)
				&& ((position.x + width) > point.y)
				&& ((position.y + height) > point.y);
	}

	inline bool overlapsRectangle(const Rectangle& other) const {
		return (other.position.x + other.width) > position.x
				&& other.position.x < (position.x + width)
				&& (other.position.y + other.height) > position.y
				&& other.position.y < (position.y + height);
	}

	inline bool overlapsWholeRectangle(const Rectangle& other) const {
		return (position.x < other.position.x)
				&& (position.y < other.position.y)
				&& ((position.x + width) > (other.position.x + other.width))
				&& ((position.y + height) > (other.position.y + other.height));
	}

	Rectangle& operator=(const Rectangle& other) = default;
	Rectangle(const Rectangle& other) = default;
	Rectangle(Rectangle&& other) = default;

	virtual void draw(Float x, Float y, Float rotation = 0.0f, Float scale =
			1.0f) const;

	void pushToLua(lua_State* lstate);

	Rectangle() :
			width(0), height(0) {

	}

	Rectangle(const Vector2& location, Float width, Float height) :
			Shape(location), width(width), height(height) {

	}

	Rectangle(Float x, Float y, Float width, Float height) :
			Shape(x, y), width(width), height(height) {

	}
	~Rectangle() {

	}

protected:
	Float width;
	Float height;

};

} /* namespace Zeta */

#endif /* RECTANGLE_HPP_ */
