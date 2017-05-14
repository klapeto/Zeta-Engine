/*
 * LifeformClassContainer.cpp
 *
 *  Created on: 28 Νοε 2014
 *      Author: klapeto
 */

/*	
 * This file is Part of Zeta
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

#include <Zeta/Core/ResourceContext.hpp>
#include <Zeta/Core/RPGClasses/LifeformClass.hpp>
#include <Zeta/Core/RPGClasses/LifeformClassContainer.hpp>
#include <Zeta/Core/System.hpp>

namespace Zeta {

LifeformClassContainer::LifeformClassContainer(const std::string& path) {
	lfClass =
			const_cast<LifeformClass*>(&System::getInstance().getResourcesManager().getLifeformClass(
					path));
}

LifeformClassContainer::~LifeformClassContainer() {
	System::getInstance().getResourcesManager().releaseResource(*lfClass);
}

} /* namespace Zeta */
