/*
 * Tile.cpp
 *
 *  Created on: 6 Μαρ 2014
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

#include <Zeta/Core/MapClasses/Tile.hpp>
#include <Zeta/Core/ResourceClasses/Bitmap.hpp>
#include <Zeta/Core/ResourceContext.hpp>
#include <Zeta/Core/System.hpp>
#include <Zeta/Core/ZetaConfig.hpp>

namespace Zeta {

Tile::Tile() :
		img(&System::getInstance().getResourcesManager().getNullBitmap()), id(
				0), collision_value(Collision::None), frameIndex(0), frameCounter(0.0f), animated(false) {

}

Tile::Tile(const Bitmap& bmp, unsigned int id) :
		img(&bmp), id(id), collision_value(Collision::None), frameIndex(0), frameCounter(0.0f), animated(false) {

}

void Tile::draw(Float x, Float y, Float rotation, Float scale) const {
	if (!animated) {
		img->draw(x, y, rotation, scale);
	} else {
		frames[frameIndex].tile->img->draw(x, y, rotation, scale);
	}
}

} /* namespace Zeta */

