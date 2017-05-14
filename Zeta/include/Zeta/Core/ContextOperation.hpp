/*
 * ContextOperation.hpp
 *
 *  Created on: 5 Σεπ 2014
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

#ifndef CONTEXTOPERATION_HPP_
#define CONTEXTOPERATION_HPP_

#include <condition_variable>
#include <mutex>

namespace Zeta {

/**
 * Template to create ContextOperations to be handled
 * by "ContextType" contexts
 */
template<typename ContextType>
class ContextOperation {
public:

	/**
	 * Pure virtual member Function to be called by the ContextType
	 * @param context the Context that called it
	 */
	virtual void handle(ContextType& context)=0;


	/**
	 * Get's if the Operation has been Handled.
	 * @return True if it has been Handled
	 */
	bool isHandled() const {
		return handled;
	}

	/**
	 * Sets the Handled Flag.
	 * This call is Thread-Safe. In most cases only a Context should call it.
	 * @param handled the value to be give to the Handled flag
	 */
	void setHandled(bool handled) {
		std::unique_lock<std::mutex> lk(mutex);
		this->handled = handled;
	}

	/**
	 * Get's if the Operation should be deallocated
	 * once it has been Handled.
	 * @return true if it should be deallocated
	 */
	bool isToBeDeleted() const {
		return toBeDeleted;
	}

	/**
	 * Sets if the Operation should be deallocated by the Context
	 * once it is handled.
	 * @param toBeDeleted true or false
	 */
	void setToBeDeleted(bool toBeDeleted) {
		this->toBeDeleted = toBeDeleted;
	}

	/**
	 * Makes the calling thread to wait until the assigned context handles the
	 * Operation.
	 * Warning! This can cause deadlock if both Context and Caller are in the same Thread.
	 * Use only if you know what you are doing.
	 */
	void waitToBeCompleted() {
		std::unique_lock<std::mutex> lk(mutex);
		while (!handled)
			done.wait(lk);
	}

	/**
	 * Notifies all waiters that called waitToBeCompleted() to continue.
	 * This in most cases is called by a context. Calling it with the Handled flag=false
	 * will literally do nothing, except consume system resources. So don't call it from
	 * anywhere else than a context.
	 */
	void notifyWaiters() {
		std::unique_lock<std::mutex> lk(mutex);
		done.notify_all();
	}

	/**
	 * Default constructor
	 * sets the toBeDeleted flag to false.
	 * Best used for Stack objects that will wait for completion.
	 */
	ContextOperation() :
			handled(false), toBeDeleted(false) {

	}

	/**
	 * Constructs an Operation with a specified toBeDeleted flag
	 * The toBeDeleted flag specifies if the Operation should be
	 * deallocated by the Context once handled.
	 * @param toBeDeleted The toBeDeleted Flag to set
	 */
	ContextOperation(bool toBeDeleted) :
			handled(false), toBeDeleted(toBeDeleted) {

	}

	/**
	 * Move Constructor
	 */
	ContextOperation(ContextOperation&&) = default;

	/**
	 * Move assignment operator
	 */
	ContextOperation& operator=(ContextOperation&&) = default;

	virtual ~ContextOperation() {

	}
protected:
	std::mutex mutex;
	std::condition_variable done;
	bool handled;
	bool toBeDeleted;
};

} /* namespace Zeta */

#endif /* CONTEXTOPERATION_HPP_ */
