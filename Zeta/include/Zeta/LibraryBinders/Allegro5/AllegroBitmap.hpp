/*
 * AllegroBitmap.hpp
 *
 *  Created on: 1 Σεπ 2014
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

#ifndef ALLEGROBITMAP_HPP_
#define ALLEGROBITMAP_HPP_

#include <Zeta/Core/ResourceClasses/Bitmap.hpp>
#include <Zeta/Core/ZetaConfig.hpp>
#include <string>
#include <Zeta/Core/ZSet.hpp>

struct ALLEGRO_BITMAP;

namespace Zeta {

class AllegroBitmap: public Bitmap {
public:

	void draw(Float x, Float y, Float rotation = 0.0f,
			Float scale = 1.0f) const;
	void draw(Float x, Float y, Float rotation, Float scale,
			FlipFlag flip) const;
	void drawAtCentre(Float x, Float y, Float rotation, Float scale,
			FlipFlag flip = Normal) const;

	Bitmap& createSubBitmap(int x, int y, int width, int height) const;
	void eraseSubBitmap(Bitmap& bitmap) const;

	void reserveSubBitmaps(size_t number) const;

	AllegroBitmap(AllegroBitmap&&) = default;
	AllegroBitmap& operator=(AllegroBitmap&&) = default;

	AllegroBitmap();
	AllegroBitmap(int width, int height);
	AllegroBitmap(const std::string& path);
	~AllegroBitmap();
private:
	AllegroBitmap(const AllegroBitmap& parent, int x, int y, int width,
			int height);
	mutable ZSet<AllegroBitmap*> subBitmaps;
	mutable ALLEGRO_BITMAP *bitmap;
	int h_width;
	int h_height;
};

} /* namespace Zeta */

#endif /* ALLEGROBITMAP_HPP_ */
