/*
 * WanderingMovementClass.hpp
 *
 *  Created on: 3 Οκτ 2014
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

#ifndef WANDERINGMOVEMENTCLASS_HPP_
#define WANDERINGMOVEMENTCLASS_HPP_

#include <Zeta/Core/RPGClasses/AI/BehaviourClass.hpp>
#include <Zeta/Core/ZetaConfig.hpp>
#include <string>

namespace Zeta {

class WanderingMovementClass: public BehaviourClass {
public:

	Behaviour* getNewBehaviour(Lifeform& owner) const;
	WanderingMovementClass(Float minWaitTime, Float maxWaitTime,
			Float maxDistance, const std::string& idleAction = "");
	~WanderingMovementClass();
private:
	std::string idleAction;
	Float minWaitTime;
	Float maxWaitTime;
	Float maxDistance;
};

} /* namespace Zeta */

#endif /* WANDERINGMOVEMENTCLASS_HPP_ */
