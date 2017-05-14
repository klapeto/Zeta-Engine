/*
 * InteractField.cpp
 *
 *  Created on: 14 Ιουλ 2014
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

#include <Zeta/Core/ConsoleFunctions.hpp>
#include <Zeta/Core/MapClasses/InteractField.hpp>
#include <Zeta/Core/SingleInstanced.hpp>
#include <Zeta/Core/UtilityClasses/Rectangle.hpp>
#include <Zeta/Core/RPGClasses/Player.hpp>
#include <tolua++.h>
#include <Zeta/Core/RPGClasses/WorldEvent.hpp>
#include <iostream>
#include <string>

namespace Zeta {

InteractField::InteractField(Float x, Float y, int width, int height) :
		Object(x, y, width, height), previousInvoker(nullptr) {
	collideAble = false;
	triggersCollisionEvents = true;
}

void InteractField::pushToLua(lua_State* lstate) {
	tolua_pushusertype(lstate, this, "Zeta::InteractField");
}

InteractField::~InteractField() {

}

void InteractField::onCollidedWith(Object* other) {
	OnCollisionHandler plyr(this);
	other->accept(plyr);
}

void InteractField::onClick(Object* other) {
	OnClickHandler plyr(this);
	other->accept(plyr);
}

void InteractField::draw(Float x, Float y, Float rotation, Float scale) const {
	if (collideAble) {
		if (ConsoleFunctions::getInstance().isBoundsShown()) {
			bounding.draw(x, y, rotation, scale);
		}
	}
}

void InteractField::setOnCollision(int luaReference) {
	onCollisionF.setLuaReference(luaReference);
}

void InteractField::setOnClick(int luaReference) {
	onClickF.setLuaReference(luaReference);
}

void InteractField::accept(Visitor& visitor) {
	visitor.handle(*this);
}

void InteractField::OnClickHandler::handle(Player& obj) {
	this->obj->onClickF( { &obj, this->obj });
}

void InteractField::OnCollisionHandler::handle(Lifeform& obj) {
	std::cout << obj.getName() << " Collided!\n";
	WorldEvent event;
	event.setAsCollisionEvent(&obj, this->obj);
	event.broadcast();
}

void InteractField::OnCollisionHandler::handle(Player& obj) {
	this->obj->onCollisionF( { &obj });
	WorldEvent event;
	event.setAsCollisionEvent(&obj, this->obj);
	event.broadcast();
}

} /* namespace Zeta */
