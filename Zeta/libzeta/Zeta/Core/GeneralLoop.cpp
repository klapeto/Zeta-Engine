/*
 * GeneralLoop.cpp
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

#include <CEGUI/Exceptions.h>
#include <CEGUI/String.h>
#include <Zeta/Core/Drawable.hpp>
#include <Zeta/Core/GeneralLoop.hpp>
#include <Zeta/Core/Logger.hpp>
#include <Zeta/Core/SingleInstanced.hpp>
#include <Zeta/Core/RenderingContext.hpp>
#include <Zeta/Core/SystemEventListener.hpp>
#include <Zeta/Core/System.hpp>
#include <Zeta/Core/Display.hpp>
#include <Zeta/Core/Updateable.hpp>
#include <Zeta/Core/UtilityClasses/Exception.hpp>
#include <string>

namespace Zeta {

void GeneralLoop::update() {
	// Get the current Time point
	auto begin = std::chrono::high_resolution_clock::now();

	// get The difference between the Last Time and now
	elapsed = fpTime(begin - ltime).count();

	// For all the items on the Update List
	for (auto updateable : updateableItems) {

		try {
			// try and update the item
			updateable->update(elapsed);
		} catch (Exception& ex) {
			// If Zeta related excpetion happened, report it
			Logger::getInstance().write(
					"Zeta::GeneralLoop::update Threw an Exception:"
							+ std::string(ex.what()) + "-- Reason: "
							+ ex.reason());
		} catch (CEGUI::Exception& e) {
			// If CEGUI related excpetion happened, report it
			Logger::getInstance().write(
					" CEGUI threw an Exception at Zeta::GeneralLoop::update: "
							+ std::string(e.getName().c_str()) + " \n\tFile: "
							+ std::string(e.getFileName().c_str())
							+ " \n\tFunction: "
							+ std::string(e.getFunctionName().c_str())
							+ " \n\tLine: " + std::to_string(e.getLine())
							+ " \n\tMessage: "
							+ std::string(e.getMessage().c_str()));
		} catch (...) {
			// If anything else happened, report it too!
			Logger::getInstance().write(
					"Zeta::GeneralLoop::update Threw an Unknown Exception");
		}
	}

	// Calculate the Frame Rate
	curFps = 1.0f / elapsed;

	// Set the new Last Time to be the now
	ltime = begin;
}

void GeneralLoop::draw() {
	// For all the Items on the Draw List
	for (auto drawable : drawableItems) {
		// Draw with no offsets
		drawable->draw(0.0f, 0.0f);
	}
	// Execute any operations on the RenderingContext
	renderingContext->executeOperations();
	// Flip the Framebuffer
	renderingContext->getDisplay().switchFramebuffer();
}

void GeneralLoop::handleEvent(Event& event) {
	// For all the Items on the Listener List
	for (auto listener : eventListeners) {
		try {
			// Try and handle the event
			listener->handleEvent(event);
		} catch (Exception& ex) {
			// If Zeta related excpetion happened, report it
			Logger::getInstance().write(
					"Zeta::GeneralLoop::update Threw an Exception:"
							+ std::string(ex.what()) + "-- Reason: "
							+ ex.reason());
		} catch (CEGUI::Exception& e) {
			// If CEGUI related excpetion happened, report it
			Logger::getInstance().write(
					" CEGUI threw an Exception at Zeta::GeneralLoop::update: "
							+ std::string(e.getName().c_str()) + " \n\tFile: "
							+ std::string(e.getFileName().c_str())
							+ " \n\tFunction: "
							+ std::string(e.getFunctionName().c_str())
							+ " \n\tLine: " + std::to_string(e.getLine())
							+ " \n\tMessage: "
							+ std::string(e.getMessage().c_str()));
		} catch (...) {
			// If anything else happened, report it too!
			Logger::getInstance().write(
					"Zeta::GeneralLoop::update Threw an Unknown Exception");
		}
	}
}

GeneralLoop::GeneralLoop() :
		renderingContext(&System::getInstance().getRenderingContext()), elapsed(
				0.0f), curFps(0.0f), running(false) {
	// Initialize the Last Time to be now!
	ltime = std::chrono::high_resolution_clock::now();
}

} /* namespace Zeta */
