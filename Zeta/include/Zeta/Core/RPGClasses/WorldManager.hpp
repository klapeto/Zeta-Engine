/*
 * WorldManager.hpp
 *
 *  Created on: 17 Μαϊ 2014
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

#ifndef WORLDMANAGER_HPP_
#define WORLDMANAGER_HPP_

#include <Zeta/Core/LuaFunctor.hpp>
#include <Zeta/Core/MapLoader.hpp>
#include <Zeta/Core/RPGClasses/WorldEvent.hpp>
#include <Zeta/Core/RPGClasses/WorldListener.hpp>
#include <Zeta/Core/SingleInstanced.hpp>
#include <Zeta/Core/RPGClasses/Player.hpp>
#include <Zeta/Core/Updateable.hpp>
#include <Zeta/Core/Drawable.hpp>
#include <Zeta/Core/View.hpp>
#include <Zeta/Core/ZetaConfig.hpp>
#include <initializer_list>
#include <Zeta/Core/ZSmallSet.hpp>
#include <Zeta/Core/ZSmallMap.hpp>
#include <string>
#include <vector>

namespace CEGUI {
class Window;
}  // namespace CEGUI

namespace Zeta {

class WorldListener;
class WorldEvent;
class Map;

class WorldManager: public Updateable, public Drawable, public SingleInstanced<
		WorldManager>, public LuaPushable {
public:
	enum class Callback {
		ChangeMap,
		LoadBegin,
		LoadEnd,
		FrameBegin,
		FrameEnd,
		LifeformDeath,
		LifeformShow,
		LifeformHide
	};
	void addListener(WorldListener *listener, WorldEvent::Type eventType);
	void addListener(WorldListener *listener, const std::string& channel);
	void removeListener(WorldListener *listener, WorldEvent::Type eventType);
	void removeListener(WorldListener *listener, const std::string& channel);

	void raiseEvent(const WorldEvent& event);

	void changeMap(const std::string& path);
	void changeMapWithCallback(const std::string& path);

	void setCallback(Callback call, const std::string& name);
	void setCallback(Callback call, lua_Object func);
	const LuaFunctor& getCallback(Callback call) const;

	void callCallback(Callback call, std::initializer_list<LuaPushable*> args);

	void addFrameListener(Updateable* listener);
	void removeFrameListener(Updateable* listener);

	View& getView() {
		return camera;
	}

	void show() {
		visible = true;
	}
	void hide() {
		visible = false;
	}

	bool isVisible() const {
		return visible;
	}

	void pause() {
		running = false;
	}

	void resume() {
		running = true;
	}

	Map& getCurrentMap() {
		return mapLoader.getMap();
	}

	Player& getPlayer() {
		return *player;
	}

	void destroyPlayer();
	void createPlayer();

	void draw(Float x, Float y, Float rotation = 0.0f,
			Float scale = 1.0f) const;
	void update(Float elapsedTime);

	void pushToLua(lua_State* lstate);
	~WorldManager();
private:
	typedef struct {
		WorldListener* listener;
		WorldEvent::Type type;
	} WorldListenerPair;

	typedef struct {
		std::string channel;
		WorldListener* listener;
	} CustomListenerPair;

	typedef ZSmallSet<WorldListener*> ListenerSet;

	ListenerSet eventChannel[10];
	ZSmallMap<std::string, ListenerSet> customChannel;
	ZSmallSet<Updateable*> frameListeners;
	std::vector<Updateable*> frameListenersToBeRemoved;
	std::vector<WorldListenerPair> worldListenersToBeErased;
	std::vector<CustomListenerPair> customListenersToBeErased;

	LuaFunctor callbacks[12];
	MapLoader mapLoader;
	View camera;

	Player *player;

	bool visible;
	bool running;

	WorldManager();

	void getStringCallback(const std::string& name, int &var);
	void getFuncCallBack(lua_Object func, int &var);

	friend class SingleInstanced;
};

} /* namespace Zeta */

#endif /* WORLDMANAGER_HPP_ */
