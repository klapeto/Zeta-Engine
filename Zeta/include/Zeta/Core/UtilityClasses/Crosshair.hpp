/*
 * Crosshair.hpp
 *
 *  Created on: 5 Αυγ 2015
 *      Author: spiti
 */

#ifndef CROSSHAIR_HPP_
#define CROSSHAIR_HPP_

#include <Zeta/Core/UtilityClasses/Shape.hpp>

namespace Zeta {

class Crosshair: public Shape {
public:

	void offsetCrosshair(Float dx, Float dy) {
		cross_x += dx;
		cross_y += dy;
	}
	void resetCrosshair() {
		cross_x = position.getX() + (width >> 1);
		cross_y = position.getY() + (height >> 1);
	}

	int getHeight() const {
		return height;
	}

	void setHeight(int height) {
		this->height = height;
	}

	Float getCrossY() const {
		return cross_y;
	}

	void setCrossY(Float crossY) {
		cross_y = crossY;
	}

	Float getCrossX() const {
		return cross_x;
	}

	void setCrossX(Float crossX) {
		cross_x = crossX;
	}

	int getWidth() const {
		return width;
	}

	void setWidth(int width) {
		this->width = width;
	}

	virtual void draw(Float x, Float y, Float rotation = 0.0f, Float scale =
			1.0f) const;

	Crosshair() :
			Shape(0.0f, 0.0f), cross_x(5.0f), cross_y(5.0f), width(10), height(
					10) {
	}
	Crosshair(Float x, Float y, int width, int height) :
			Shape(x, y), cross_x(x + (width >> 1)), cross_y(y + (height >> 1)), width(
					width), height(height) {

	}
	~Crosshair() {

	}
protected:
	Float cross_x;
	Float cross_y;
	int width;
	int height;
};

} /* namespace Zeta */

#endif /* CROSSHAIR_HPP_ */
