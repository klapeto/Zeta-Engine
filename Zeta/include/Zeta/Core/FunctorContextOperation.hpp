/*
 * FunctorContextOperation.hpp
 *
 *  Created on: 17 Σεπ 2014
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

#ifndef FUNCTORCONTEXTOPERATION_HPP_
#define FUNCTORCONTEXTOPERATION_HPP_

#include <Zeta/Core/Context.hpp>
#include <Zeta/Core/ContextOperation.hpp>
#include <functional>

namespace Zeta {

/**
 * Captures a Lambda function and the Context Executes it.
 * The most fast (in terms of code writing) ContextOperation Type
 */
template<typename ContextType>
class FunctorContextOperation: public ContextOperation<ContextType> {
public:

	/**
	 * Calls the lambda function provided
	 * @param context the context that called it.
	 */
	void handle(ContextType& context) {
		func(context);
	}

	/**
	 * Creates a ContextOperation with the lambda function provided
	 * Warning! This is by default deallocated by the Context. Set the toBeDeleted flag
	 * if you want otherwise.
	 * @param func The lambda Function to be executed by the Context
	 * @param toBeDeleted if the Context should deallocate the Operation (Default = true)
	 */
	FunctorContextOperation(std::function<void(ContextType&)> func,
			bool toBeDeleted = true) :
			ContextOperation<ContextType>(toBeDeleted), func(func) {
	}
	~FunctorContextOperation() {

	}
private:
	std::function<void(ContextType&)> func;
};

} /* namespace Zeta */

#endif /* FUNCTORCONTEXTOPERATION_HPP_ */
