/*
 * SynchronousRenderingContext.hpp
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

#ifndef SYNCHRONOUSRENDERINGCONTEXT_HPP_
#define SYNCHRONOUSRENDERINGCONTEXT_HPP_

#include <Zeta/Core/Context.hpp>
#include <Zeta/Core/ContextOperation.hpp>
#include <Zeta/Core/Display.hpp>
#include <Zeta/Core/RenderingContext.hpp>
#include <queue>

namespace Zeta {

/**
 * Template for creating Synchronous Rendering Contexts
 * The Synchronous Contexts are the ones that run on the same thread they are created
 * The template parameter is the Class that will create the Display Object
 */
template<typename DisplayT>
class SynchronousRenderingContext: public RenderingContext {
public:

	/**
	 * Returns the Contexts Display object
	 * @returns The display Object
	 */
	Display& getDisplay() {
		return display;
	}

	/**
	 * Adds the Operation to the Queue for execution
	 * @param operation The operation to add
	 */
	void addOperationToQueue(ContextOperation<RenderingContext>& operation) {
		std::lock_guard<std::mutex> lock(mutex);
		Context::addOperationToQueue(operation);
	}

	/**
	 * Executes all the operations that are on the Queue
	 */
	void executeOperations() {
		std::lock_guard<std::mutex> lock(mutex);
		Context::executeOperations();
	}

	/**
	 * Default Constructor
	 * Upon Creation, the Class will create a Object defined by the Template Argument
	 */
	SynchronousRenderingContext() :
			RenderingContext() {

	}

	/**
	 * Destructor
	 * Upon destruction, the Display Object is destroyed too
	 */
	~SynchronousRenderingContext() {

	}
private:
	std::mutex mutex;
	DisplayT display;
};

} /* namespace Zeta */

#endif /* SYNCHRONOUSRENDERINGCONTEXT_HPP_ */
