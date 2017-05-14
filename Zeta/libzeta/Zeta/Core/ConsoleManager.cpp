/*
 * ConsoleManager.cpp
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
#include <Zeta/Core/ConsoleManager.hpp>
#include <tolua++.h>
#include <utility>

namespace Zeta {

ConsoleManager::ConsoleManager() {
	commands.reserve(20);
	commandHelp.reserve(5);
	commands["/exit"] = ConsoleFunctions::exit;
	commands["/echo"] = ConsoleFunctions::echo;
//	commands["/teleport"] = ConsoleFunctions::teleport;
//	commands["/cast"] = ConsoleFunctions::useAbility;
//	commands["/toggleBounds"] = ConsoleFunctions::toggleBoundBoxes;
//	commands["/setBoundPos"] = ConsoleFunctions::setBoundPosition;
//	commands["/setBoundSize"] = ConsoleFunctions::setBoundSize;
//	commands["/offsetBound"] = ConsoleFunctions::offsetBound;
//	commands["/reloadScript"] = ConsoleFunctions::reloadScript;
}

void ConsoleManager::pushToLua(lua_State* lstate) {
	tolua_pushusertype(lstate, this, "Zeta::ConsoleManager");
}

ConsoleManager::~ConsoleManager() {

}

std::string ConsoleManager::excecuteLine(const std::string& line) {
	if (line.size() > 0) {
		unsigned int x = line.find(' ');
		std::string name = line.substr(0, x);
		auto cmd = commands.find(name);
		if (cmd != commands.end()) {
			if (x < line.size()) {
				std::string args = line.substr(x + 1);
				return (cmd->second)(args);
			} else {
				return (cmd->second)("");
			}
		} else {
			return "Σφάλμα Εντολής: Η εντολή \"" + name
					+ "\" δεν υπάρχει. Πληκτρολογίστε \"/help\" για να εμφανίσετε μια λίστα εντολών.";
		}
	}
	return "Σφάλμα Εντολής: Δεν δόθηκε Εντολή.";
}

} /* namespace Zeta */
