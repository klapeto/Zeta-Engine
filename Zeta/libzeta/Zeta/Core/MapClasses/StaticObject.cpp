/*
 * StaticObject.cpp
 *
 *  Created on: 25 Σεπ 2014
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

#include <Zeta/Core/MapClasses/StaticObject.hpp>
#include <Zeta/Core/MapClasses/Tile.hpp>
#include <Zeta/Core/UtilityClasses/Vector2.hpp>
#include <Zeta/Core/UtilityClasses/Visitor.hpp>
#include <tolua++.h>

namespace Zeta {

void StaticObject::accept(Visitor& visitor) {
	visitor.handle(*this);
}

void StaticObject::draw(Float x, Float y, Float rotation, Float scale) const {
	tile.draw(this->position.getX() - x, this->position.getY() - y - tileHeight,
			rotation, scale);
}

StaticObject::StaticObject(Float x, Float y, const Tile& tile,
		unsigned int tileWidth, unsigned int tileHeight) :
		Object(x, y, tileWidth, tileHeight), tile(tile), tileWidth(tileWidth), tileHeight(
				tileHeight) {
	collideAble = false;
	triggersCollisionEvents = false;

}

void StaticObject::pushToLua(lua_State* lstate) {
	tolua_pushusertype(lstate, this, "Zeta::Object");
}

StaticObject::~StaticObject() {

}

} /* namespace Zeta */
