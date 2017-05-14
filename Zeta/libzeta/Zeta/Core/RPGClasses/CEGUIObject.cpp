/*
 * CEGUIObject.cpp
 *
 *  Created on: 4 Δεκ 2014
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
#include <Zeta/Core/RPGClasses/CEGUIObject.hpp>
#include <Zeta/Core/LuaEngine.hpp>
#include <Zeta/Core/SingleInstanced.hpp>
#include <Zeta/Core/UtilityClasses/Exception.hpp>
#include <Zeta/Core/UtilityClasses/Visitor.hpp>
#include <CEGUI/Element.h>
#include <CEGUI/UDim.h>
#include <CEGUI/Vector.h>
#include <CEGUI/Window.h>
#include <tolua++.h>

namespace Zeta {

void CEGUIObject::draw(Float x, Float y, Float rotation, Float scale) const {
	if (window != nullptr) {
		Vector2 rend = this->getRenderPosition();
		window->setPosition(
				CEGUI::UVector2(CEGUI::UDim(0.0f, rend.getX() + offX),
						CEGUI::UDim(0.0f, rend.getY() + offY)));
	}
	animHandler.draw(x, y, rotation, scale);
}

void CEGUIObject::onHide() {
	if (window != nullptr) {
		window->hide();
	}
}

void CEGUIObject::onShow() {
	if (window != nullptr) {
		window->show();
	}
}

void CEGUIObject::setPosition(Float x, Float y) {
	Object::setPosition(x, y);
	if (window != nullptr) {
		Vector2 rend = this->getRenderPosition();
		window->setPosition(
				CEGUI::UVector2(CEGUI::UDim(0.0f, rend.getX() + offX),
						CEGUI::UDim(0.0f, rend.getY() + offY)));
	}
}

void CEGUIObject::offsetPosition(Float dx, Float dy) {
	Object::offsetPosition(dx, dy);
	if (window != nullptr) {

		window->setPosition(
				CEGUI::UVector2(window->getXPosition() + CEGUI::UDim(0.0f, dx),
						window->getYPosition() + CEGUI::UDim(0.0f, dy)));
	}
}

void CEGUIObject::onCollidedWith(Object* other) {
}

void CEGUIObject::onClick(Object* other) {
	onClickF( { other, this, &table });
}

void CEGUIObject::accept(Visitor& visitor) {
	visitor.handle(*this);
}

CEGUIObject::CEGUIObject(CEGUI::Window* window, Float x, Float y,
		const std::string& animationClass) :
		Object(x, y, 64, 64), window(window), offX(0.0f), offY(0.0f), destroy(
				false) {
	Vector2 rend = this->getRenderPosition();
	window->setPosition(
			CEGUI::UVector2(CEGUI::UDim(0.0f, rend.getX() + offX),
					CEGUI::UDim(0.0f, rend.getY() + offY)));
}

void CEGUIObject::setLuaTable(lua_Object table) {
	try {
		this->table.setFromStack(LuaEngine::getInstance().getState(), table);
	} catch (Exception& ex) {
		Logger::getInstance().write(
				"During assigning a Lua Table to Zeta::CEGUIObject. Reason: "
						+ ex.reason());
	}
}

void CEGUIObject::setOnClick(lua_Object func) {
	try {
		this->onClickF.setFromStack(LuaEngine::getInstance().getState(),func);
	} catch (Exception& ex) {
		Logger::getInstance().write(
				"During assigning a Lua Function (onClick) to Zeta::CEGUIObject. Reason: "
						+ ex.reason());
	}
}

void CEGUIObject::pushToLua(lua_State* lstate) {
	tolua_pushusertype(lstate, this, "Zeta::CEGUIObject");
}

CEGUIObject::~CEGUIObject() {
	if (window != nullptr) {
		if (destroy) {

			window->getParent()->destroyChild(window);
		} else {
			window->hide();
		}
	}

}

} /* namespace Zeta */
