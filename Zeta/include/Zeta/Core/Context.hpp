/*
 * Context.hpp
 *
 *  Created on: 16 Σεπ 2014
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

#ifndef CONTEXT_HPP_
#define CONTEXT_HPP_

#include <Zeta/Core/ContextOperation.hpp>
#include <queue>

namespace Zeta {

/**
 * Template to create Contextes
 * @param ContextType the Context-Derived class to be used
 */
template<typename ContextType>
class Context {
public:

	/**
	 * Pushes a ContextOperation to the contexte's Queue
	 * @param operation The context to be added
	 */
	virtual void addOperationToQueue(ContextOperation<ContextType>& operation) {
		operation.setHandled(false);
		operations.push(&operation);
	}

	/**
	 * Executes all the operations on the Context's Queue
	 * if an Operation should be deallocated, it will be done.
	 * All waiters will be notified when Handled.
	 */
	virtual void executeOperations() {
		while (operations.size() > 0) {
			ContextOperation<ContextType> *operation = operations.front();
			operations.pop();
			operation->handle(*static_cast<ContextType*>(this));
			operation->setHandled(true);
			operation->notifyWaiters();
			if (operation->isToBeDeleted()) {
				delete operation;
			}
		}
	}
	Context() {

	}
	virtual ~Context() {
		executeOperations();
	}
protected:
	std::queue<ContextOperation<ContextType>*> operations;
};

} /* namespace Zeta */

#endif /* CONTEXT_HPP_ */
