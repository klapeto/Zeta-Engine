/*
 * NullReference.hpp
 *
 *  Created on: 6 Σεπ 2014
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

#ifndef NULLREFERENCE_HPP_
#define NULLREFERENCE_HPP_

#include <type_traits>

namespace Zeta {

/**
 * NullReference Template
 * Template for providing global Null Usuable Objects
 * The template argument is the Class that will construct the NullObject
 */
template<typename type>
class NullReference {
public:
	static_assert(std::is_constructible<type>::value,"NullReferenced was passed a type that has not default constructor");

	/**
	 * Returns the NullObject
	 * @return the Object
	 */
	static type& getNull() {
		static type nullInstance;
		return nullInstance;
	}

	/**
	 * Default Constructor
	 * Does nothing
	 */
	NullReference() {

	}

	/**
	 * Destructor
	 * Does nothing
	 */
	virtual ~NullReference() {

	}
};

} /* namespace Zeta */

#endif /* NULLREFERENCE_HPP_ */
