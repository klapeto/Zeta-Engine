/*
 * AsynchronousRenderingContext.hpp
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

#ifndef ZETA_CAN_USE_ASYNCHRONOUS
#error The usage of Zeta Asynchronous Context Templates is not recommended! Use Zeta Synchronous instead.
#else

#ifndef ASYNCHRONOUSRENDERINGCONTEXT_HPP_
#define ASYNCHRONOUSRENDERINGCONTEXT_HPP_

#include <Zeta/Core/AsynchronousWorker.hpp>
#include <Zeta/Core/Context.hpp>
#include <Zeta/Core/ContextOperation.hpp>
#include <Zeta/Core/Display.hpp>
#include <Zeta/Core/RenderingContext.hpp>
#include <mutex>
#include <queue>
#include <type_traits>

namespace Zeta {

template<typename DispT>
class AsynchronousRenderingContext: public RenderingContext,
		public AsynchronousWorker {
public:
	static_assert(std::is_base_of<Display,DispT>::value,"ERROR: Template Argument for Display in the RenderingContext is not derived form Display Base Class!");

	Display& getDisplay() {
		return *display;
	}

	void addOperationToQueue(ContextOperation<RenderingContext>& operation) {
		std::unique_lock<std::mutex> lock(mutex);
		operations.push(&operation);
		performCycle();
	}

	AsynchronousRenderingContext() :
			AsynchronousWorker(), display(nullptr) {
		performCycle();
	}
	~AsynchronousRenderingContext() {

	}
private:
	DispT *display;
	void runCycleOperations() {
		if (display == nullptr) {
			display = new DispT;
		}
		executeOperations();
	}
};

} /* namespace Zeta */

#endif /* ASYNCHRONOUSRENDERINGCONTEXT_HPP_ */

#endif /* ZETA_CAN_USE_ASYNCHRONOUS */
