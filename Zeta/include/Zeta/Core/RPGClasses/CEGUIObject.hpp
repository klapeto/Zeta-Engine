/*
 * CEGUIObject.hpp
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

#ifndef ZETA_CORE_RPGCLASSES_CEGUIOBJECT_HPP_
#define ZETA_CORE_RPGCLASSES_CEGUIOBJECT_HPP_

#include <Zeta/Core/AnimationClasses/AnimationHandler.hpp>
#include <Zeta/Core/LuaFunctor.hpp>
#include <Zeta/Core/LuaTable.hpp>
#include <Zeta/Core/RPGClasses/Object.hpp>
#include <Zeta/Core/ZetaConfig.hpp>
#include <string>

namespace CEGUI {
class Window;
} /* namespace CEGUI */

namespace Zeta {

class CEGUIObject: public Object {
public:
	void setOffesets(Float offX, Float offY) {
		this->offX = offX;
		this->offY = offY;
	}

	bool isDestroy() const {
		return destroy;
	}

	void setDestroy(bool destroy) {
		this->destroy = destroy;
	}

	Float getOffsetX() const {
		return offX;
	}

	void setOffsetX(Float offX) {
		this->offX = offX;
	}

	Float getOffsetY() const {
		return offY;
	}

	void setOffsetY(Float offY) {
		this->offY = offY;
	}

	CEGUI::Window* getWindow() const {
		return window;
	}

	void setWindow(CEGUI::Window* window) {
		this->window = window;
	}

	void update(Float elapsedTime) {
		animHandler.update(elapsedTime);
	}

	void setLuaTable(lua_Object table);
	void setOnClick(lua_Object func);

	AnimationHandler& getAnimationHandler() {
		return animHandler;
	}

	void draw(Float x, Float y, Float rotation = 0.0f,
			Float scale = 1.0f) const;
	void onHide();
	void onShow();
	void setPosition(Float x, Float y);
	void offsetPosition(Float dx, Float dy);
	void onCollidedWith(Object *other);
	void onClick(Object *other);
	void accept(Visitor& visitor);
	void pushToLua(lua_State* lstate);
	CEGUIObject(CEGUI::Window* window, Float x, Float y,
			const std::string& animationClass = "");
	~CEGUIObject();
private:
	AnimationHandler animHandler;
	LuaTable table;
	LuaFunctor onClickF;
	CEGUI::Window *window;
	Float offX;
	Float offY;
	bool destroy;
};

} /* namespace Zeta */

#endif /* ZETA_CORE_RPGCLASSES_CEGUIOBJECT_HPP_ */
