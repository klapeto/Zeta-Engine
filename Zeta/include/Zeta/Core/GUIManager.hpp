/*
 * GUIManager.hpp
 *
 *  Created on: 3 Ιαν 2014
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

#ifndef GUIMANAGER_HPP_
#define GUIMANAGER_HPP_

#include <Zeta/Core/SingleInstanced.hpp>
#include <Zeta/Core/Updateable.hpp>
#include <Zeta/Core/Drawable.hpp>
#include <Zeta/Core/SystemEventListener.hpp>
#include <string>

namespace CEGUI {
class GUIContext;
class System;
}  // namespace CEGUI

namespace Zeta {

class Event;

/**
 * Singleton Class to handle the GUI System
 */
class GUIManager: public Updateable,
		public Drawable,
		public SystemEventListener,
		public SingleInstanced<GUIManager> {
public:

	/**
	 * Forward the Event to GUI to handle it
	 * @param event the Event to forward.
	 */
	void handleEvent(Event& event);

	/**
	 * Notifies the GUI that time has passes since last call of this function
	 * @param time the time passed.
	 */
	void update(Float elapsedTime);

	/**
	 * Requests the GUI System to draw on screen
	 */
	void draw(Float x, Float y, Float rotation = 0.0f, Float scale =
			1.0f) const;

	/**
	 * Notifies the GUI that Main Window Size has changed
	 * @param width the New Width
	 * @param height the New Height
	 */
	void displayResized(int width, int height);

	/**
	 * Initializes the GUI with the provided settings file
	 * @param settingsPath the Configuration File
	 */
	void initializeContext(const std::string& settingsPath);
	void destroyContext();
	~GUIManager();
private:
	GUIManager();

	CEGUI::GUIContext *context;
	CEGUI::System *sys;

	friend class SingleInstanced;
};

} /* namespace Zeta */

#endif /* GUIMANAGER_HPP_ */
