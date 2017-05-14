/*
 * InteractObject.cpp
 *
 *  Created on: 6 Οκτ 2014
 *      Author: klapeto
 */

/*	
 * This file is Part of Zeta
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

#include <Zeta/Core/Logger.hpp>
#include <Zeta/Core/RPGClasses/InteractObject.hpp>
#include <Zeta/Core/LuaEngine.hpp>
#include <Zeta/Core/SingleInstanced.hpp>
#include <Zeta/Core/UtilityClasses/Exception.hpp>
#include <Zeta/Core/UtilityClasses/Vector2.hpp>
#include <Zeta/Core/UtilityClasses/Visitor.hpp>
#include <tolua++.h>

namespace Zeta {

void InteractObject::draw(Float x, Float y, Float rotation, Float scale) const {
	if (visible) {
		animHandler.draw(position.getX() - x, position.getY() - y, rotation,
				scale);
	}
}

void InteractObject::onCollidedWith(Object* other) {
	onCollideF( { this, other });
}

void InteractObject::onClick(Object* other) {
	onClickF( { this, other });
}

void InteractObject::setOnClick(lua_Object func) {
	try {
		onClickF.setFromStack(LuaEngine::getInstance().getState(), func);
	} catch (Exception& ex) {
		Logger::getInstance().write(
				"During getting Lua Functor. Reason: " + ex.reason()
						+ "\n At file: " + std::string(__FILE__)
						+ "\n At function: " + std::string(__FUNCTION__));
	}
}

void InteractObject::setOnCollide(lua_Object func) {
	try {
		onCollideF.setFromStack(LuaEngine::getInstance().getState(), func);
	} catch (Exception& ex) {
		Logger::getInstance().write(
				"During getting Lua Functor. Reason: " + ex.reason()
						+ "\n At file: " + std::string(__FILE__)
						+ "\n At function: " + std::string(__FUNCTION__));
	}
}

void InteractObject::setAnimation(const std::string& name) {
	animHandler.setAnimation(name);
}

void InteractObject::accept(Visitor& visitor) {
	visitor.handle(*this);
}

InteractObject::InteractObject(const std::string& animationClass, Float x,
		Float y) :
		Object(x, y) {
	animHandler.setAnimationClass(animationClass);
}

void InteractObject::pushToLua(lua_State* lstate) {
	tolua_pushusertype(lstate, this, "Zeta::InteractObject");
}

InteractObject::~InteractObject() {

}
} /* namespace Zeta */
