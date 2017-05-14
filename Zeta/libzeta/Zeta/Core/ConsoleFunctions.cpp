/*
 * ConsoleFunctions.cpp
 *
 *  Created on: 7 Ιαν 2014
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

#include <Zeta/Core/ConsoleFunctions.hpp>
#include <Zeta/Core/Logger.hpp>
#include <Zeta/Core/LuaEngine.hpp>
#include <Zeta/Core/RPGClasses/Ability.hpp>
#include <Zeta/Core/RPGClasses/Player.hpp>
#include <Zeta/Core/RPGClasses/WorldManager.hpp>
#include <Zeta/Core/System.hpp>
#include <Zeta/Core/UtilityClasses/Exception.hpp>
#include <Zeta/Core/UtilityClasses/Rectangle.hpp>
#include <Zeta/Core/UtilityClasses/Vector2.hpp>
#include <Zeta/Core/UtilityClasses/StringOperations.hpp>
#include <cstdlib>
#include <list>

namespace Zeta {

std::string ConsoleFunctions::exit(const std::string &args) {
	System::getInstance().abort("Termination Forced from Terminal");
	return "";
}

std::string ConsoleFunctions::echo(const std::string& args) {
	return args;
}

std::string ConsoleFunctions::teleport(const std::string& args) {

	if (WorldManager::getInstance().isVisible()) {
		std::list<std::string> tokens;
		StringOperations::getTokens(args, ',', tokens);

		if (tokens.size() == 2) {
			auto itr = tokens.begin();
			int x = strtol((*itr++).data(), nullptr, 0);
			int y = strtol((*itr--).data(), nullptr, 0);
			Player &plyr = WorldManager::getInstance().getPlayer();
			plyr.teleportToCordinates(x, y);
			return plyr.getName() + " teleported to: " + (*itr++) + "," + (*itr);
		} else {
			return "Invalid arguments for /teleport! The format is: /teleport x,y";
		}
	} else {
		return "Invalid arguments for /teleport! The format is: /teleport x,y";
	}

}

std::string ConsoleFunctions::useAbility(const std::string& args) {
	if (WorldManager::getInstance().getPlayer().invokeAbility(args) == Ability::Result::Success) {
		return "Success";
	} else {
		return "Fail";
	}
}

std::string ConsoleFunctions::toggleBoundBoxes(const std::string& args) {
	bool& val = ConsoleFunctions::getInstance().boundsShown;
	val = !val;
	return "Bounds draw is now: " + std::to_string(val);
}

std::string ConsoleFunctions::setBoundPosition(const std::string& args) {

	if (WorldManager::getInstance().isVisible()) {
		std::list<std::string> tokens;
		StringOperations::getTokens(args, ',', tokens);

		if (tokens.size() == 2) {
			Player &plyr = WorldManager::getInstance().getPlayer();
			Rectangle &bound = plyr.getBounding();
			auto itr = tokens.begin();
			int x = strtol((*itr++).data(), nullptr, 0);
			int y = strtol((*itr--).data(), nullptr, 0);
			bound.setPosition(x, y);
			bound.offsetPosition(plyr.getPosition().getX(),
					plyr.getPosition().getY());
			return plyr.getName() + " Bound Position set to: "
					+ std::to_string(bound.getPosition().getX()) + ","
					+ std::to_string(bound.getPosition().getY());
		} else {
			return "Invalid number of arguments for /setboundpos! You must define x and y args!";
		}
	} else {
		return "Map is not visible. You must be in a loaded/new game to use this function.";
	}

}

std::string ConsoleFunctions::setBoundSize(const std::string& args) {

	if (WorldManager::getInstance().isVisible()) {
		std::list<std::string> tokens;
		StringOperations::getTokens(args, ',', tokens);

		if (tokens.size() == 2) {
			Player &plyr = WorldManager::getInstance().getPlayer();
			Rectangle &bound = plyr.getBounding();
			auto itr = tokens.begin();
			int width = strtol((*itr++).data(), nullptr, 0);
			int height = strtol((*itr--).data(), nullptr, 0);
			bound.setSize(width, height);
			return plyr.getName() + " Bound size set to: "
					+ std::to_string(bound.getWidth()) + ","
					+ std::to_string(bound.getHeight());
		} else {
			return "Invalid number of arguments for /setboundsize! You must define x and y args!";
		}
	} else {
		return "Map is not visible. You must be in a loaded/new game to use this function.";
	}
}

std::string ConsoleFunctions::offsetBound(const std::string& args) {
	if (WorldManager::getInstance().isVisible()) {
		std::list<std::string> tokens;
		StringOperations::getTokens(args, ',', tokens);

		if (tokens.size() == 2) {
			Player &plyr = WorldManager::getInstance().getPlayer();
			Rectangle &bound = plyr.getBounding();
			auto itr = tokens.begin();
			int offx = strtol((*itr++).data(), nullptr, 0);
			int offy = strtol((*itr--).data(), nullptr, 0);
			bound.offsetPosition(offx, offy);
			return plyr.getName() + " Bound Position offseted to: "
					+ std::to_string(bound.getPosition().getX()) + ","
					+ std::to_string(bound.getPosition().getY());
		} else {
			return "Invalid number of arguments for /offsetbound! You must define x and y args!";
		}
	} else {
		return "Map is not visible. You must be in a loaded/new game to use this function.";
	}
}

std::string ConsoleFunctions::reloadScript(const std::string& args) {
	std::list<std::string> tokens;
	StringOperations::getTokens(args, ',', tokens);

	if (tokens.size() > 0) {
		std::string name = *tokens.begin();
		try {
			LuaEngine::getInstance().excecuteScriptFile(name, true);
		} catch (Exception &ex) {
			Logger::getInstance().write(
					"During reloading the script" + name + " Reason: "
							+ ex.reason(),
							Logger::MessageType::LuaError);
			return "ERROR! During reloading the script" + name + " Reason: "
					+ ex.reason();
		}
		return name + " Script successfully reloaded!";
	} else {
		return "reloadScript: You must define the fileName!";
	}
}

} /* namespace Zeta */
