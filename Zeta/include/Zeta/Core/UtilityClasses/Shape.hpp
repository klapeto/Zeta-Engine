/*
 * Shape.hpp
 *
 *  Created on: 8 Μαϊ 2014
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

#ifndef SHAPE_HPP_
#define SHAPE_HPP_

#include <Zeta/Core/Color.hpp>
#include <Zeta/Core/Drawable.hpp>
#include <Zeta/Core/UtilityClasses/Vector2.hpp>
#include <Zeta/Core/ZetaConfig.hpp>

namespace Zeta {

class Shape: public Drawable {
public:

	inline Float getX() const {
		return position.getX();
	}

	inline Float getY() const {
		return position.getY();
	}

	inline void setPosition(Float x, Float y) {
		position.set(x, y);
	}

	inline void setPosition(const Vector2& pos) {
		position = pos;
	}

	inline Vector2& getPosition() {
		return position;
	}

	inline const Vector2& getPosition() const {
		return position;
	}

	inline void offsetPosition(Float dx, Float dy) {
		position.offset(dx, dy);
	}

	bool isBackgroundEnabled() const {
		return backgroundEnabled;
	}

	void setBackgroundEnabled(bool backgroundEnabled) {
		this->backgroundEnabled = backgroundEnabled;
	}

	bool isOutlineEnabled() const {
		return outlineEnabled;
	}

	void setOutlineEnabled(bool outlineEnabled) {
		this->outlineEnabled = outlineEnabled;
	}

	const Color& getOutlineColor() const {
		return outlineColor;
	}

	void setOutlineColor(const Color& outlineColor) {
		this->outlineColor = outlineColor;
	}

	const Color& getBackgroundColor() const {
		return backgroundColor;
	}

	void setBackgroundColor(const Color& backgroundColor) {
		this->backgroundColor = backgroundColor;
	}

	Float getOutlineThickness() const {
		return outlineThickness;
	}

	void setOutlineThickness(Float outlineThickness) {
		this->outlineThickness = outlineThickness;
	}

	Shape() :
			outlineThickness(1.0f), outlineEnabled(true), backgroundEnabled(
					false) {

	}

	Shape(Float x, Float y) :
			position(x, y), outlineThickness(1.0f), outlineEnabled(true), backgroundEnabled(
					false) {

	}

	Shape(const Vector2& position) :
			position(position), outlineThickness(1.0f), outlineEnabled(true), backgroundEnabled(
					false) {

	}
	virtual ~Shape() {

	}

protected:
	Vector2 position;
	Color outlineColor;
	Color backgroundColor;
	Float outlineThickness;
	bool outlineEnabled;
	bool backgroundEnabled;
};

} /* namespace Zeta */

#endif /* SHAPE_HPP_ */
