/*
 * ClassifiedAbility.hpp
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

#ifndef CLASSIFIEDABILITY_HPP_
#define CLASSIFIEDABILITY_HPP_

#include <Zeta/Core/ResourceContext.hpp>
#include <Zeta/Core/RPGClasses/Ability.hpp>
#include <Zeta/Core/System.hpp>

namespace Zeta {

template<typename AbClass>
class ClassifiedAbility: public Ability {
public:
	const AbClass& getClass() const {
		return abilityClass;
	}
	ClassifiedAbility(const AbClass& abilityClass, Lifeform *owner, int level) :
			Ability(owner, level), abilityClass(abilityClass) {

	}
	virtual ~ClassifiedAbility() {
		ResourceContext* resources =
				&System::getInstance().getResourcesManager();
		if (resources != nullptr) {
			resources->releaseResource(abilityClass);
		}
	}
protected:
	const AbClass& abilityClass;
};

} /* namespace Zeta */

#endif /* CLASSIFIEDABILITY_HPP_ */
