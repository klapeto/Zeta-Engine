/*
 * Lifeform.cpp
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

#include <Zeta/Core/ConsoleFunctions.hpp>
#include <Zeta/Core/Logger.hpp>
#include <Zeta/Core/LuaEngine.hpp>
#include <Zeta/Core/MapClasses/Map.hpp>
#include <Zeta/Core/RPGClasses/AbilityClass.hpp>
#include <Zeta/Core/ResourceClasses/AnimationClass.hpp>
#include <Zeta/Core/AnimationClasses/AnimationPlayer.hpp>
#include <Zeta/Core/ResourceContext.hpp>
#include <Zeta/Core/RPGClasses/Ability.hpp>
#include <Zeta/Core/RPGClasses/ActiveAbility.hpp>
#include <Zeta/Core/RPGClasses/ChildObject.hpp>
#include <Zeta/Core/RPGClasses/PassiveAbility.hpp>
#include <Zeta/Core/RPGClasses/Regeneration.hpp>
#include <Zeta/Core/RPGClasses/Effect.hpp>
#include <Zeta/Core/RPGClasses/FlatModifier.hpp>
#include <Zeta/Core/RPGClasses/Lifeform.hpp>
#include <Zeta/Core/RPGClasses/LifeformClass.hpp>
#include <Zeta/Core/RPGClasses/Modifier.hpp>
#include <Zeta/Core/RPGClasses/MulModifier.hpp>
#include <Zeta/Core/RPGClasses/WorldEvent.hpp>
#include <Zeta/Core/RPGClasses/WorldManager.hpp>
#include <Zeta/Core/RPGClasses/AI/Behaviour.hpp>
#include <Zeta/Core/RPGClasses/AI/Faction.hpp>
#include <Zeta/Core/SingleInstanced.hpp>
#include <Zeta/Core/System.hpp>
#include <Zeta/Core/UtilityClasses/Ellipsis.hpp>
#include <Zeta/Core/UtilityClasses/Shape.hpp>
#include <Zeta/Core/UtilityClasses/Visitor.hpp>
#include <Zeta/Core/NullReference.hpp>
#include <lua.hpp>
#include <tolua++.h>
#include <cmath>
#include <utility>
#include <vector>

namespace Zeta {

Lifeform::Lifeform() :
		Object(), lifeformClass(nullptr), target(nullptr), faction(
				&NullReference<Faction>::getNull()), level(1), inCombat(false), dirty(
				true) {
	addShapesToBeOffseted();
}

Lifeform::Lifeform(const std::string& lifeClass, Float x, Float y) :
		Object(), lifeformClass(nullptr), target(nullptr), generalAI(nullptr), movementAI(
				nullptr), faction(&NullReference<Faction>::getNull()), inCombat(
				false), dirty(true) {
	addShapesToBeOffseted();

	// We set the position
	position.set(x, y);
	// We set the LifeformClass
	setClass(lifeClass);
}

Lifeform::Lifeform(const LifeformClass& lifeClass, Float x, Float y) :
		Object(), lifeformClass(nullptr), target(nullptr), generalAI(nullptr), movementAI(
				nullptr), faction(&NullReference<Faction>::getNull()), inCombat(
				false), dirty(true) {
	addShapesToBeOffseted();
	position.set(x, y);
	setClass(lifeClass);
}

void Lifeform::update(Float elapsedTime) {
	// If this Lifeform is alive
	if (isAlive()) {

		// Update the AI Handlers if defined
		if (generalAI != nullptr) {
			generalAI->update(elapsedTime);
		}

		if (movementAI != nullptr) {
			movementAI->update(elapsedTime);
		}

		// Check if moving and update it
		updateMovement(elapsedTime);
		// Update the effects this Lifeform has (durations, etc)
		updateEffects(elapsedTime);
		// Update the abilities (cooldown, etc)
		updateAbilities(elapsedTime);

		for (auto& child : childs) {
			child.second->update(elapsedTime);
		}
	} else {
		// else if is not alive

		// if is Dying, then this means the die() function called
		// and the death animation is invoked. When the death animation
		// is finished, we should set the according dead state
		if (state.getAction() == LifeformState::Action::Dying
				&& !animHandler.getMainAnimationPlayer().isPlaying()) {
			// set the acording animations/states to Dead
			setDeadState();
		}
	}
	// Update the animations
	animHandler.update(elapsedTime);
}

void Lifeform::draw(Float x, Float y, Float rotation, Float scale) const {
	if (visible) {
		// Draw the shadow Ellipsis the Animation class provided
		if (animHandler.getAnimationClass().hasShadow()) {
			shadow.draw(x, y, rotation, scale);
		}

		for (auto& child : childs) {
			child.second->draw(x, y, rotation, scale);
		}

		// Draw the animations
		animHandler.draw(position.getX() - x, position.getY() - y, rotation,
				scale);

		// If the user enabled from console to show the Bound Boxes, do it
		if (ConsoleFunctions::getInstance().isBoundsShown()) {
			// Draw the Bound Box
			bounding.draw(x, y, rotation, scale);
			targetArea.draw(x, y, rotation, scale);
		}
	}
}

void Lifeform::moveToPosition(Float x, Float y) {
	if (canMove()) {
		// Set the targetPosition
		targetPosition.set(x, y);
		// Calculate the Normalized Direction
		calculateDirection();

		// What state we have now?
		setMovingState();
	} else if (state.getAction() == LifeformState::Action::Casting) {
		// XXX: Hack to reduce the lag felt when you cast from idle state
		// and a move was chosen while casting was occuring, resulting staying idle
		// rather than moving to the desired location. Its not a bug, but a the player
		// will not like it
		prevState = LifeformState::Action::Moving;
		// Set the targetPosition
		targetPosition.set(x, y);
		// Calculate the Normalized Direction
		calculateDirection();
	}
}

Lifeform::~Lifeform() {
	onHide();
	hardReset();
}

void Lifeform::hardReset() {
	// Erase all effects
	for (auto eff : effects) {
		delete eff;
	}
	effects.clear();
	// Erase all Abilities
	for (auto ab : activeAbilities) {
		delete ab.second;
	}
	activeAbilities.clear();
	for (auto ab : passiveAbilities) {
		delete ab.second;
	}
	passiveAbilities.clear();
	for (auto ab : regenerations) {
		delete ab.second;
	}
	regenerations.clear();

	// Erase all modifiers
	for (auto& att : attributes) {
		att.second.removeAllModifiers(true);
	}

	delete generalAI;
	delete movementAI;
	generalAI = nullptr;
	movementAI = nullptr;

	modifiers.clear();
	// Erase all Attributes
	attributes.clear();
	// Clear the target
	target = nullptr;
	// Set to default state
	setState(LifeformState::Action::Idle | LifeformState::Direction::Down);
	// Clear the current animation class by getting a non Existing
	animHandler.setAnimationClass("");
	// reset position;
	setPosition(0, 0);
	// release the lifeformclass
	ResourceContext* resources = &System::getInstance().getResourcesManager();
	if (resources != nullptr) {
		resources->releaseResource(*lifeformClass);
	}
}

void Lifeform::stopMoving() {
	// set IdleState
	setIdleState();
}

void Lifeform::die() {
	collideAble = false;
	triggersCollisionEvents = false;
	inCombat = false;
	target = nullptr;

	// Stop any casting happeningq
	for (auto ability : activeAbilities) {
		ability.second->stopCasting();
	}

	// Which state we have? Set the according direction dying animation/state

	setState(LifeformState::Action::Dying);
	animHandler.setAnimation(state.getCombinedState());
	// Stat the dying animation
	animHandler.getMainAnimationPlayer().play();

	// Notify the AI Handlers
	if (generalAI != nullptr) {
		generalAI->onDeath();
	}

	if (movementAI != nullptr) {
		movementAI->onDeath();
	}

	WorldEvent event;
	event.type = WorldEvent::Type::Death;
	event.data.deathEvent.victim = this;
	WorldManager::getInstance().raiseEvent(event);

	WorldManager::getInstance().callCallback(
			WorldManager::Callback::LifeformDeath, { this });
}

void Lifeform::setIdleState() {
	// Set the according Idle animation/state depending on the current one
	setState(LifeformState::Action::Idle);
	animHandler.setAnimation(state.getCombinedState());
}

void Lifeform::setClass(const std::string& path) {
	setClass(
			System::getInstance().getResourcesManager().getLifeformClass(path));
}

void Lifeform::setAnimationClass(const std::string& path) {
	// forward the new AnimationClass path to AnimationHandler
	animHandler.setAnimationClass(path);
}

void Lifeform::setDeadState() {
	// Set state to Dead
	setState(LifeformState::Action::Dead);
	// Set the according animation to Dead
	animHandler.setAnimation(state.getCombinedState());
}

void Lifeform::teleportToCordinates(Float x, Float y) {
	// Use the Object::setPosition() to get the desired results
	//resetShapes();
	setPosition(x, y);
}

void Lifeform::setMovingState() {
	bool animationShouldChange = false;

	{
		// get the absolute value of the direction on both axis
		Float xValue = std::abs(direction.getX());
		Float yValue = std::abs(direction.getY());

		// The animation to change
		LifeformState::Direction animDir = state.getDirection();
		// Check if we need to use a Vertical or Horizontal animation
		// we actually see where we lean more, on the x axis or the y axis
		if (xValue > yValue) {
			// If we need a horizontal, check if we need right or left
			if (direction.getX() > 0.0f) {
				animDir = LifeformState::Direction::Right;
			} else {
				animDir = LifeformState::Direction::Left;
			}
		} else {
			// if we need vertical check if we need up or down
			if (direction.getY() > 0.0f) {
				animDir = LifeformState::Direction::Down;
			} else {
				animDir = LifeformState::Direction::Up;
			}
		}
		// If state is not already to the one we calculated
		if (state.getDirection() != animDir) {
			// Set the state to the correct one
			state = animDir;
			// Set the Animation to the Primitive::Moving_Right
			animationShouldChange = true;
		}
	}
	if (state.getAction() != LifeformState::Action::Moving
			|| animationShouldChange) {
		// Set that we are moving now
		setState(LifeformState::Action::Moving);
		animHandler.setAnimation(state.getCombinedState());
	}
	// Start the animations (if not already started)
	animHandler.getMainAnimationPlayer().play();
}

void Lifeform::addEffect(Effect* eff) {
	// if eff is not null
	if (eff != nullptr) {
		// push eff to effects list
		if (!eff->getClass().isStackable()) {
			auto itr = nonStackableEffects.find(eff->getClass().getName());
			if (itr != nonStackableEffects.end()) {
				delete eff;
				return;
			} else {
				nonStackableEffects.insert(eff->getClass().getName());
			}
		}
		effects.push_back(eff);
	}
}

void Lifeform::updateMovement(Float elapsedTime) {
	// If movement is enabled (Eg. Not casting, or has target location)
	if (state.getAction() == LifeformState::Action::Moving) {
		// Get the speed attribute and multiply it by the elapsed time.
		// We multiply it to ensure that the speed of the movement will remain constant
		// on FPS changes
		Float speed = attributes["Speed"].getValue() * elapsedTime;
		// If we are near the target location
		if (position.getDistance(targetPosition) <= (speed + 0.1f)) {
			// Stop Moving and set the associated primitive animations
			setIdleState();
		} else {
			// Else if we are far from target Location

			// Calculate the offsets to add to get the next Position
			// (direction) has the Normalized vector from the currentPosition to target Position
			// So multiplying each delta with speed gives us the according
			// offsets to add to current x,y to retrieve the the next frame position
			Float off_x = direction.getX() * speed;
			Float off_y = direction.getY() * speed;

			bool moving = true;

			// Retrieve the current Map
			Map& curMap = WorldManager::getInstance().getCurrentMap();

			{
				// Get a copy of Bound Rectangle
				Rectangle rect = bounding;

				// Offset the copy to the future position on X Axis
				rect.offsetPosition(off_x, 0);

				// Check if the future bounding will collide with anything
				// on X axis (cause we offset on with off_x)
				if (curMap.isRectangleColliding(rect, this,
						off_x > 0 ?
								Rectangle::Surface::Right :
								Rectangle::Surface::Left)) {
					// If it does collide, the reset the off_x, meaning that
					// we will not move on X axis
					off_x = 0;

					// We get the distance from targetPosition on Y axis
					float dy = targetPosition.getY()
							- (position.getY() + off_y);
					// if the distance is very near
					if (std::abs(dy) < (speed + 0.1f)) {
						// Stop moving
						moving = false;
					}
				}
			}
			{
				// Get a copy of Bound Rectangle
				Rectangle rect = bounding;

				// Offset the copy to the future position on Y Axis
				rect.offsetPosition(0, off_y);

				// Check if the future bounding will collide with anything
				// on Y axis (cause we offset on wit off_y)
				if (curMap.isRectangleColliding(rect, this,
						off_y > 0 ?
								Rectangle::Surface::Bottom :
								Rectangle::Surface::Top)) {

					// If it does collide, the reset the off_y, meaning that
					// we will not move on Y axis
					off_y = 0;

					// We get the distance from targetPosition on Y axis
					float dx = targetPosition.getX()
							- (position.getX() + off_x);

					// if the distance is very near
					if (std::abs(dx) < (speed + 0.1f)) {
						// We should stop moving
						moving = false;
					}
				}
			}

			// If we are still moving and any of the offsets are not 0
			if (moving && (off_x != 0 || off_y != 0)) {
				// this means we can actually move

				// add the offsets to position, bounding and TargetArea
				offsetPosition(off_x, off_y);

				// If we faced an obstacle, one of the offsets must be 0
				// depending on which side we faced it. In such case
				// the initial direction will miss the targetPosition
				// because we didn't move completely as intended. So
				// we have to recalculate the direction so the next frame
				// will move to correct position (See Manual for further explanation)
				if (off_x == 0 || off_y == 0) {
					calculateDirection();
					// set the according moving animations
					setMovingState();
				}
			} else {
				// else we can not move
				// set the according idle Animations
				setIdleState();
			}

		}
	}
}

void Lifeform::setActionAnimation(const std::string& name) {
	// Since the Action-Animation Convention requires the
	// format : action/direction , we have to add a '/' at the end
	// of the animation target animation before applying the direction

	// According to current state, add to name buffer the direction
	switch (state.getDirection()) {
	case LifeformState::Direction::Down:
		animHandler.setAnimation(name + "/Down",
				LifeformState::Action::Idle | LifeformState::Direction::Down);
		break;
	case LifeformState::Direction::Left:
		animHandler.setAnimation(name + "/Left",
				LifeformState::Action::Idle | LifeformState::Direction::Left);
		break;
	case LifeformState::Direction::Right:
		animHandler.setAnimation(name + "/Right",
				LifeformState::Action::Idle | LifeformState::Direction::Right);
		break;
	case LifeformState::Direction::Up:
		animHandler.setAnimation(name + "/Up",
				LifeformState::Action::Idle | LifeformState::Direction::Up);
		break;
	default:
		animHandler.setAnimation(name + "/Down",
				LifeformState::Action::Idle | LifeformState::Direction::Down);
		break;
	}

	// Make AnimationHandler to change to the Buffered animation name
	animHandler.getMainAnimationPlayer().play();
}

void Lifeform::setState(const LifeformState& st) {
	// Backup the current state
	prevState = state;
	// Change the current state to the arguments (st)
	state = st;
}

void Lifeform::updateEffects(Float elapsedTime) {
	// for all the effects in the effects list
	for (auto itr = effects.begin(); itr != effects.end();) {
		// Update the effect
		(*itr)->update(elapsedTime);
		// If effect isFinished (duration is over, etc)
		if ((*itr)->isFinished()) {
			auto nonS = nonStackableEffects.find((*itr)->getClass().getName());
			if (nonS != nonStackableEffects.end()) {
				nonStackableEffects.erase(nonS);
			}

			// delete the effect
			delete *itr;
			// erase it's pointer from the list to
			// avoid segmentation faults. We get the next iterator
			// from erasing it
			itr = effects.erase(itr);
		} else {
			// if the effect is not Finished, the just carry on
			++itr;
		}
	}
}

Ability::Result Lifeform::invokeAbility(const std::string& name) const {
	// Find the ability name in the Lifeform's abilities container
	auto itr = activeAbilities.find(name);
	// if this ability is found
	if (itr != activeAbilities.end()) {
		// invoke it and return it's result
		return itr->second->invoke();
	} else {
		// else if the ability is not in possession of this Lifeform,
		// return InvalidAbility
		return Ability::Result::InvalidAbility;
	}
}

void Lifeform::addAttributeModifier(const std::string& attributeName,
		Modifier* mod) {
	// dirtyfy the Lifeform
	dirty = true;
	// Get the attribute reference
	Attribute &at = attributes[attributeName];
	// add the modifier
	at.addModifier(mod);
}

void Lifeform::offsetMana(AttributeValue value) {
	// dirtyfy the Lifeform
	dirty = true;
	// Get the Mana attribute reference
	Attribute &at = attributes["Mana"];
	// Apply directly to base value, the value of the Arg
	at.applyToBaseFlat(value);
}

void Lifeform::offsetHP(AttributeValue value) {
	// dirtyfy the Lifeform
	dirty = true;
	// Get the Hp attribute reference
	Attribute &at = attributes["HP"];
	// Apply directly to base value, the value of the Arg
	at.applyToBaseFlat(value);

	if (isAlive() && at.getValue() <= 0) {
		// set the HP to 0 (cause Damage might have got it below 0)
		at.setBase(0);
		// and finally die
		die();
	}
}

void Lifeform::setHP(AttributeValue value) {
	// dirtyfy the Lifeform
	dirty = true;
	// Get the Hp attribute reference
	Attribute &at = attributes["HP"];
	// Set the base value
	at.setBase(value);
}

void Lifeform::setMana(AttributeValue value) {
	// dirtyfy the Lifeform
	dirty = true;
	// Get the Hp attribute reference
	Attribute &at = attributes["Mana"];
	// Set the base value
	at.setBase(value);
}

void Lifeform::fullResetState() {
	//TODO: All states...

	// Change the State according to the Previous state
	switch (prevState.getAction()) {
	case LifeformState::Action::Idle:
		setIdleState();
		break;
	case LifeformState::Action::Moving:
		setMovingState();
		break;
	default:
		setIdleState();
		break;
	}
}

void Lifeform::setCastingState() {
	// Set the castingState according to Current State
	setState(LifeformState::Action::Casting);
	// Start the animations
	animHandler.getMainAnimationPlayer().play();
}

void Lifeform::updateAbilities(Float elapsedTime) {
	// For all abilities
	for (auto ab : activeAbilities) {
		// Update the ability
		ab.second->update(elapsedTime);
	}

	for (auto ab : regenerations) {
		ab.second->update(elapsedTime);
	}
}

void Lifeform::resetShapes() {
	// Get the current AnimationClass from  the Lifeform's AnimationHandler
	const AnimationClass &cls = animHandler.getAnimationClass();
	// Retrieve the Shapes
	bounding = cls.getBoundBox();
	targetArea = cls.getTargetBox();
	shadow = cls.getShadow();
}

void Lifeform::onClick(Object *other) {
	// Call the Lua function with the arguments
	onClickF( { &table, this, other });
}

void Lifeform::face(const Vector2& position) {
	// Calculate the delta
	Vector2 dir = position - this->position;
	// Normalize the vector to get the direction
	dir.normalize();

	bool animationShouldChange = false;

	if (dir.getX() > 0.5f) {
		// If direction x > 0.5 , this means we lean Right

		// If state is not already to Idle_Right
		if (state.getDirection() != LifeformState::Direction::Right) {
			// Set the state to the correct one
			setState(LifeformState::Direction::Right);
			animationShouldChange = true;
		}
	} else if (dir.getX() < -0.5f) {
		// Else if direction x < -0.5 , this means we lean Left

		// If state is not already to Idle_Left
		if (state.getDirection() != LifeformState::Direction::Left) {
			// Set the state to the correct one
			setState(LifeformState::Direction::Left);
			animationShouldChange = true;
		}
	} else {
		// Else ( if (direction.getX() <= 0.5) && (direction.getX() > -0.5) )

		// If direction y >= 0.5 , this means we lean Down
		if (dir.getY() >= 0.5f) {

			// If state is not already to Idle_Down
			if (state.getDirection() != LifeformState::Direction::Down) {
				// Set the state to the correct one
				setState(LifeformState::Direction::Down);
				animationShouldChange = true;
			}
		} else if (dir.getY() <= -0.5f) {
			// Else if direction y <= -0.5 , this means we lean Up

			// If state is not already to Idle_Up
			if (state.getDirection() != LifeformState::Direction::Up) {
				// Set the state to the correct one
				setState(LifeformState::Direction::Up);
				animationShouldChange = true;
			}
		}
	}
	if (animationShouldChange) {
		animHandler.setAnimation(state.getCombinedState());
	}
	// Start the animations (if not already started)
	animHandler.getMainAnimationPlayer().play();
}

void Lifeform::addAttributeModifier(const std::string& attributeName,
		const std::string& modifierName, Float value, Modifier::Type type) {

	// Try finding this modifierName in the modifiers container
	auto itr = modifiers.find(modifierName);

	// if this modifier is not present
	if (itr == modifiers.end()) {

		// Get the Attribute reference with the Arg's name
		Attribute &att = attributes[attributeName];

		// Here depending on Modifier type, we add the according Modifier

		Modifier *mod;
		switch (type) {
		case Modifier::Type::Flat:
			// We add the Modifier to the attribute and store the returned iterator
			// to ModifierPair.itr
			mod = new FlatModifier(value);
			break;
		case Modifier::Type::Scalar:
			mod = new MulModifier(value);
			break;
		default:
			mod = new FlatModifier(value);
			Logger::getInstance().write(
					"Illegal Enumeration at Lifeform:" + name
							+ " on Function Call: addAttributeModifier()."
									"Reason: Possibly from a Lua call with a number/Variable argument rather than one of the pre-Defined ones(eg. Zeta.ModifierType.Flat). Defaulting to Flat...",
					Logger::MessageType::Warning);
			break;
		}

		att.addModifier(mod);

		modifiers[modifierName] = mod;
		// set dirty
		dirty = true;
	}
}

void Lifeform::removeAttributeModifier(const std::string& attributeName,
		const std::string& modifierName) {

	// Search in the modifiers for that modifier name
	auto itr = modifiers.find(modifierName);

	// if this name exists
	if (itr != modifiers.end()) {
		// Get the Attribute the ModifierPair says
		Attribute &att = attributes[attributeName];

		// remove the modifier from the Attribute with the iterator
		// from the ModifierPair we found
		att.removeModifierAndDelete(itr->second);

		// Erase this ModifierPair
		modifiers.erase(itr);
		// Set Dirty
		dirty = true;
	}

}

void Lifeform::onCollidedWith(Object* other) {
	// Call the call back with the arguments
	onCollisionF( { &table, this, other });

	WorldEvent ev;
	ev.setAsCollisionEvent(this, other);
	ev.broadcast();
}

void Lifeform::addShapesToBeOffseted() {
	// Call the Object function
	Object::addShapesToBeOffseted();
	// Add the shadow shape
	shapesToBeOffseted.push_back(&shadow);
}

lua_Object Lifeform::getLuaTable() {
	table.pushToLua(LuaEngine::getInstance().getState());
	return -1;
}

void Lifeform::setLuaTable(lua_Object table) {
	try {
		this->table.setFromStack(LuaEngine::getInstance().getState(), table);
	} catch (Exception& ex) {
		Logger::getInstance().write(
				"During getting Lifeform Table:" + ex.reason() + "\n At file: "
						+ std::string(__FILE__) + "\n At function: "
						+ std::string(__FUNCTION__));
	}
}

PassiveAbility* Lifeform::getPassiveAbility(const std::string& abilityName) {
	auto itr = passiveAbilities.find(abilityName);
	if (itr != passiveAbilities.end()) {
		return itr->second;
	}
	return nullptr;
}

Ability* Lifeform::getAbility(const std::string& abilityName) {
	{
		auto itr = activeAbilities.find(abilityName);
		if (itr != activeAbilities.end()) {
			return itr->second;
		}
	}
	{
		auto itr = passiveAbilities.find(abilityName);
		if (itr != passiveAbilities.end()) {
			return itr->second;
		}
	}
	{
		auto itr = regenerations.find(abilityName);
		if (itr != regenerations.end()) {
			return itr->second;
		}
	}
	return nullptr;
}

bool Lifeform::isAnimationFinished() const {
	return !animHandler.getMainAnimationPlayer().isPlaying();
}

bool Lifeform::isHostileWith(Lifeform* other) const {
	if (other != nullptr) {
		return faction->isHostile(other->getFaction());
	} else {
		return false;
	}
}

void Lifeform::startMovingToDirection(const Vector2& pos) {
}

bool Lifeform::canReceiveEffect(const EffectClass& effClass) const {
	if (effClass.isStackable()) {
		return true;
	} else {
		auto itr = nonStackableEffects.find(effClass.getName());
		if (itr != nonStackableEffects.end()) {
			return false;
		} else {
			return true;
		}
	}
}

void Lifeform::onShow() {
	WorldManager::getInstance().callCallback(
			WorldManager::Callback::LifeformShow, { this });
}

void Lifeform::onHide() {
	WorldManager::getInstance().callCallback(
			WorldManager::Callback::LifeformHide, { this });
}

void Lifeform::setState(LifeformState::CombinedState newState) {
	// Backup the current state
	prevState = state;
	// Change the current state to the arguments (newState)
	this->state = newState;
}

void Lifeform::calculateDirection() {
	// Get the difference between the targetPosition and current Position
	direction = targetPosition - position;
	// Normalize the vector to get the direction
	direction.normalize();
}

void Lifeform::getAttributesLuaTable() const {
// Get the lua state
	lua_State *lstate = LuaEngine::getInstance().getState();

// Create a Lua Table of size of the attributes
	lua_createtable(lstate, 0, attributes.size());

// for every attribute
	for (auto& attribute : attributes) {
		// Push the base value
		lua_pushnumber(lstate, attribute.second.getBaseValue());
		// Set the value name
		lua_setfield(lstate, -2, attribute.first.c_str());
	}
}

void Lifeform::accept(Visitor& visitor) {
	visitor.handle(*this);
}

void Lifeform::setAttributeBaseValue(const std::string& name,
		AttributeValue value) {
// Get the named Attribute
	Attribute& att = attributes[name];
// Set the attributes base value
	att.setBase(value);
}

bool Lifeform::isFacing(Object* other) const {
// Check if the function was called with a valid pointer
	if (other != nullptr) {
		// Get the difference between the positions
		Vector2 otherDir = other->getPosition() - position;
		// Normalize the difference so that we will get the direction Vector
		otherDir.normalize();
		// Check the direction's x,y to determine the discreet direction
		if (otherDir.getX() > 0.5f) {
			// This means that the Other Lifeform is mostly Right of us

			// Return true if we already facing Right
			if (state.getDirection() == LifeformState::Direction::Right) {
				return true;
			} else {
				// If we are not facing Right, return false
				return false;
			}
		} else if (otherDir.getX() < -0.5f) {
			// This means that the Other Lifeform is mostly Left of us

			// Return true if we already facing Left
			if (state.getDirection() == LifeformState::Direction::Left) {
				return true;
			} else {
				// If we are not facing Left, return false
				return false;
			}
		} else {
			// Here we get if the direction is not near Left, or Right
			// This means that it is near Up or Down

			if (otherDir.getY() >= 0.5f) {
				// This means that the Other Lifeform is mostly Down of us

				// Return true if we already facing Down
				if (state.getDirection() == LifeformState::Direction::Down) {
					return true;
				} else {
					// If we are not facing Down, return false
					return false;
				}
			} else if (otherDir.getY() <= -0.5f) {
				// This means that the Other Lifeform is mostly Up of us

				// Return true if we already facing Up
				if (state.getDirection() == LifeformState::Direction::Up) {
					return true;
				} else {
					// If we are not facing Up, return false
					return false;
				}
			}
		}

		// Getting here is nearly impossible, however we need to provide this
		return false;
	} else {
		// If it was called with no argument (nullptr), then return false
		return false;
	}

}

void Lifeform::resurect() {

// For every existing modifier
	for (auto& att : attributes) {
		att.second.removeAllModifiers(true);
	}
// Delete any effects that exist since previous life
	for (auto eff : effects) {
		delete eff;
	}
	effects.clear();

// Reset Hp/Mana attributes
	attributes["HP"] = attributes["MaxHP"];
	attributes["Mana"] = attributes["MaxMana"];

// Reset The State
	fullResetState();
}

void Lifeform::addAbility(const std::string& abilityClass, int level) {
// Get the ability Class
	const AbilityClass& cls =
			System::getInstance().getResourcesManager().getAbilityClass(
					abilityClass);
	addAbility(cls, level);
}

void Lifeform::addAbility(const AbilityClass& abilityClass, int level) {
	// Check if the ability exists
	{
		auto itr = activeAbilities.find(abilityClass.getAbilityName());
		if (itr != activeAbilities.end()) {
			// If exists, just set the new level
			itr->second->setLevel(level);
			return;
		}
	}
	{
		auto itr = passiveAbilities.find(abilityClass.getAbilityName());
		if (itr != passiveAbilities.end()) {
			// If exists, just set the new level
			itr->second->setLevel(level);
			return;
		}
	}
	{
		auto itr = regenerations.find(abilityClass.getAbilityName());
		if (itr != regenerations.end()) {
			// If exists, just set the new level
			itr->second->setLevel(level);
			return;
		}
	}
	// Else if it does not exist
	// Generate a new ability
	Ability* ab = abilityClass.getNewAbility(this, level);

	if (ab != nullptr) {
		switch (abilityClass.getType()) {
		case AbilityClass::Type::Active:
			activeAbilities[abilityClass.getAbilityName()] =
					static_cast<ActiveAbility*>(ab);
			break;
		case AbilityClass::Type::Passive:
			passiveAbilities[abilityClass.getAbilityName()] =
					static_cast<PassiveAbility*>(ab);
			break;
		case AbilityClass::Type::Regeneration:
			regenerations[abilityClass.getAbilityName()] =
					static_cast<Regeneration*>(ab);
			break;
		}
	}
}

ActiveAbility* Lifeform::getActiveAbility(const std::string& abilityName) {
// Check if the ability exists
	auto itr = activeAbilities.find(abilityName);
	if (itr != activeAbilities.end()) {
		// If exists, return it
		return itr->second;
	} else {
		// If it does not exist, return NULL
		return nullptr;
	}

}

void Lifeform::pushToLua(lua_State* lstate) {
	tolua_pushusertype(lstate, this, "Zeta::Lifeform");
}

Regeneration* Lifeform::getRegeneration(const std::string& regenerationName) {
	auto itr = regenerations.find(regenerationName);
	if (itr != regenerations.end()) {
		return itr->second;
	}
	return nullptr;
}

void Lifeform::setClass(const LifeformClass& lifeClass) {
	for (auto child : childs) {
		delete child.second;
	}

	childs.clear();
	childsToBeOffseted.clear();

	if (lifeformClass != nullptr) {
		System::getInstance().getResourcesManager().releaseResource(
				*lifeformClass);
	}

	setState(LifeformState::Action::Idle | LifeformState::Direction::Down);

	// Get the stated Lifeform Class from RESCON
	lifeformClass = &lifeClass;

	// Get the level
	level = lifeformClass->getLevel();

	// Remove all attributes
	attributes.clear();

	// Get the new Attributes
	lifeformClass->getStats(attributes);

	// Get the AnimationClass
	animHandler.setAnimationClass(lifeformClass->getAnimationClassName());

	// Get the faction
	faction = &lifeformClass->getFaction();

	// get the Lifeform name
	name = lifeformClass->getLifeformName();

	// Get the AI handlers
	generalAI = lifeformClass->getGeneralBehaviour(*this);
	movementAI = lifeformClass->getMovementBehaviour(*this);

	// Reset all shapes to AnimationClass defaults
	resetShapes();

	// Offset the shapes to the current position
	offsetShapes(position.getX(), position.getY());

	for (auto ab : activeAbilities) {
		delete ab.second;
	}
	activeAbilities.clear();
	for (auto ab : passiveAbilities) {
		delete ab.second;
	}
	passiveAbilities.clear();
	for (auto ab : regenerations) {
		delete ab.second;
	}
	regenerations.clear();

	// get the new Abilities
	lifeformClass->getAbilities(this);

	// get the Childs
	lifeformClass->getChildObjets(this);

	// Get the Lua table
	table = lifeformClass->getTable();

	// TODO: Called from class??? Maybe?
	// Get the onClick Lua Callback
	onClickF = lifeformClass->getOnClick();

	// Get the onCollision Lua Callback
	onCollisionF = lifeformClass->getOnCollision();

	// Finaly start the animations
	animHandler.getMainAnimationPlayer().play();
}

} /* namespace Zeta */
