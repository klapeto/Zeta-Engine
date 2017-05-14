/*
 * Ability.hpp
 *
 *  Created on: 27 Μαρ 2014
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

#ifndef ABILITY_HPP_
#define ABILITY_HPP_

#include <Zeta/Core/LuaPushable.hpp>
#include <Zeta/Core/LuaFunctor.hpp>

namespace Zeta {

class Lifeform;

class Ability: public LuaPushable {
public:

	enum class Result {
		Success,
		onCooldown,
		NoTarget,
		NoMana,
		OutOfRange,
		TargetIsDead,
		TargetIsNotHostile,
		InvalidAbility,
		Other
	};
	int getLevel() const {
		return level;
	}
	void setLevel(int level) {
		this->level = level;
		onLevelChange();
	}
	Lifeform& getOwner() {
		return *owner;
	}
	void setOwner(Lifeform *owner) {
		this->owner = owner;
	}
	Ability(Lifeform *owner, int level) :
			owner(owner), level(level) {

	}
	virtual ~Ability() {
	}
protected:
	Ability() :
			owner(nullptr), level(1) {

	}
	Lifeform *owner;
	int level;

	virtual void onLevelChange()=0;
};

} /* namespace Zeta */

#endif /* ABILITY_HPP_ */
