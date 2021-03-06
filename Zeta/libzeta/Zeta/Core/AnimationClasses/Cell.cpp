/*
 * Cell.cpp
 *
 *  Created on: 8 Ιαν 2014
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

#include <Zeta/Core/AnimationClasses/Cell.hpp>
#include <Zeta/Core/ResourceClasses/SpriteSheet.hpp>
#include <algorithm>
#include <cstdlib>

namespace Zeta {

void Cell::draw(Float x, Float y, Float rotation, Float scale) const {
	// Draw all the sprites this Cell has
	for (auto &spr : sprites) {
		spr.draw(x, y, rotation, scale);
	}
}

void Cell::addSprite(const Sprite& spr) {
	// We have to see where it will be inserted
	auto itr = sprites.begin();
	// for all sprites we already have added
	for (; itr != sprites.end(); ++itr) {
		// check if the Z value is greater that ours
		if ((*itr).getZ() > spr.getZ()) {
			// if it is, then we have to put it there
			break;
		}
	}
	// insert the sprite on the iterator we found
	sprites.insert(itr, spr);
}

} /* namespace Zeta */
