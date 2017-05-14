/*
 * Modifier.hpp
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

#ifndef MODIFIER_HPP_
#define MODIFIER_HPP_

#include <Zeta/Core/ZetaConfig.hpp>

namespace Zeta {

/**
 * Abstract Class for creating Attribute Modifiers
 */
class Modifier {
public:

	enum class Type {
		Flat, Scalar
	};

	/**
	 * Gets the order of the Modifier on the Attribute stack
	 * @return The order position or -1 if the Modifier is not assigned to an Attribute
	 */
	int getOrder() const {
		return order;
	}

	/**
	 * Applies the modification to the value
	 * @param value The Value to apply the modification
	 */
	virtual void calculate(AttributeValue &value) const=0;

	Modifier(AttributeValue modValue) :
			modValue(modValue), order(-1) {

	}
	virtual ~Modifier() {

	}
protected:
	AttributeValue modValue;
private:
	int order;

	void setOrder(int order) {
		this->order = order;
	}
	friend class Attribute;
};

} /* namespace Zeta */

#endif /* MODIFIER_HPP_ */
