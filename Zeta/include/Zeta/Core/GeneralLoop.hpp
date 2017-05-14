/*
 * GeneralLoop.hpp
 *
 *  Created on: 5 Αυγ 2015
 *      Author: spiti
 */

/*	This file is Part of Zeta Engine
 *
 *	The MIT License
 *
 * Copyright (c) 2015 Ioannis G. Panagiotopoulos (AKA Klapeto)
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

#ifndef ZETA_CORE_GENERALLOOP_HPP_
#define ZETA_CORE_GENERALLOOP_HPP_

#include <chrono>
#include <list>

namespace Zeta {

class Event;
class Updateable;
class Drawable;
class RenderingContext;
class SystemEventListener;
/**
 * GeneralLoop
 * This class contains all the Items that will be handled by the Loop
 */
class GeneralLoop {
public:
	typedef std::list<Updateable*>::iterator UpdateIndex;
	typedef std::list<Drawable*>::iterator DrawIndex;
	typedef std::list<SystemEventListener*>::iterator ListenerIndex;

	/**
	 * Adds an Item to the Update List on the last slot
	 * @param item The item to add
	 * @return An iterator to the position it was added
	 */
	UpdateIndex addItemToBeUpdated(Updateable* item) {
		if (item != nullptr) {
			updateableItems.push_back(item);

		}
		return updateableItems.end();
	}

	/**
	 * Insert an Item to the Update List on the target
	 * position, pointed by the iterator passed.
	 * @param itr The iterator to insert too
	 * @param item The item to insert
	 * @return  An iterator to the position it was inserted
	 */
	UpdateIndex insertItemToBeUpdated(const UpdateIndex& itr,
			Updateable* item) {
		if (item != nullptr) {
			return updateableItems.insert(itr, item);
		}
		return updateableItems.end();
	}

	/**
	 * Removes a item from the Update List
	 * @param itr The iterator pointing at the item
	 */
	void removeItemToBeUpdated(const UpdateIndex& itr) {
		updateableItems.erase(itr);
	}

	/**
	 * Adds an Item to the Draw List on the last slot
	 * @param item The item to add
	 * @return An iterator to the position it was added
	 */
	DrawIndex addItemToBeDrawn(Drawable* item) {
		if (item != nullptr) {
			drawableItems.push_back(item);
		}
		return drawableItems.end();
	}

	/**
	 * Insert an Item to the Draw List on the target
	 * position, pointed by the iterator passed.
	 * @param itr The iterator to insert too
	 * @param item The item to insert
	 * @return  An iterator to the position it was inserted
	 */
	DrawIndex insertItemToBeDrawn(const DrawIndex& itr, Drawable* item) {
		if (item != nullptr) {
			return drawableItems.insert(itr, item);
		}
		return drawableItems.end();
	}

	/**
	 * Removes a item from the Draw List
	 * @param itr The iterator pointing at the item
	 */
	void removeItemToBeDrawn(const DrawIndex& itr) {
		drawableItems.erase(itr);
	}

	/**
	 * Adds an Item to the Listener List on the last slot
	 * @param item The item to add
	 * @return An iterator to the position it was added
	 */
	ListenerIndex addSystemListener(SystemEventListener* item) {
		if (item != nullptr) {
			eventListeners.push_back(item);
		}
		return eventListeners.end();
	}

	/**
	 * Insert an Item to the Listener List on the target
	 * position, pointed by the iterator passed.
	 * @param itr The iterator to insert too
	 * @param item The item to insert
	 * @return  An iterator to the position it was inserted
	 */
	ListenerIndex insertSystemListener(const ListenerIndex& itr,
			SystemEventListener* item) {
		if (item != nullptr) {
			return eventListeners.insert(itr, item);
		}
		return eventListeners.end();
	}

	/**
	 * Removes a item from the Listener List
	 * @param itr The iterator pointing at the item
	 */
	void removeSystemListener(const ListenerIndex& itr) {
		eventListeners.erase(itr);
	}

	/**
	 * Starts the Loop
	 * \note It has no meaning if called without a LoopRunner
	 */
	void start() {
		running = true;
	}

	/**
	 * Stops the Loop
	 * \note It has no meaning if called without a LoopRunner
	 */
	void stop() {
		running = false;
	}

	/**
	 * Returns if the loop is currently running
	 * @return true if the loop is running
	 */
	inline bool isLoopRunning() const {
		return running;
	}

	/**
	 * Returns the current Frame Rate of the Loop
	 * @return The frame Rate
	 */
	float getCurrentFPS() const {
		return curFps;
	}

	/**
	 * Updates all Items on the Update List
	 */
	void update();

	/**
	 * Draws all the Items on the Draw List
	 */
	void draw();

	/**
	 * Causes all the Items on the Listener List
	 * to handle the event
	 * @param event The event that the Listener will handle
	 */
	void handleEvent(Event& event);

	/**
	 * Constructs a General loop with no items on the list
	 */
	GeneralLoop();
	virtual ~GeneralLoop() {
		running = false;
	}
private:
	typedef std::chrono::duration<float, std::chrono::seconds::period> fpTime;

	std::list<Updateable*> updateableItems;
	std::list<Drawable*> drawableItems;
	std::list<SystemEventListener*> eventListeners;
	std::chrono::high_resolution_clock::time_point ltime;
	RenderingContext* renderingContext;
	float elapsed;
	float curFps;
	bool running;
};

} /* namespace Zeta */

#endif /* ZETA_CORE_GENERALLOOP_HPP_ */
