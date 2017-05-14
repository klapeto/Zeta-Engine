/*
 * EffectClass.cpp
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

#include <Zeta/Core/LuaTable.hpp>
#include <Zeta/Core/RPGClasses/EffectClass.hpp>
#include <Zeta/Core/RPGClasses/OverTimeEffect.hpp>
#include <Zeta/Core/Logger.hpp>

namespace Zeta {

EffectClass::EffectClass() :
		uptime(5), tickEvery(1), durable(false), overTime(false), stackable(
				false) {
	name = "null EffectClass";
}

EffectClass::EffectClass(const LuaTable& table) :
		uptime(5), tickEvery(1), durable(false), overTime(false), stackable(
				false) {
	if (table.getField(LuaString("Name"), name)) {
		Logger::getInstance().write(
				"No Name specified for EffectClass passed through Lua. Reseting to \"No Named EffectClass\"",
				Logger::MessageType::Warning);
		name = "No Named EffectClass";
	}
	table.getField(LuaString("Durable"), durable);
	table.getField(LuaString("OverTime"), overTime);
	table.getField(LuaString("UpTime"), uptime);
	table.getField(LuaString("onApply"), onApply);
	table.getField(LuaString("Stackable"), stackable);
	onApply.setName(name + ": onApply");
	table.getField(LuaString("onRemove"), onRemove);
	onRemove.setName(name + ": onRemove");
	if (overTime) {
		table.getField(LuaString("onTick"), onTick);
		onTick.setName(name + ": onTick");
		table.getField(LuaString("TickEvery"), tickEvery);
	}

}

EffectClass::EffectClass(lua_Object table) :
		uptime(5), tickEvery(1), durable(false), overTime(false), stackable(
				false) {
	LuaTable tmp(table);
	tmp.getField(LuaString("Name"), name);
	tmp.getField(LuaString("Durable"), durable);
	tmp.getField(LuaString("OverTime"), overTime);
	tmp.getField(LuaString("UpTime"), uptime);
	tmp.getField(LuaString("onApply"), onApply);
	tmp.getField(LuaString("Stackable"), stackable);
	onApply.setName(name + ": onApply");
	tmp.getField(LuaString("onRemove"), onRemove);
	onRemove.setName(name + ": onRemove");
	if (overTime) {
		tmp.getField(LuaString("onTick"), onTick);
		onTick.setName(name + ": onTick");
		tmp.getField(LuaString("TickEvery"), tickEvery);
	}
}

Effect* EffectClass::getNewEffect(Lifeform* target, int level) const {
	if (overTime) {
		return new OverTimeEffect(*this, target, level);
	} else if (durable) {
		return new DurableEffect(*this, target, level);
	} else {
		return new Effect(*this, target, level);
	}
}

EffectClass::~EffectClass() {

}

} /* namespace Zeta */

