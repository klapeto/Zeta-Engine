/*
 * MapLoader.hpp
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

#ifndef MAPLOADER_HPP_
#define MAPLOADER_HPP_

#include <Zeta/Core/ContextOperation.hpp>
#include <Zeta/Core/MapClasses/Map.hpp>
#include <Zeta/Core/RenderingContext.hpp>
#include <mutex>
#include <string>
#include <thread>

namespace Zeta {

class MapLoader {
public:
	bool isReady() {
		std::unique_lock<std::mutex> lock(mutex);
		return ready;
	}

	void setNextMap(const std::string& path) {
		std::unique_lock<std::mutex> lock(mutex);
		nextMap = path;
		ready = false;
	}

	Map& getMap() {
		return map;
	}

	const Map& getMap() const {
		return map;
	}

	void startLoad();

	MapLoader(const MapLoader&) = default;
	MapLoader& operator=(const MapLoader&) = default;

	MapLoader();
	~MapLoader();
private:

	class LoadBeginCall: public ContextOperation<RenderingContext> {
	public:
		void handle(RenderingContext& context);

		LoadBeginCall() :
				ContextOperation<RenderingContext>() {

		}
	};

	class LoadEndCall: public ContextOperation<RenderingContext> {
	public:
		void handle(RenderingContext& context);

		LoadEndCall() :
				ContextOperation<RenderingContext>() {

		}
	};

	Map map;
	std::thread worker;
	std::mutex mutex;
	std::string nextMap;

	LoadBeginCall onBegin;
	LoadEndCall onEnd;

	bool ready;

	void doLoad();
};

} /* namespace Zeta */

#endif /* MAPLOADER_HPP_ */
