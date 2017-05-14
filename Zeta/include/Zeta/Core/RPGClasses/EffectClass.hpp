/*
 * EffectClass.hpp
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

#ifndef EFFECTCLASS_HPP_
#define EFFECTCLASS_HPP_

#include <Zeta/Core/ZetaConfig.hpp>
#include <Zeta/Core/LuaFunctor.hpp>
#include <string>

namespace Zeta {

class Lifeform;
class Effect;
class LuaTable;

class EffectClass {
public:

	const std::string& getName() const {
		return name;
	}

	const LuaFunctor& getOnApply() const {
		return onApply;
	}
	const LuaFunctor& getOnRemove() const {
		return onRemove;
	}
	const LuaFunctor& getOnTick() const {
		return onTick;
	}
	Float getUpTime() const {
		return uptime;
	}
	Float getTickEvery() const {
		return tickEvery;
	}

	bool isStackable() const {
		return stackable;
	}

	EffectClass(EffectClass&&) = default;
	EffectClass& operator=(EffectClass&&) = default;

	Effect* getNewEffect(Lifeform *target, int level) const;

	EffectClass();
	EffectClass(const LuaTable& table);
	EffectClass(lua_Object table);
	~EffectClass();
private:

	std::string name;

	LuaFunctor onApply;
	LuaFunctor onRemove;
	LuaFunctor onTick;

	Float uptime;
	Float tickEvery;

	bool durable;
	bool overTime;
	bool stackable;

};

} /* namespace Zeta */

#endif /* EFFECTCLASS_HPP_ */
