/*
 * Bitmap.hpp
 *
 *  Created on: 26 Φεβ 2014
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

#ifndef BITMAP_HPP_
#define BITMAP_HPP_

#include <stddef.h>

#include <Zeta/Core/Drawable.hpp>
#include <Zeta/Core/ZetaConfig.hpp>
#include <Zeta/Core/ResourceClasses/Resource.hpp>

namespace Zeta {

class Bitmap: public Drawable, public Resource {
public:

	enum FlipFlag {
		Normal, Fliped_Horizontaly, Fliped_Verticaly, Fliped_Both
	};

	int getWidth() const {
		return width;
	}

	int getHeight() const {
		return height;
	}

	virtual void draw(Float x, Float y, Float rotation, Float scale,
			FlipFlag flip = Normal) const =0;
	virtual void drawAtCentre(Float x, Float y, Float rotation, Float scale,
			FlipFlag flip = Normal) const =0;

	virtual Bitmap& createSubBitmap(int x, int y, int width,
			int height) const=0;

	virtual void eraseSubBitmap(Bitmap& bitmap) const =0;

	virtual void reserveSubBitmaps(size_t number) const=0;

	Bitmap(Bitmap&&) = default;
	Bitmap& operator=(Bitmap&&) = default;

	Bitmap(const std::string& path) :
			Resource(path), width(64), height(64) {

	}

	Bitmap(int width, int height) :
			Resource("null Bitmap"), width(width), height(height) {

	}
	virtual ~Bitmap() {

	}
protected:
	int width;
	int height;
};

} /* namespace Zeta */

#endif /* BITMAP_HPP_ */
