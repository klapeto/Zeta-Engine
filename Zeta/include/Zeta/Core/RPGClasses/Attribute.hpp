/*
 * Attribute.hpp
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

#ifndef ATTRIBUTE_HPP_
#define ATTRIBUTE_HPP_

#include <Zeta/Core/ZetaConfig.hpp>
#include <set>
#include <list>

namespace Zeta {

class Modifier;

/**
 * Class for handling Lifeform Attributes
 */
class Attribute {
public:

	/**
	 * Calculates the actual value of the Attribute
	 * based on the base value and the modifiers
	 */
	void calculate();

	/**
	 * Adds a modifier at the top
	 * @param mod The modifier to add
	 */
	void addModifier(Modifier *mod);

	/**
	 * Removes the Modifier
	 * \note The modifier is not destructed
	 * @param mod The modifier to remove
	 */
	void removeModifier(Modifier *mod);

	/**
	 * Removes and destroys the Modifier
	 * @param mod The modifier to remove
	 */
	void removeModifierAndDelete(Modifier *mod);

	/**
	 * Gets the Calculated Value
	 * @return The calculated value
	 */
	AttributeValue getValue() const {
		return calculatedValue;
	}

	/**
	 * Gets the base value of the Attribute
	 * @param the Base Value
	 */
	AttributeValue getBaseValue() const {
		return baseValue;
	}

	/**
	 * Adds the value x to the base value and recalculates
	 * the actual value
	 * @param x the Value to add
	 */
	void applyToBaseFlat(AttributeValue x) {
		baseValue += x;
		calculate();
	}

	/**
	 * Multiplies the value x to the base value and recalculates
	 * the actual value
	 * @param x The value to multiply
	 */
	void applyToBaseMul(AttributeValue x) {
		baseValue *= x;
		calculate();
	}

	/**
	 * Sets the base Value and recalculates the actual value
	 * \note Zero values are not allowed and replaced with 1
	 * @param value The value to assign
	 */
	void setBase(AttributeValue value) {
		if (value == 0) {
			this->baseValue = 1;
		} else {
			this->baseValue = value;
		}
		calculate();
	}

	/**
	 * Sets the calculated value
	 * \note This value will be replaces if the calculate() function is called
	 * @param value The value to assign
	 */
	void setCalculatedValue(AttributeValue value) {
		calculatedValue = value;
	}

	/**
	 * Removes all the Modifiers
	 * @param deleteThem If true, the Modifiers will be destroyed too
	 */
	void removeAllModifiers(bool deleteThem);

	/**
	 * Constructs an Attribute with base value 1
	 */
	Attribute() :
			baseValue(1), calculatedValue(1) {

	}

	/**
	 * Constructs an Attribute and assigns the Base value
	 * @param baseValue The base Value to assign
	 */
	Attribute(AttributeValue baseValue) {
		setBase(baseValue);
	}

	Attribute(const Attribute& other);

	Attribute& operator=(const Attribute& other);

	Attribute& operator=(AttributeValue value) {
		setBase(value);
		return *this;
	}

	virtual ~Attribute() {

	}
protected:

	struct ModifierComparator {
		bool operator()(const Modifier* mod1, const Modifier* mod2);
	};

	std::set<Modifier*, ModifierComparator> modifiers;

	AttributeValue baseValue;
	AttributeValue calculatedValue;

	void reapplyOrders();

};

} /* namespace Zeta */

#endif /* ATTRIBUTE_HPP_ */
