/*
 * ChildObject.hpp
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

#ifndef CHILDOBJECT_HPP_
#define CHILDOBJECT_HPP_

#include <Zeta/Core/AnimationClasses/AnimationHandler.hpp>
#include <Zeta/Core/RPGClasses/Object.hpp>
#include <Zeta/Core/ZetaConfig.hpp>
#include <string>

namespace Zeta {

class ChildObject: public Object {
public:

	Object* getParent() {
		return parent;
	}

	bool hasParent() const {
		return parent == nullptr;
	}

	void setParent(Object* parent) {
		this->parent = parent;
	}

	virtual void onCollidedWith(Object *other) {

	}
	virtual void onClick(Object *other) {

	}
	AnimationHandler& getAnimationHandler() {
		return animHandler;
	}

	bool isToBeDeleted() const {
		return toBeDeleted;
	}

	void setToBeDeleted(bool toBeDeleted) {
		this->toBeDeleted = toBeDeleted;
	}

	virtual void update(Float elapsedTime);

	virtual void draw(Float x, Float y, Float rotation = 0.0f, Float scale =
			1.0f) const;

	virtual void accept(Visitor& visitor);

	virtual void pushToLua(lua_State* lstate);

	ChildObject();
	ChildObject(Float x, Float y, Object *parent, const std::string& name,
			const std::string& animationClass, const std::string& animName);
	virtual ~ChildObject();
protected:
	AnimationHandler animHandler;
	Object *parent;
	bool toBeDeleted;
};

} /* namespace Zeta */

#endif /* CHILDOBJECT_HPP_ */
