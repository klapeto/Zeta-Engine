/*
 * GUIManager.cpp
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

#include <Zeta/Core/Event.hpp>
#include <Zeta/Core/GUIManager.hpp>
#include <Zeta/Core/Logger.hpp>
#include <Zeta/Core/LuaEngine.hpp>
#include <Zeta/Core/RPGClasses/WorldManager.hpp>
#include <Zeta/Core/View.hpp>
#include <Zeta/Core/ZetaConfig.hpp>
#include <Zeta/Core/System.hpp>
#include <CEGUI/InputEvent.h>
#include <CEGUI/GUIContext.h>
#include <CEGUI/RendererModules/OpenGL/GLRenderer.h>
#include <CEGUI/ScriptModules/Lua/ScriptModule.h>
#include <CEGUI/Exceptions.h>
#include <CEGUI/Size.h>
#include <CEGUI/System.h>

namespace Zeta {

GUIManager::GUIManager() :
		context(nullptr), sys(nullptr) {
}

GUIManager::~GUIManager() {
	destroyContext();
}

void GUIManager::update(Float elapsedTime) {
	if (context)
		context->injectTimePulse(elapsedTime);
	if (sys)
		sys->injectTimePulse(elapsedTime);

}

void GUIManager::draw(Float x, Float y, Float rotation, Float scale) const {
	if (sys)
		sys->renderAllGUIContexts();
}

void GUIManager::handleEvent(Event& event) {
	if (context) {
		switch (event.type) {
		case EventType::Mouse_Move:
			context->injectMousePosition(event.mouse.x, event.mouse.y);
			if (event.mouse.wheel != 0) {
				context->injectMouseWheelChange(event.mouse.wheel);
			}
			break;
		case EventType::Mouse_Button_Down:
			context->injectMouseButtonDown(
					static_cast<CEGUI::MouseButton>(event.mouse.button));
			break;
		case EventType::Mouse_Button_Up:
			context->injectMouseButtonUp(
					static_cast<CEGUI::MouseButton>(event.mouse.button));
			break;
		case EventType::Keyboard_Char_Pressed:
			if (event.keyboard.unichar >= 32) {
				context->injectChar(event.keyboard.unichar);
			}
			break;
		case EventType::Keyboard_Key_Down:
			context->injectKeyDown(
					static_cast<CEGUI::Key::Scan>(event.keyboard.key));
			break;
		case EventType::Keyboard_Key_Up:
			context->injectKeyUp(
					static_cast<CEGUI::Key::Scan>(event.keyboard.key));
			break;
		default:
			break;
		}
	}
}

void GUIManager::initializeContext(const std::string& settingsPath) {
	if (sys != nullptr || context != nullptr) {
		CEGUI::System::destroy();
	}
	try {
		sys = &CEGUI::System::create(CEGUI::OpenGLRenderer::create(), nullptr,
				nullptr, nullptr, nullptr, settingsPath);
	} catch (CEGUI::Exception& ex) {
		Logger::getInstance().write(
				" CEGUI threw an Exception at " + std::string(__FUNCTION__)
						+ ": " + std::string(ex.getName().c_str())
						+ " \n\tFile: " + std::string(ex.getFileName().c_str())
						+ " \n\tFunction: "
						+ std::string(ex.getFunctionName().c_str())
						+ " \n\tLine: " + std::to_string(ex.getLine())
						+ " \n\tMessage: "
						+ std::string(ex.getMessage().c_str()));
		if (sys == nullptr) {
			System::getInstance().abort(
					"CEGUI Failed to be created! Aborting Excecution!");
		}
	}

	context = &sys->getDefaultGUIContext();

	CEGUI::LuaScriptModule* module = &CEGUI::LuaScriptModule::create(
			LuaEngine::getInstance().getState());
	module->createBindings();
	sys->setScriptingModule(module);
}

void GUIManager::displayResized(int width, int height) {
	CEGUI::System::getSingleton().notifyDisplaySizeChanged(
			CEGUI::Sizef(width, height));
	WorldManager::getInstance().getView().resize(width, height);
}

void GUIManager::destroyContext() {
	CEGUI::System::destroy();
	Logger::getInstance().write("CEGUI Has been destroyed!");
	sys = nullptr;
	context = nullptr;
}

} /* namespace Zeta */

