/*
 * PassiveAbility.cpp
 *
 *  Created on: 10 Απρ 2014
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

#include <Zeta/Core/RPGClasses/AbilityClass.hpp>
#include <Zeta/Core/RPGClasses/PassiveAbility.hpp>
#include <Zeta/Core/UtilityClasses/Visitor.hpp>
#include <tolua++.h>

namespace Zeta {

Ability::Result PassiveAbility::invoke() {
	abilityClass.onApply(this, owner, nullptr);
	return Result::Success;
	return Result::InvalidAbility;
}

PassiveAbility::PassiveAbility(const PassiveAbilityClass& abilityClass,
		Lifeform* owner, int level) :
		ClassifiedAbility(abilityClass, owner, level) {
}

void PassiveAbility::accept(Visitor& visitor) {
	visitor.handle(*this);
}

void PassiveAbility::pushToLua(lua_State* lstate) {
	tolua_pushusertype(lstate, this, "Zeta::PassiveAbility");
}

PassiveAbility::~PassiveAbility() {
	abilityClass.onRemove(this, owner, nullptr);

}

} /* namespace Zeta */
