/*
 * Logger.hpp
 *
 *  Created on: 25 Φεβ 2014
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

#ifndef LOGGER_HPP_
#define LOGGER_HPP_

#include <Zeta/Core/SingleInstanced.hpp>
#include <Zeta/Core/LuaPushable.hpp>
#include <fstream>
#include <sstream>
#include <string>

namespace Zeta {

/**
 * Singleton Class to provide with a Logger
 * Logs to a file with Time stamps
 */
class Logger: public SingleInstanced<Logger>, LuaPushable {
public:

	enum class MessageType {
		Info, Warning, Error, LuaError
	};

	/**
	 * PushToLua Implementation.
	 * Pushes to Lua Stack the Object casted to the appropriate Type
	 * @param lstate the Lua State to push it.
	 */
	void pushToLua(lua_State *lstate);

	/**
	 * Writes to Log File the Message with a time Stamp
	 * The message is assigned a type from the provided one
	 * @param message The message to write
	 * @param type the Message type
	 */
	void write(const std::string& message,
			MessageType type = MessageType::Info);

	Logger();
	~Logger();
private:
	std::ofstream out_File;
	std::ostringstream stringBuffer;
	std::string types[4] = { "Info", "Warning", "CoreError", "LuaError" };
};

} /* namespace Zeta */

#endif /* LOGGER_HPP_ */
