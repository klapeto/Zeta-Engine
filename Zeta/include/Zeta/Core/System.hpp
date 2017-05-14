/*
 * System.hpp
 *
 *  Created on: 14 Δεκ 2013
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

#ifndef SYSTEM_HPP_
#define SYSTEM_HPP_

#include <Zeta/Core/LuaPushable.hpp>
#include <string>

namespace Zeta {

class ResourceContext;
class RenderingContext;
class AudioContext;
class ShapeRenderer;

/**
 * The main System Class
 * This Singleton Object contains all the main Modules of the Engine
 */
class System: public LuaPushable {
public:

	/**
	 * Causes the Main Loop to start Running
	 */
	void start();

	/**
	 * Returns the assigned RenderingContext
	 * @return The assigned RenderingContext
	 */
	RenderingContext& getRenderingContext() {
		return *renderingContext;
	}

	/**
	 * Returns the assigned ResourceContext
	 * @return The assigned ResourceContext
	 */
	ResourceContext& getResourcesManager() {
		return *resManager;
	}

	/**
	 * Returns the assigned AudioContext
	 * @return The assigned AudioContext
	 */
	AudioContext& getAudioContext() {
		return *audio;
	}

	/**
	 * Returns the assigned ShapeRenderer
	 * @return The assigned ShapeRenderer
	 */
	ShapeRenderer& getShapeRenderer() {
		return *renderer;
	}

	/**
	 * Returns the System Object(Singleton)
	 * @return The System Object
	 */
	static System& getInstance() {
		return *instance;
	}

	/**
	 * Creates the System Object and assigns the Modules defined
	 * The modules will be destroyed by the System when it will shutdown
	 * If there is already a System Object created, the old one will be destroyed
	 * and its modules will be destroyed too.
	 * @param renderingContext The RenderingContext to assign
	 * @param resManager The ResourceContext to assign
	 * @param audio The AudioContext to assign
	 * @param renderer The ShapeRenderer to assign
	 * @return The created Object
	 */
	static System& create(RenderingContext* renderingContext,
			ResourceContext* resManager, AudioContext* audio,
			ShapeRenderer *renderer) {
		if (instance != nullptr) {
			delete instance;
		}
		instance = new System(resManager, renderingContext, audio, renderer);
		return *instance;
	}

	/**
	 * Shutdowns and terminates the execution of the program
	 * All the modules are destroyed and the resources are freed before
	 * termination with exception the static allocated objects.
	 */
	[[ noreturn ]]
	void shutdown(); //---------------------> Once you get in here, there is [[ noreturn ]]

	/**
	 * Shutdowns and terminates the execution of the program writing a message to the Log File
	 * All the modules are destroyed and the resources are freed before
	 * termination with exception the static allocated objects.
	 * The message is written to the LogFile before terminating
	 * @param error The message to write on the Log File
	 */
	[[ noreturn ]]
	void abort(const std::string &error);

	/**
	 * Pushes the Object to the Lua Environment
	 * @param lstate The Lua Environment to push to.
	 */
	void pushToLua(lua_State* lstate);
private:
	System(ResourceContext* resManager, RenderingContext* renderingContext,
			AudioContext *audio, ShapeRenderer *renderer);
	~System();

	ResourceContext* resManager;
	RenderingContext* renderingContext;
	AudioContext* audio;
	ShapeRenderer* renderer;

	static System* instance;
};

} /* namespace Zeta */

#endif /* SYSTEM_HPP_ */
