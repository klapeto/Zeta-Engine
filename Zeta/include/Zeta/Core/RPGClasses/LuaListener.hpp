/*
 * LuaListener.hpp
 *
 *  Created on: 21 Δεκ 2014
 *      Author: klapeto
 */

/*	
 * This file is Part of Zeta
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

#ifndef ZETA_CORE_RPGCLASSES_LUALISTENER_HPP_
#define ZETA_CORE_RPGCLASSES_LUALISTENER_HPP_

#include <Zeta/Core/LuaFunctor.hpp>
#include <Zeta/Core/RPGClasses/WorldEvent.hpp>
#include <Zeta/Core/RPGClasses/WorldListener.hpp>
#include <Zeta/Core/ZetaConfig.hpp>

namespace Zeta {

class LuaListener: public WorldListener, public LuaPushable {
public:
	void acceptEvent(const WorldEvent& event);
	void pushToLua(lua_State *lstate);
	void deactivate();
	void activate();
	LuaListener(lua_Object func, WorldEvent::Type type);
	LuaListener(const std::string& channel, lua_Object func);
	~LuaListener();
private:
	std::string customChannel;
	LuaFunctor callback;
	WorldEvent::Type type;
	bool active;
};

} /* namespace Zeta */

#endif /* ZETA_CORE_RPGCLASSES_LUALISTENER_HPP_ */
