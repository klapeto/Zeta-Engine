/*
 * AbilityClass.hpp
 *
 *  Created on: 3 Απρ 2014
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

#ifndef ABILITYCLASS_HPP_
#define ABILITYCLASS_HPP_

#include <Zeta/Core/LuaFunctor.hpp>
#include <Zeta/Core/LuaTable.hpp>
#include <Zeta/Core/ResourceClasses/Resource.hpp>
#include <Zeta/Core/ZetaConfig.hpp>
#include <string>

struct lua_State;

namespace Zeta {

class Lifeform;
class Ability;

class AbilityClass: public Resource, public LuaPushable {
public:

	enum class Type {
		Active, Passive, Regeneration
	};

	int getLevels() const {
		return levels;
	}

	const std::string& getAbilityName() const {
		return abilityName;
	}

	bool isPassive() const {
		return type == Type::Passive;
	}

	Type getType() const {
		return type;
	}

	const AbilityClass* getParent() const {
		return parent;
	}

	const LuaTable& getTable() const {
		return table;
	}

	lua_Object getLuaTable() const;

	void onApply(Ability *invoker, Lifeform *caster, Lifeform *target) const;
	void onRemove(Ability *invoker, Lifeform *caster, Lifeform *target) const;
	void onLevelChange(Ability *invoker) const;

	virtual Ability* getNewAbility(Lifeform *caster, int level) const;

	virtual void pushToLua(lua_State* lstate);

	AbilityClass();
	AbilityClass(const std::string& path);
	AbilityClass(lua_Object table);
	AbilityClass(AbilityClass& parent, LuaTable& table);
	virtual ~AbilityClass();
protected:
	std::string abilityName;
	mutable LuaTable table;
	LuaFunctor onApplyF;
	LuaFunctor onRemoveF;
	LuaFunctor onLevelChangeF;
	AbilityClass* implementation;
	AbilityClass* parent;
	int levels;
	Type type;

	void getData(LuaTable& table);
	void nullise();
};

} /* namespace Zeta */

#endif /* ABILITYCLASS_HPP_ */
