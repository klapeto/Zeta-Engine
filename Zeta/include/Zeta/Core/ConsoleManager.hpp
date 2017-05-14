/*
 * ConsoleManager.hpp
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

#ifndef CONSOLEMANAGER_HPP_
#define CONSOLEMANAGER_HPP_

#include <Zeta/Core/LuaPushable.hpp>
#include <Zeta/Core/SingleInstanced.hpp>
#include <string>
#include <Zeta/Core/ZMap.hpp>

namespace Zeta {

/**
 * ConsoleManager. Singleton Class to handle Console commands
 */
class ConsoleManager: public SingleInstanced<ConsoleManager>, public LuaPushable {
public:

	typedef std::string (*Command)(const std::string&);

	/**
	 * Executes the string provided
	 * @param line The string that has the command
	 * @return The commands output
	 */
	std::string excecuteLine(const std::string& line);

	void addCommand(const std::string& name, Command command) {
		commands[name] = command;
	}

	/**
	 * PushToLua Implementation.
	 * Pushes to Lua Stack the Object casted to the appropriate Type
	 * @param lstate the Lua State to push it.
	 */
	void pushToLua(lua_State* lstate);
private:
	ConsoleManager();
	~ConsoleManager();

	ZMap<std::string, Command> commands;
	ZMap<std::string, std::string> commandHelp;

	friend class SingleInstanced;
};

} /* namespace Zeta */

#endif /* CONSOLEMANAGER_HPP_ */