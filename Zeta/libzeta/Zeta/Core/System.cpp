/*
 * System.cpp
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

#include <Zeta/Core/GUIManager.hpp>
#include <Zeta/Core/Logger.hpp>
#include <Zeta/Core/LuaEngine.hpp>
#include <Zeta/Core/MainLoop.hpp>
#include <Zeta/Core/RenderingContext.hpp>
#include <Zeta/Core/ResourceContext.hpp>
#include <Zeta/Core/AudioContext.hpp>
#include <Zeta/Core/ShapeRenderer.hpp>
#include <Zeta/Core/MapClasses/Map.hpp>
#include <Zeta/Core/RPGClasses/WorldManager.hpp>
#include <Zeta/Core/SingleInstanced.hpp>
#include <Zeta/Core/System.hpp>
#include <Zeta/Core/XMLSchemaValidator.hpp>
#include <tolua++.h>
#include <cstdlib>

using namespace std;

namespace Zeta {

System* System::instance = nullptr;

System::System(ResourceContext* resManager, RenderingContext* renderingContext,
		AudioContext *audio, ShapeRenderer *renderer) :
		resManager(resManager), renderingContext(renderingContext), audio(
				audio), renderer(renderer) {

	Logger &log = Logger::getInstance();

	log.write("        \\\\_______   _____   _______");
	log.write("       / /____  /  | ____| |__   __|  /\\ ");
	log.write("      ' |/\\\\ / /   | |__      | |    /  \\ ");
	log.write("           \\/ /    |  __|     | |   / /\\ \\ ");
	log.write("           / /__/| | |___     | |  / ____ \\ ");
	log.write("          /_____/  |_____|    |_| / /    \\ \\ ");
	log.write("             `'");
	log.write("           Simple 2-Dimensional ARPG Engine");
	log.write("");

	log.write("===========================================================");
	log.write("Zeta was assigned Rendering/Resource Contextes");
	log.write(
			"Now SDK-Specific operations will occur depending on linkage used");
	log.write("===========================================================");
}

System::~System() {
	shutdown();
}

void System::shutdown() {
	Logger &log = Logger::getInstance();

	WorldManager& wrldMgr = WorldManager::getInstance();

	log.write("======Zeta Engine Shutdown Requested======");\
	wrldMgr.getCurrentMap().nullise();
	wrldMgr.destroyPlayer();

	GUIManager::getInstance().destroyContext();

//	LuaEngine::getInstance().destroyState();

	delete audio;
	audio = nullptr;
	delete resManager;
	resManager = nullptr;
	delete renderingContext;
	renderingContext = nullptr;
	delete renderer;
	renderer = nullptr;

	log.write(
			"Many static allocated Data (eg: Null References) will not be destroyed...");

	log.write(
			"=====================================================================");
	log.write(
			"||-----------------------Zeta Engine Log End-----------------------||");
	log.write(
			"=====================================================================");

	std::exit(EXIT_SUCCESS);
}

void System::abort(const string &error) {
	Logger::getInstance().write(error);
	shutdown();
}

void System::start() {
	MainLoop::getInstance().start();
}

void System::pushToLua(lua_State* lstate) {
	tolua_pushusertype(lstate, this, "Zeta::System");
}

} /* namespace Zeta */
