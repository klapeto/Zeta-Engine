/*
 * MainLoop.cpp
 *
 *  Created on: 2 Ιαν 2014
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

#include <tolua++.h>
#include <Zeta/Core/GUIManager.hpp>
#include <Zeta/Core/MainLoop.hpp>
#include <Zeta/Core/RPGClasses/WorldManager.hpp>

namespace Zeta {

void MainLoop::pushToLua(lua_State* lstate) {
	tolua_pushusertype(lstate, this, "Zeta::MainLoop");
}

MainLoop::MainLoop() :
		guiMgr(&GUIManager::getInstance()), worldMgr(
				&WorldManager::getInstance()) {
	start();
	addItemToBeDrawn(worldMgr);
	addItemToBeDrawn(guiMgr);
	addItemToBeUpdated(worldMgr);
	addItemToBeUpdated(guiMgr);
	addSystemListener(guiMgr);
}

} /* namespace Zeta */
