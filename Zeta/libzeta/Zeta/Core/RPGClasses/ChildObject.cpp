/*
 * ChildObject.cpp
 *
 *  Created on: 2 Ιουν 2014
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

#include <Zeta/Core/RPGClasses/ChildObject.hpp>
#include <Zeta/Core/UtilityClasses/Vector2.hpp>
#include <Zeta/Core/UtilityClasses/Visitor.hpp>
#include <tolua++.h>

namespace Zeta {

void ChildObject::update(Float elapsedTime) {
	if (visible) {
		animHandler.update(elapsedTime);
	}
}

void ChildObject::draw(Float x, Float y, Float rotation, Float scale) const {
	if (visible) {
		animHandler.draw(position.getX() - x, position.getY() - y, rotation,
				scale);
	}
}

ChildObject::ChildObject(Float x, Float y, Object* parent,
		const std::string& name, const std::string& animationClass,
		const std::string& animName) :
		Object(parent->getPosition().getX() + x,
				parent->getPosition().getY() + y), parent(parent), toBeDeleted(
				true) {
	this->name = name;
	animHandler.setAnimationClass(animationClass);
	animHandler.setAnimation(animName + "/Down");
	visible = false;
}

ChildObject::ChildObject() :
		Object(0, 0), parent(nullptr), toBeDeleted(false) {
	visible = false;
}

void ChildObject::pushToLua(lua_State* lstate) {
	tolua_pushusertype(lstate, this, "Zeta::ChildObject");
}

ChildObject::~ChildObject() {

}

void ChildObject::accept(Visitor& visitor) {
	visitor.handle(*this);
}

} /* namespace Zeta */
