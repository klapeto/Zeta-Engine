/*
 * ReferenceRequest.hpp
 *
 *  Created on: 11 Μαρ 2016
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

#ifndef ZETA_CORE_MAPCLASSES_REFERENCEREQUEST_HPP_
#define ZETA_CORE_MAPCLASSES_REFERENCEREQUEST_HPP_

#include <Zeta/Core/ContextOperation.hpp>
#include <Zeta/Core/RenderingContext.hpp>
#include <string>

namespace Zeta {

/**
 * Class for requesting from the Main thread to get A lua Reference to lua code
 */
class ReferenceRequest: public ContextOperation<RenderingContext> {
public:

	/**
	 * Gets the Lua Reference
	 * \note The Operation must have been handled before calling this method
	 * @return The lua reference
	 */
	int getReference() const {
		return reference;
	}

	void handle(RenderingContext& context);

	/**
	 * Constructs a ReferenceRequest and assigns the script
	 * @param script The lua script
	 */
	ReferenceRequest(const std::string& script);
private:
	std::string script;
	int reference;
};

} /* namespace Zeta */

#endif /* ZETA_CORE_MAPCLASSES_REFERENCEREQUEST_HPP_ */
