/*
 * MapLoader.cpp
 *
 *  Created on: 6 Σεπ 2014
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

#include <Zeta/Core/Logger.hpp>
#include <Zeta/Core/MapLoader.hpp>
#include <Zeta/Core/RPGClasses/WorldManager.hpp>
#include <Zeta/Core/UtilityClasses/Exception.hpp>
#include <Zeta/Core/LuaEngine.hpp>
#include <Zeta/Core/System.hpp>

namespace Zeta {

MapLoader::MapLoader() :
		ready(false) {

}

MapLoader::~MapLoader() {
	if (worker.joinable()) {
		worker.join();
	}
}

void MapLoader::startLoad() {
	if (worker.joinable()) {
		worker.join();
	}
	worker = std::thread(&MapLoader::doLoad, this);
}

void MapLoader::doLoad() {

	std::lock_guard<std::mutex> lk(mutex);

	RenderingContext& render = System::getInstance().getRenderingContext();
	render.addOperationToQueue(onBegin);
	onBegin.waitToBeCompleted();
	try {
		Logger::getInstance().write(
				"=====Started Loading Map: " + nextMap + "=====");
		map.load(nextMap);
		Logger::getInstance().write("=====Map Loading Ended=====");
	} catch (Exception& ex) {
		Logger::getInstance().write(
				"During Loading Map: " + nextMap + " Reason: " + ex.reason(),
				Logger::MessageType::Error);
		map.nullise();
	}
	render.addOperationToQueue(onEnd);
	onEnd.waitToBeCompleted();
	ready = true;
}

void MapLoader::LoadBeginCall::handle(RenderingContext& context) {
	WorldManager::getInstance().callCallback(WorldManager::Callback::LoadBegin,
			{ });
}

void MapLoader::LoadEndCall::handle(RenderingContext& context) {
	WorldManager::getInstance().callCallback(WorldManager::Callback::LoadEnd,
			{ });
	LuaEngine::getInstance().performGarbageCollection();
}

} /* namespace Zeta */
