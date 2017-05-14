/*
 * View.hpp
 *
 *  Created on: 7 Ιαν 2014
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

#ifndef VIEW_HPP_
#define VIEW_HPP_

#include <Zeta/Core/RPGClasses/Object.hpp>
#include <Zeta/Core/UtilityClasses/Rectangle.hpp>
#include <Zeta/Core/UtilityClasses/Shape.hpp>
#include <Zeta/Core/ZetaConfig.hpp>

namespace Zeta {

/**
 * Class for handling Views (Cameras)
 */
class View: public LuaPushable {
public:

	/**
	 * Sets the position of the View
	 * \note The offsets are calculated too
	 * @param x The position on the x axis
	 * @param y The position on the y axis
	 */
	void setPosition(Float x, Float y) {
		viewRect.setPosition(x, y);
		dx = x - viewRect.getX();
		dy = y - viewRect.getY();
	}

	/**
	 * Gets the position of the View
	 * @return The position
	 */
	Vector2& getPosition() {
		return viewRect.getPosition();
	}

	/**
	 * Offsets the position of the View
	 * The offsets are assigned too
	 * @param dx The offset to apply on the x axis
	 * @param dy The offset to apply on the y axis
	 */
	void offsetPosition(Float dx, Float dy) {
		viewRect.offsetPosition(dx, dy);
		this->dx = dx;
		this->dy = dy;
	}

	/**
	 * Resizes the View
	 * @param width The new width
	 * @param height The new height
	 */
	void resize(int width, int height) {
		viewRect.setSize(width, height);
	}

	/**
	 * Gets the x of the position of the view
	 * @return The x coordinate
	 */
	inline Float getX() const {
		return viewRect.getX();
	}

	/**
	 * Gets the y of the position of the view
	 * @return The y coordinate
	 */
	inline Float getY() const {
		return viewRect.getY();
	}

	/**
	 * Gets the Width of the View
	 * return The width
	 */
	inline int getWidth() const {
		return viewRect.getWidth();
	}

	/**
	 * Gets the Height of the View
	 * return The height
	 */
	inline int getHeight() const {
		return viewRect.getHeight();
	}

	/**
	 * Gets the last X offset happened on the View
	 * @return The offset happened on the X axis
	 */
	inline Float getDX() const {
		return dx;
	}

	/**
	 * Gets the last Y offset happened on the View
	 * @return The offset happened on the Y axis
	 */
	inline Float getDY() const {
		return dy;
	}

	/**
	 * Checks if the object overlaps with the View
	 * @param obj The object to check
	 * @return true if the object overlaps with the view
	 */
	inline bool isInView(const Object& obj) const {
		return viewRect.overlapsRectangle(obj.getTargetArea());
	}

	/**
	 * Resets the stored Last Offsets happened on the View
	 */
	void resetOffests() {
		dx = 0.0f;
		dy = 0.0f;
	}

	void pushToLua(lua_State* lstate);

	View();
	~View();
protected:
	Rectangle viewRect;
	Float dx;
	Float dy;
};

} /* namespace Zeta */

#endif /* VIEW_HPP_ */
