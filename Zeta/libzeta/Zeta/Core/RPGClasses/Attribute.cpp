/*
 * Attribute.cpp
 *
 *  Created on: 14 Απρ 2014
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

#include <Zeta/Core/RPGClasses/Attribute.hpp>
#include <Zeta/Core/RPGClasses/Modifier.hpp>

namespace Zeta {

void Attribute::calculate() {
	// reset the calculated value
	calculatedValue = baseValue;
	// for all modifiers
	for (auto mod : modifiers) {
		// calculate the value
		mod->calculate(calculatedValue);
	}
}

void Attribute::addModifier(Modifier* mod) {
	// Check if the modifier is real
	if (mod != nullptr) {
		// we have to check if there is any other modifier in the list
		if (modifiers.size() > 0) {
			// if there is, then we need to set order to this one
			// according to the last added on the list
			mod->setOrder((*modifiers.rbegin())->getOrder() + 1);
		} else {
			// If there is none then we are first on the line
			mod->setOrder(1);
		}
		// insert the modifier
		modifiers.insert(mod);
		// check if the first modifier has reached large order number
		// (usually happens when massive amount of Modifiers are applied
		// and removed fast)
		if ((*modifiers.begin())->getOrder() > 100) {
			// sanitize the order numbers to prevent overflows
			reapplyOrders();
		}
	}
	// recalculate
	calculate();
}

void Attribute::removeModifier(Modifier *mod) {
	modifiers.erase(mod);
	calculate();
}

Attribute::Attribute(const Attribute& other) {
	baseValue = other.baseValue;
	calculatedValue = other.calculatedValue;
}

Attribute& Attribute::operator =(const Attribute& other) {
	baseValue = other.baseValue;
	calculatedValue = other.calculatedValue;
	return *this;
}

void Attribute::removeModifierAndDelete(Modifier *mod) {
	delete mod;
	modifiers.erase(mod);
	calculate();
}

void Attribute::removeAllModifiers(bool deleteThem) {
	if (deleteThem) {
		for (auto mod : modifiers) {
			delete mod;
		}
	}
	modifiers.clear();
}

void Attribute::reapplyOrders() {
	int order = 1;
	for (auto mod : modifiers) {
		mod->setOrder(order++);
	}
}

bool Attribute::ModifierComparator::operator ()(const Modifier* mod1,
		const Modifier* mod2) {
	return mod1->getOrder() < mod2->getOrder();
}

} /* namespace Zeta */
