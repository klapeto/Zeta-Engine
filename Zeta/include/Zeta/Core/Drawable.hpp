/*
 * Drawable.hpp
 *
 *  Created on: 2 Ιαν 2014
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

#ifndef DRAWABLE_HPP_
#define DRAWABLE_HPP_

#include <Zeta/Core/ZetaConfig.hpp>

namespace Zeta {

/**
 * Abstract Class that ensures that derived classes can be drawn on Screen
 */
class Drawable {
public:

	/**
	 * Draws the Object on screen.
	 * Be advised, the x,y, offsets might have different meaning on different implementations.
	 * @param x X offset to be applied on the drawing
	 * @param y Y offset to be applied on the drawing
	 * @param rotation the rotation to be applied on the drawing
	 */
	virtual void draw(Float x, Float y, Float rotation = 0.0f, Float scale =
			1.0f) const=0;

	Drawable() {

	}
	virtual ~Drawable() {

	}
};

} /* namespace Zeta */

#endif /* DRAWABLE_HPP_ */
