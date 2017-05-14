/*
 * Ellipsis.hpp
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

#ifndef ELLIPSIS_HPP_
#define ELLIPSIS_HPP_

#include <Zeta/Core/UtilityClasses/Shape.hpp>
#include <Zeta/Core/ZetaConfig.hpp>

namespace Zeta {

class Ellipsis: public Shape {
public:

	Float getRadiusX() const {
		return radiusX;
	}

	void setRadiusX(Float radiusX) {
		this->radiusX = radiusX;
	}

	Float getRadiusY() const {
		return radiusY;
	}

	void setRadiusY(Float radiusY) {
		this->radiusY = radiusY;
	}

	void draw(Float x, Float y, Float rotation = 0.0f,
			Float scale = 1.0f) const;

	Ellipsis() :
			radiusX(1), radiusY(1) {

	}
	Ellipsis(Float x, Float y) :
			Shape(x, y), radiusX(1), radiusY(1) {

	}
	Ellipsis(Float x, Float y, Float radiusX, Float radiusY) :
			Shape(x, y), radiusX(radiusX), radiusY(radiusY) {

	}
	~Ellipsis() {

	}
protected:
	Float radiusX;
	Float radiusY;
};

} /* namespace Zeta */

#endif /* ELLIPSIS_HPP_ */
