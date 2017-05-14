/*
 * LoopRunner.hpp
 *
 *  Created on: 17 Δεκ 2013
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

#ifndef LOOPRUNNER_HPP_
#define LOOPRUNNER_HPP_

namespace Zeta {

class GeneralLoop;
class Event;

/**
 * LoopRunner abstract class to write Library-Specific Wrappers
 */
class LoopRunner {
public:

	/**
	 * Causes the Main Loop to start
	 */
	virtual void start()=0;

	/**
	 * Gets the Loops target FPS
	 * Warning this is not the Current Engine's FPS
	 * @return the target FPS
	 */
	virtual int getTargetFps() const=0;

	/**
	 * Sets the Loops target FPS
	 * Warning this is not the Current Engine's FPS
	 * @param targetFps the target FPS
	 */
	virtual void setTargetFps(int targetFps)=0;

	/**
	 * Sets the Loop Implementation Object to run
	 * @param loop The Loop to run
	 */
	void setLoop(GeneralLoop* loop) {
		this->loop = loop;
	}

	/**
	 * Gets the Loop Object that runs
	 * @return The loop object assigned
	 */
	GeneralLoop* getLoop() const {
		return loop;
	}

	/**
	 * Constructs a LoopRunner with no Loop assigned
	 */
	LoopRunner() :
			loop(nullptr) {

	}
	virtual ~LoopRunner() {

	}
private:
	GeneralLoop *loop;
protected:

	/**
	 * Causes the Loop Object to render everything it should render
	 */
	void render();

	/**
	 * Causes the Loop Object to update everything it should update
	 */
	void update();

	/**
	 * Causes the Loop Object to handle the system Event
	 * @param event The event to handle
	 */
	void handleEvents(Event& event);

	/**
	 * Gets if the Loop Object must be running
	 * As soon this function returns true, the Loop must run
	 * @return true if the Loop must continue running
	 */
	bool isLoopRunning();
};

} /* namespace Zeta */

#endif /* LOOPRUNNER_HPP_ */
