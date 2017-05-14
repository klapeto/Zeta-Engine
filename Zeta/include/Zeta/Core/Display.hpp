/*
 * Display.hpp
 *
 *  Created on: 1 Σεπ 2014
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

#ifndef DISPLAY_HPP_
#define DISPLAY_HPP_

#include <Zeta/Core/LuaPushable.hpp>
#include <vector>

namespace Zeta {

/**
 * Display Base class
 * Used to create Library-Specific Wrappers to be used inside the
 * Engine's Core
 */
class Display {
public:

	/**
	 * Resolution Class to pass Display resolutions
	 */
	class Resolution: public LuaPushable {
	public:
		int height;
		int width;
		void pushToLua(lua_State *lstate);
	};

	/**
	 * Get's if the calling thread is the same with the Rendering.
	 * This is used by the ResourceContext to distinguish if the caller thread
	 * can load VRAM Textures.
	 * @return true if the calling thread is the rendering Thread
	 */
	static bool isRenderingThread() {
		return renderingThread;
	}

	/**
	 * Resize overload to accept Resolution Objects
	 * @param res The resolution to resize the Main Window.
	 */
	void resize(const Resolution& res) {
		resize(res.width, res.height);
	}

	/**
	 * Gets the Main Window Width
	 * @return The main window Width;
	 */
	virtual int getWidth() const=0;

	/**
	 * Gets the Main Window Height
	 * @return The main window height;
	 */
	virtual int getHeight() const=0;

	/**
	 * Resizes the Main Window to the specified Dimensions
	 * @param width the target width
	 * @param height the target Height
	 */
	virtual void resize(int width, int height)=0;

	/**
	 * Toggles the Main Window Full-screen Mode
	 * @param value True for Fullscreen
	 */
	virtual void setFullScreen(bool value)=0;

	/**
	 * Gets the available Resolutions for this Display
	 * @return A std::vector<Zeta::Display::Resoultion> contain all Resolutions
	 */
	virtual std::vector<Resolution> getAvailableResolutions() const=0;

	/**
	 * Switches the framebuffer.
	 * It should be used on Double or Triple Buffering implementations
	 */
	virtual void switchFramebuffer()=0;

	/**
	 * No Copy Constructor
	 */
	Display(const Display&) = delete;

	/**
	 * No Copy Assignment operator
	 */
	Display& operator=(const Display&) = delete;

	/**
	 * Move Constructor
	 */
	Display(Display&&) = default;

	/**
	 * Move assignment operator
	 */
	Display& operator=(Display&&) = default;


	/**
	 * Creates a Display.
	 * Created displays set the Thread-Specific flag renderingThread to true.
	 */
	Display() {
		renderingThread = true;
	}
	virtual ~Display() {

	}
private:
	static thread_local bool renderingThread;
};

} /* namespace Zeta */

#endif /* DISPLAY_HPP_ */
