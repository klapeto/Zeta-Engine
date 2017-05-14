/*
 * Visitor.hpp
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

#ifndef VISITOR_HPP_
#define VISITOR_HPP_

namespace Zeta {

class InteractField;
class Lifeform;
class Player;
class ChildObject;
class Projectile;
class ActiveAbility;
class PassiveAbility;
class DirectionalProjectile;
class Quest;
class StaticObject;
class InteractObject;
class CEGUIObject;

class Visitor {
public:
	virtual void handle(Projectile& obj) {
	}
	virtual void handle(DirectionalProjectile& obj) {
	}
	virtual void handle(InteractField& obj) {
	}
	virtual void handle(Lifeform& obj) {
	}
	virtual void handle(Player& obj) {
	}
	virtual void handle(ChildObject& obj) {
	}
	virtual void handle(ActiveAbility& ability) {
	}
	virtual void handle(PassiveAbility& ability) {
	}
	virtual void handle(Quest& quest) {
	}
	virtual void handle(StaticObject& quest) {
	}
	virtual void handle(InteractObject& obj) {
	}
	virtual void handle(CEGUIObject& obj) {
	}

	Visitor() {

	}
	virtual ~Visitor() {

	}
};

} /* namespace Zeta */

#endif /* VISITOR_HPP_ */
