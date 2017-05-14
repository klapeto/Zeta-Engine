/*
 * InteractObject.hpp
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

#ifndef INTERACTOBJECT_HPP_
#define INTERACTOBJECT_HPP_

#include <Zeta/Core/AnimationClasses/AnimationHandler.hpp>
#include <Zeta/Core/LuaFunctor.hpp>
#include <Zeta/Core/RPGClasses/Object.hpp>
#include <Zeta/Core/ZetaConfig.hpp>
#include <string>

namespace Zeta {

class InteractObject: public Object {
public:
	void draw(Float x, Float y, Float rotation = 0.0f, Float scale =
			1.0f) const;
	void update(Float elapsedTime) {
	}
	void onCollidedWith(Object *other);
	void onClick(Object *other);
	void setOnClick(lua_Object func);
	void setOnCollide(lua_Object func);
	void setAnimation(const std::string& name);
	void accept(Visitor& visitor);
	void pushToLua(lua_State *lstate);
	InteractObject(const std::string& animationClass, Float x, Float y);
	~InteractObject();
private:
	AnimationHandler animHandler;
	LuaFunctor onClickF;
	LuaFunctor onCollideF;
};

} /* namespace Zeta */

#endif /* INTERACTOBJECT_HPP_ */
