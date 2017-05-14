/*
 * WanderingMovement.hpp
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

#ifndef WANDERINGMOVEMENT_HPP_
#define WANDERINGMOVEMENT_HPP_

#include <Zeta/Core/RPGClasses/AI/Behaviour.hpp>
#include <Zeta/Core/UtilityClasses/Vector2.hpp>
#include <Zeta/Core/ZetaConfig.hpp>
#include <random>

namespace Zeta {

class WanderingMovement: public Behaviour {
public:

	const std::string& getIdleAction() const {
		return idleAction;
	}

	void setIdleAction(const std::string& idleAction) {
		this->idleAction = idleAction;
	}

	void update(Float elapsedTime);

	void onDeath() {

	}
	WanderingMovement(const std::string& action, Lifeform &owner,
			Float minWaitTime = 1.0f, Float maxWaitTime = 4.0f,
			Float maxDistance = 500);
	~WanderingMovement();
private:
	std::string idleAction;
	std::default_random_engine generator;
	std::uniform_real_distribution<Float> timeRandomizer;
	std::uniform_real_distribution<Float> actionRandomizer;
	std::uniform_int_distribution<int> xBounds;
	std::uniform_int_distribution<int> yBounds;

	Float waitTime;
	Float actionWaitTime;
};

} /* namespace Zeta */

#endif /* WANDERINGMOVEMENT_HPP_ */
