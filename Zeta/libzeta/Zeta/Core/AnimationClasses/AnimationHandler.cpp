/*
 * AnimationHandler.cpp
 *
 *  Created on: 28 Φεβ 2014
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

#include <Zeta/Core/AnimationClasses/Animation.hpp>
#include <Zeta/Core/AnimationClasses/AnimationHandler.hpp>
#include <Zeta/Core/AnimationClasses/AnimationPlayer.hpp>
#include <Zeta/Core/NullReference.hpp>
#include <Zeta/Core/ResourceClasses/AnimationPack.hpp>
#include <Zeta/Core/ResourceContext.hpp>
#include <Zeta/Core/System.hpp>
#include <tolua++.h>
#include <utility>

namespace Zeta {

AnimationHandler::AnimationHandler() :
		animClass(&NullReference<AnimationClass>::getNull()), releaseResources(
				true) {
	// Set the NullAnimation to the main (if a animation with name "null" exist, then hehehehe)
	mainAnimation.setAnimation(animClass->getAnimation("null"));
}

AnimationHandler::AnimationHandler(const AnimationClass& animClass) :
		animClass(&animClass), releaseResources(true) {
	// Set the default main Animation
	mainAnimation.setAnimation(
			this->animClass->getAnimation(
					LifeformState::Action::Idle
							| LifeformState::Direction::Down));
}

AnimationHandler::AnimationHandler(const std::string& classPath,
		const std::string& animation) :
		releaseResources(true) {
	// Get the AnimationClass from the ResourcesContainer
	animClass = &System::getInstance().getResourcesManager().getAnimationClass(
			classPath);
	// Set the main Animation from the one provided
	mainAnimation.setAnimation(animClass->getAnimation(animation));
}

void AnimationHandler::setAnimation(const std::string& name,
		LifeformState::CombinedState nonExist) {
	// Set the animation provided
	mainAnimation.setAnimation(animClass->getAnimation(name, nonExist));
}

void AnimationHandler::setAnimation(LifeformState::CombinedState name) {
	// Set the animation provided
	mainAnimation.setAnimation(animClass->getAnimation(name));
}

void AnimationHandler::update(Float elapsedTime) {
	// Update the main Animation
	mainAnimation.update(elapsedTime);

	// for all the front Animations
	for (auto itr = frontalAnimations.begin(); itr != frontalAnimations.end();
			) {
		// Update the Animation
		itr->second.update(elapsedTime);
		// Check if it is still playing
		if (itr->second.isPlaying()) {
			// If it is still playing, then get the next one
			++itr;
		} else {
			// if it does not playing, then remove it, since it is over
			itr = frontalAnimations.erase(itr);
		}
	}
	// for all the front Animations
	for (auto itr = backAnimations.begin(); itr != backAnimations.end();) {
		// Update the Animation
		itr->second.update(elapsedTime);
		// Check if it is still playing
		if (itr->second.isPlaying()) {
			// If it is still playing, then get the next one
			++itr;
		} else {
			// if it does not playing, then remove it, since it is over
			itr = backAnimations.erase(itr);
		}
	}
}

void AnimationHandler::draw(Float x, Float y, Float rotation,
		Float scale) const {
	// For all the back animations
	for (auto itr = backAnimations.begin(); itr != backAnimations.end();
			++itr) {
		// Draw the animation
		itr->second.draw(x, y, rotation, scale);
	}
	// Draw the main animation
	mainAnimation.draw(x, y, rotation, scale);
	// For all the front animations
	for (auto itr = frontalAnimations.begin(); itr != frontalAnimations.end();
			++itr) {
		// Draw the animation
		itr->second.draw(x, y, rotation, scale);
	}
}

void AnimationHandler::setAnimationClass(const AnimationClass& animClass) {
	// Set the class
	this->animClass = &animClass;
	// Set the default main Animation
	mainAnimation.setAnimation(
			this->animClass->getAnimation(
					LifeformState::Action::Idle
							| LifeformState::Direction::Down));
}

void AnimationHandler::setAnimationClass(const std::string& path) {
	// Get the resources Context
	auto& resCon = System::getInstance().getResourcesManager();
	// Check if we should release the AnimationClass we already have
	if (releaseResources) {
		// If we should, then release it
		resCon.releaseResource(*animClass);
	}
	// Get the AnimationClass from the ResourcesContext
	this->animClass = &resCon.getAnimationClass(path);
	// Set the default main Animation
	mainAnimation.setAnimation(
			this->animClass->getAnimation(
					LifeformState::Action::Idle
							| LifeformState::Direction::Down));
}

OffAnimation& AnimationHandler::getOffAnimation(const std::string& name,
		QueuePlace queue) {
	// Get a pointer to a map
	ZSmallMap<std::string, OffAnimation>* map;
	// Check which queue we should get from and assign the appropriate
	// map to the pointer
	if (queue == QueuePlace::Front) {
		map = &frontalAnimations;
	} else {
		map = &backAnimations;
	}
	// Search the map for the named Animation
	auto itr = map->find(name);
	// Check if we found it
	if (itr != map->end()) {
		// If we found it, return the OffAnimation that has that name
		return itr->second;
	} else {
		// If we haven't find it, then return a NullAnimation
		return NullReference<OffAnimation>::getNull();
	}
}

AnimationHandler::~AnimationHandler() {
	// Check if we should release the AnimationClass
	if (releaseResources) {
		// If we should, then get the ResourcesContext
		ResourceContext* resources =
				&System::getInstance().getResourcesManager();
		// Check if the ResCON exists (it will probably not exist if the engine shuts down)
		if (resources != nullptr) {
			// If it exists then release the AnimationClass
			resources->releaseResource(*animClass);
		}
	}
}

void AnimationHandler::pushToLua(lua_State* lstate) {
	tolua_pushusertype(lstate, this, "Zeta::AnimationHandler");
}

void AnimationHandler::addOffAnimation(const Animation& animation, Float dx,
		Float dy, QueuePlace queue) {
	// Construct an Empty OffAnimation
	OffAnimation anim;
	// Set the Animation of the OffAnimation
	anim.setAnimation(animation);
	// Set the offsets
	anim.setOffsets(dx, dy);

	// Check which queue we should add it
	switch (queue) {
	case QueuePlace::Front:
		frontalAnimations[animation.getName()] = std::move(anim);
		break;
	case QueuePlace::Back:
		backAnimations[animation.getName()] = std::move(anim);
		break;
	}
}

} /* namespace Zeta */
