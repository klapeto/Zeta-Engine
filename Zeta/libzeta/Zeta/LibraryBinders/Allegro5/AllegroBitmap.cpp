/*
 * AllegroBitmap.cpp
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

#include <allegro5/allegro.h>
#include <allegro5/bitmap.h>
#if ALLEGRO_WIP_VERSION > 3
#include <allegro5/bitmap_draw.h>
#endif
#include <allegro5/bitmap_io.h>
#include <Zeta/Core/UtilityClasses/Exception.hpp>
#include <Zeta/LibraryBinders/Allegro5/AllegroBitmap.hpp>
#include <stddef.h>
#include <iterator>

namespace Zeta {

AllegroBitmap::AllegroBitmap() :
		Bitmap(64, 64), h_width(32), h_height(32) {
	bitmap = al_create_bitmap(64, 64);
}

AllegroBitmap::AllegroBitmap(int width, int height) :
		Bitmap(width, height), h_width(width >> 1), h_height(height >> 1) {
	bitmap = al_create_bitmap(width, height);
}

AllegroBitmap::AllegroBitmap(const std::string& path) :
		Bitmap(path) {
	bitmap = al_load_bitmap(path.c_str());
	if (bitmap == nullptr) {
		throw Exception(path, "Failed Loading Bitmap (Allegro 5)");
	}
	width = al_get_bitmap_width(bitmap);
	height = al_get_bitmap_height(bitmap);
	h_width = width >> 1;
	h_height = height >> 1;
}

AllegroBitmap::~AllegroBitmap() {
	for (auto subBitmap : subBitmaps) {
		delete subBitmap;
	}
	al_destroy_bitmap(bitmap);
}

AllegroBitmap::AllegroBitmap(const AllegroBitmap& parent, int x, int y,
		int width, int height) :
		Bitmap(width, height), h_width(width >> 1), h_height(height >> 1) {
	bitmap = al_create_sub_bitmap(parent.bitmap, x, y, width, height);

}

void AllegroBitmap::draw(Float x, Float y, Float rotation, Float scale) const {
	al_draw_scaled_rotated_bitmap(bitmap, 0, 0, x, y, scale, scale,
			rotation * 0.0174532925, 0);
}

void AllegroBitmap::draw(Float x, Float y, Float rotation, Float scale,
		FlipFlag flip) const {
	al_draw_scaled_rotated_bitmap(bitmap, 0, 0, x, y, scale, scale,
			rotation * 0.0174532925, static_cast<int>(flip));
}

Bitmap& AllegroBitmap::createSubBitmap(int x, int y, int width,
		int height) const {
	auto pair = subBitmaps.insert(
			new AllegroBitmap(*this, x, y, width, height));
	return **pair.first;
}

void AllegroBitmap::reserveSubBitmaps(size_t number) const {
	subBitmaps.reserve(number);
}

void AllegroBitmap::eraseSubBitmap(Bitmap& bitmap) const {
	auto itr = subBitmaps.find(static_cast<AllegroBitmap*>(&bitmap));
	if (itr != subBitmaps.end()) {
		delete *itr;
		subBitmaps.erase(itr);
	}
}

void Zeta::AllegroBitmap::drawAtCentre(Float x, Float y, Float rotation,
		Float scale, FlipFlag flip) const {
	al_draw_scaled_rotated_bitmap(bitmap, h_width, h_height, x, y, scale, scale,
			rotation * 0.0174532925, 0);
}

} /* namespace Zeta */
