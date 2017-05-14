/*
 * AsynchronousWorker.hpp
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

#ifndef ASYNCHRONOUSWORKER_HPP_
#define ASYNCHRONOUSWORKER_HPP_

#include <condition_variable>
#include <mutex>
#include <thread>

namespace Zeta {

/**
 * AsynchronousWorker base class.
 * Used for the derived classes to create objects that
 * execute actions on a unique separate thread.
 */
class AsynchronousWorker {
public:

	/**
	 * \brief Makes the runner thread to call the runCycleOperations()
	 */
	void performCycle() {
		cycle.notify_one();
	}

	/**
	 * \brief Constructs a runner thread
	 */
	AsynchronousWorker() :
			running(true) {
		worker = std::thread(&AsynchronousWorker::loop, this);
	}
	virtual ~AsynchronousWorker() {
		{
			std::lock_guard<std::mutex> lock(mutex);
			running = false;
			cycle.notify_one();
		}
		worker.join();
	}
protected:
	std::mutex mutex;
private:
	std::thread worker;
	std::condition_variable cycle;
	bool running;

	void loop() {
		while (running) {
			std::unique_lock<std::mutex> lock(mutex);
			runCycleOperations();
			cycle.wait(lock);
		}
	}
protected:
	/**
	 * /brief Pure virtual member function to be implemented by derived classes
	 * It should contain any actions that should be executed by the object's runner thread
	 */
	virtual void runCycleOperations()=0;

};

} /* namespace Zeta */

#endif /* ASYNCHRONOUSWORKER_HPP_ */
