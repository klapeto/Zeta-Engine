/*
 * OverTimeEffect.cpp
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

#include <Zeta/Core/LuaNumber.hpp>
#include <Zeta/Core/RPGClasses/EffectClass.hpp>
#include <Zeta/Core/RPGClasses/OverTimeEffect.hpp>
#include <Zeta/Core/RPGClasses/Lifeform.hpp>
#include <Zeta/Core/RPGClasses/Ability.hpp>
#include <tolua++.h>

namespace Zeta {

void OverTimeEffect::update(Float elapsedTime) {
	switch (state) {
	case EffectState::Running:
		frameCounter -= elapsedTime;
		if (frameCounter > 0) {
			tickCounter -= elapsedTime;
			if (tickCounter <= 0) {

				LuaNumber lvl(level);
				effClass->getOnTick()( { this, owner, &lvl, source });

				tickCounter = tickEvery;
			}
		} else {
			state = EffectState::End;
		}
		break;
	case EffectState::Begin: {
		LuaNumber lvl(level);

		effClass->getOnApply()( { this, owner, &lvl, source });
	}
		state = EffectState::Running;
		break;
	case EffectState::End: {
		LuaNumber lvl(level);
		effClass->getOnRemove()( { this, owner, &lvl, source });
	}
		finished = true;
		break;
	}
}

OverTimeEffect::OverTimeEffect(const EffectClass& effCls, Lifeform *target,
		int level) :
		DurableEffect(effCls, target, level), tickEvery(effCls.getTickEvery()), tickCounter(
				effCls.getTickEvery()) {
}

OverTimeEffect::~OverTimeEffect() {

}

void OverTimeEffect::pushToLua(lua_State* lstate) {
	tolua_pushusertype(lstate, this, "Zeta::OverTimeEffect");
}

} /* namespace Zeta */

