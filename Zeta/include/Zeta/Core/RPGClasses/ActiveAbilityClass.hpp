/*
 * ActiveAbilityClass.hpp
 *
 *  Created on: 25 Σεπ 2014
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

#ifndef ACTIVEABILITYCLASS_HPP_
#define ACTIVEABILITYCLASS_HPP_

#include <Zeta/Core/LuaTable.hpp>
#include <Zeta/Core/RPGClasses/AbilityClass.hpp>
#include <Zeta/Core/RPGClasses/EffectClass.hpp>
#include <Zeta/Core/RPGClasses/ProjectileClass.hpp>
#include <Zeta/Core/ZetaConfig.hpp>
#include <Zeta/Core/ZMap.hpp>
#include <string>

namespace Zeta {

class ActiveAbilityClass: public AbilityClass {
public:

	Float getCooldown() const {
		return cooldown;
	}

	Float getManaCost() const {
		return manaCost;
	}

	Float getCastTime() const {
		return castTime;
	}

	Float getRange() const {
		return range;
	}

	const std::string& getCastAnimation() const {
		return castAnimation;
	}

	const std::string& getReleaseAnimation() const {
		return releaseAnimation;
	}

	const std::string& getCastSound() const {
		return castSound;
	}

	const std::string& getReleaseSound() const {
		return releaseSound;
	}

	const ProjectileClass* getProjectileClass(const std::string& name) const;

	Ability* getNewAbility(Lifeform *caster, int level) const;

	const ZMap<std::string, ProjectileClass>& getProjectileClasses() const {
		return projectiles;
	}

	const ZMap<std::string, EffectClass>& getEffectClasses() const {
		return effects;
	}

	void applyEffect(const std::string& name, Lifeform *target, int level,
			ActiveAbility* ability = nullptr) const;

	void pushToLua(lua_State* lstate);

	ActiveAbilityClass(AbilityClass& parent, LuaTable& table);
	~ActiveAbilityClass();
private:
	ZMap<std::string, EffectClass> effects;
	ZMap<std::string, ProjectileClass> projectiles;
	std::string castAnimation;
	std::string releaseAnimation;
	std::string castSound;
	std::string releaseSound;

	Float range;
	Float manaCost;
	Float castTime;
	Float cooldown;
};

} /* namespace Zeta */

#endif /* ACTIVEABILITYCLASS_HPP_ */
