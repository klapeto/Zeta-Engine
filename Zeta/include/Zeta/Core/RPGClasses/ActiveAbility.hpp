/*
 * ActiveAbility.hpp
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

#ifndef ACTIVEABILITY_HPP_
#define ACTIVEABILITY_HPP_

#include <Zeta/Core/RPGClasses/ActiveAbilityClass.hpp>
#include <Zeta/Core/RPGClasses/ClassifiedAbility.hpp>
#include <Zeta/Core/Updateable.hpp>
#include <Zeta/Core/ZetaConfig.hpp>
#include <Zeta/Core/ZSmallMap.hpp>
#include <Zeta/Core/ZSmallSet.hpp>
#include <string>

namespace Zeta {

class Projectile;
class Visitor;
class SoundInstance;
class Attribute;

class ActiveAbility: public ClassifiedAbility<ActiveAbilityClass>,
		public Updateable {
public:

	enum class State {
		Ready, onCoodown, Casting, Inactive
	};

	Result invoke();
	void update(Float elapsedTime);

	Float getRemainingCooldown() const {
		return state == State::onCoodown ? frameCounter : 0;
	}
	bool isCasting() const {
		return (state == State::Casting);
	}
	bool isReady() const {
		return (state == State::Ready);
	}
	bool isOnCooldown() const {
		return (state == State::onCoodown);
	}
	bool isDone() const {
		return finished;
	}
	bool canBeInvoked() const;
	bool isThereEnoughMana() const;

	Float getCastTime() const {
		return castTime;
	}

	void setCastTime(Float castTime) {
		this->castTime = castTime;
	}

	Float getCoolDown() const {
		return coolDown;
	}

	void setCoolDown(Float coolDown) {
		this->coolDown = coolDown;
	}

	Float getManaCost() const {
		return manaCost;
	}

	void setManaCost(Float manaCost) {
		this->manaCost = manaCost;
	}

	Float getRange() const {
		return range;
	}

	void setRange(Float range) {
		this->range = range;
	}

	void stopCasting();

	void invokeProjectile(const std::string& name, Float x, Float y);
	void applyEffect(const std::string& name, Lifeform *target, int level);

	void accept(Visitor& visitor);

	void pushToLua(lua_State* lstate);

	ActiveAbility(const ActiveAbilityClass& abilityClass, Lifeform *owner,
			int level);
	virtual ~ActiveAbility();
protected:

	ZSmallMap<std::string, Projectile*> availableProjectiles;
	ZSmallSet<Projectile*> projectiles;

	SoundInstance *castingSound;
	SoundInstance *releaseSound;

	Lifeform *target;
	Attribute &ownerMana;

	Float manaCost;
	Float coolDown;
	Float castTime;
	Float range;

	Float frameCounter;
	State state;

	bool hasCastingAnimation;
	bool hasReleaseAnimation;
	bool hasCastingSound;
	bool hasReleaseSound;
	bool animationChanged;
	bool isCastingSoundPlaying;
	bool finished;

	virtual void release();
	virtual Result checkConditions();
	virtual void cast();
	void onLevelChange();
};

} /* namespace Zeta */

#endif /* ACTIVEABILITY_HPP_ */
