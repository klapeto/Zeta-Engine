/*
 * Lifeform.hpp
 *
 *  Created on: 7 Ιαν 2014
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

#ifndef LIFEFORM_HPP_
#define LIFEFORM_HPP_

#include <Zeta/Core/AnimationClasses/AnimationHandler.hpp>
#include <Zeta/Core/RPGClasses/Object.hpp>
#include <Zeta/Core/UtilityClasses/Rectangle.hpp>
#include <Zeta/Core/UtilityClasses/Vector2.hpp>
#include <Zeta/Core/RPGClasses/LifeformState.hpp>
#include <Zeta/Core/RPGClasses/Attribute.hpp>
#include <Zeta/Core/RPGClasses/Modifier.hpp>
#include <Zeta/Core/RPGClasses/Ability.hpp>
#include <Zeta/Core/LuaTable.hpp>
#include <Zeta/Core/LuaFunctor.hpp>
#include <Zeta/Core/ZetaConfig.hpp>
#include <list>
#include <string>
#include <Zeta/Core/ZSmallSet.hpp>
#include <Zeta/Core/ZSmallMap.hpp>
#include <Zeta/Core/ZMap.hpp>

namespace CEGUI {
class Window;
}  // namespace CEGUI

namespace Zeta {

class Effect;
class Damage;
class Behaviour;
class ActiveAbility;
class LifeformClass;
class PassiveAbility;
class Regeneration;
class Faction;
class EffectClass;
class AbilityClass;

class Lifeform: public Object {
public:

	virtual void update(Float elapsedTime);
	virtual void draw(Float x, Float y, Float rotation = 0.0f, Float scale =
			1.0f) const;
	virtual void onCollidedWith(Object *other);
	virtual void onClick(Object *other);
	virtual void onShow();
	virtual void onHide();
	void moveToPosition(Float x, Float y);
	void moveToPosition(const Vector2& pos) {
		moveToPosition(pos.getX(), pos.getY());
	}
	void startMovingToDirection(const Vector2& pos);
	const LifeformState& getState() const {
		return state;
	}
	void stopMoving();
	void setClass(const std::string& path);
	void setClass(const LifeformClass& lifeClass);
	const LifeformClass& getClass() const {
		return *lifeformClass;
	}
	void setAnimationClass(const std::string& path);
	void setActionAnimation(const std::string& name);
	bool isAnimationFinished() const;
	void addOffAnimation(const Animation& animation, Float dx = 0.0f, Float dy =
			0.0f, AnimationHandler::QueuePlace queue =
			AnimationHandler::QueuePlace::Front) {
		animHandler.addOffAnimation(animation, dx, dy, queue);
	}
	AnimationHandler& getAnimationHandler() {
		return animHandler;
	}
	const AnimationHandler& getAnimationHandler() const {
		return animHandler;
	}
	void resetState() {
		setState(prevState);
	}

	bool canMove() const {
		return (state.getAction() != LifeformState::Action::Casting);
	}
	void fullResetState();
	inline bool isAlive() const {
		return state.getAction() != LifeformState::Action::Dead
				&& state.getAction() != LifeformState::Action::Dying;
	}
	AttributeValue getAttributeValue(const std::string& name) const {
		return attributes[name].getValue();
	}
	Attribute& getAttribute(const std::string& name) {
		return attributes[name];
	}
	const Attribute& getAttribute(const std::string& name) const {
		return attributes[name];
	}
	void setAttributeBaseValue(const std::string& name, AttributeValue value);
	void getAttributesLuaTable() const;
	void addAttributeModifier(const std::string& attributeName, Modifier *mod);
	void addAttributeModifier(const std::string& attributeName,
			const std::string& modifierName, Float value,
			enum Modifier::Type type);
	void removeAttributeModifier(const std::string& attributeName,
			const std::string& modifierName);
	void offsetMana(AttributeValue value);
	void offsetHP(AttributeValue value);
	void setHP(AttributeValue value);
	void setMana(AttributeValue value);
	void addEffect(Effect *eff);
	bool canReceiveEffect(const EffectClass& effClass) const;
	const std::list<Effect*>& getEffects() const {
		return effects;
	}
	const ZSmallMap<std::string, ActiveAbility*>& getActiveAbilities() const {
		return activeAbilities;
	}
	bool hasTarget() const {
		return (target != nullptr);
	}
	bool isDirty() const {
		return dirty;
	}
	void setDirty(bool val = true) {
		dirty = val;
	}
	void setTarget(Lifeform *trg) {
		target = trg;
	}
	Lifeform* getTarget() {
		return target;
	}
	bool isInMeleeRange(const Lifeform* lf) const {
		return lf != nullptr ?
				targetArea.overlapsRectangle(lf->getTargetArea()) : false;
	}
	int getLevel() const {
		return level;
	}
	bool isMoving() const {
		return state.getAction() == LifeformState::Action::Moving;
	}
	bool isDying() const {
		return state.getAction() == LifeformState::Action::Dying;
	}
	bool isInCombat() const {
		return inCombat;
	}
	void setInCombat(bool combat) {
		inCombat = combat;
	}
	const Faction& getFaction() const {
		return *faction;
	}

	bool isHostileWith(Lifeform* other) const;

	const LuaTable& getTable() const {
		return table;
	}
	lua_Object getLuaTable();
	void setLuaTable(lua_Object table);
	Ability::Result invokeAbility(const std::string& name) const;
	void addAbility(const std::string& abilityClass, int level);
	void addAbility(const AbilityClass& abilityClass, int level);
	ActiveAbility* getActiveAbility(const std::string& abilityName);
	PassiveAbility* getPassiveAbility(const std::string& abilityName);
	Regeneration* getRegeneration(const std::string& regenerationName);
	Ability* getAbility(const std::string& abilityName);
	virtual void teleportToCordinates(Float x, Float y);
	virtual void die();
	virtual void resurect();
	void setCastingState();
	void hardReset();
	void resetShapes();
	void face(const Vector2 &position);
	void face(Float x, Float y) {
		face(Vector2(x, y));
	}
	void face(Object *other) {
		if (other != nullptr)
			face(other->getPosition());
	}
	bool isFacing(Object *other) const;

	virtual void pushToLua(lua_State* lstate);

	virtual void accept(Visitor& visitor);

	Lifeform();
	Lifeform(const std::string& lifeClass, Float x, Float y);
	Lifeform(const LifeformClass& lifeClass, Float x, Float y);
	virtual ~Lifeform();
protected:

	mutable ZMap<std::string, Attribute> attributes;
	ZSmallMap<std::string, Modifier*> modifiers;
	ZSmallMap<std::string, ActiveAbility*> activeAbilities;
	ZSmallMap<std::string, PassiveAbility*> passiveAbilities;
	ZSmallMap<std::string, Regeneration*> regenerations;
	std::list<Effect*> effects;
	ZSmallSet<std::string> nonStackableEffects;
	AnimationHandler animHandler;
	const LifeformClass *lifeformClass;
	Ellipsis shadow;
	Vector2 targetPosition;
	Vector2 direction;
	LuaTable table;
	LuaFunctor onCollisionF;
	LuaFunctor onClickF;
	Lifeform *target;
	Behaviour *generalAI;
	Behaviour *movementAI;
	const Faction* faction;
	int level;
	LifeformState state;
	LifeformState prevState;
	bool inCombat;
	bool dirty;

	void setIdleState();
	void setDeadState();
	void setMovingState();
	void setState(const LifeformState& st);
	void setState(LifeformState::CombinedState newState);
	virtual void updateMovement(Float elapsedTime);
	void updateEffects(Float elapsedTime);
	void updateAbilities(Float elapsedTime);
	virtual void addShapesToBeOffseted();
	void calculateDirection();

	friend class LifeformClass;
};

} /* namespace Zeta */

#endif /* LIFEFORM_HPP_ */
