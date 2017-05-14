/*
 * WanderingMovement.cpp
 *
 *  Created on: 16 Ιουλ 2014
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

#include <Zeta/Core/RPGClasses/AI/WanderingMovement.hpp>
#include <Zeta/Core/RPGClasses/Lifeform.hpp>
#include <Zeta/Core/RPGClasses/Object.hpp>
#include <ctime>

namespace Zeta {

// TODO: Custom Idle Action wait Times
WanderingMovement::WanderingMovement(const std::string& action, Lifeform &owner,
		Float minWaitTime, Float maxWaitTime, Float maxDistance) :
		Behaviour(owner), idleAction(action), waitTime(0.0f), actionWaitTime(
				0.0f) {

	if (minWaitTime < maxWaitTime) {
		timeRandomizer = std::uniform_real_distribution<Float>(minWaitTime,
				maxWaitTime);
		actionRandomizer = std::uniform_real_distribution<Float>(minWaitTime,
				maxWaitTime);
	} else {
		timeRandomizer = std::uniform_real_distribution<Float>(1.0f, 4.0f);
		actionRandomizer = std::uniform_real_distribution<Float>(1.0f, 4.0f);
	}
	generator.seed(reinterpret_cast<intptr_t>(this));
	waitTime = timeRandomizer(generator);
	actionWaitTime = actionRandomizer(generator);
	const Vector2& position = owner.getPosition();
	xBounds = std::uniform_int_distribution<int>(
			position.getX() - maxDistance / 2,
			position.getX() + maxDistance / 2);
	yBounds = std::uniform_int_distribution<int>(
			position.getY() - maxDistance / 2,
			position.getY() + maxDistance / 2);

}

WanderingMovement::~WanderingMovement() {

}

void WanderingMovement::update(Float elapsedTime) {
	if (owner->isAlive() && !owner->isMoving() && !owner->isInCombat()) {
		waitTime -= elapsedTime;
		if (owner->isAnimationFinished()) {
			if (waitTime <= 0) {
				waitTime = timeRandomizer(generator);
				owner->moveToPosition(xBounds(generator), yBounds(generator));
			} else if (idleAction.size() > 0) {
				actionWaitTime -= elapsedTime;
				if (actionWaitTime <= 0) {
					actionWaitTime = actionRandomizer(generator);
					owner->setActionAnimation(idleAction);
				} else {
					owner->stopMoving();
				}
			}
		}
	}
}

} /* namespace Zeta */
