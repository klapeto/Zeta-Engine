/*
 * Logger.cpp
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

#include <Zeta/Core/Logger.hpp>

#include <Zeta/Core/UtilityClasses/Exception.hpp>
#include <tolua++.h>
#include <iomanip>

namespace Zeta {

Logger::Logger() {

	out_File.open("Zeta_Log.log", std::ios_base::out | std::ios::trunc);

	if (!out_File.good()) {
		throw Exception("Logger", "Can't open the output file: Zeta_Log.log");
	}

	out_File.width(2);
	write(
			"======================================================================");
	write(
			"||----------------------Zeta Engine Log Started---------------------||");
	write(
			"======================================================================");
	write(
			"NOTICE: If this Log file does not end with an \"Zeta Engine Log End\" in the end, then something bad happened");
}

void Logger::write(const std::string& message, MessageType type) {
	int i = static_cast<int>(type);
	time_t tim;
	time(&tim);
	tm* time = localtime(&tim);

	if (time != nullptr) {
		stringBuffer.str("");
		stringBuffer << std::setfill('0') << std::setw(2) << time->tm_mday
				<< "/" << std::setfill('0') << std::setw(2) << 1 + time->tm_mon
				<< "/" << 1900 + time->tm_year << " " << std::setfill('0')
				<< std::setw(2) << time->tm_hour << ":" << std::setfill('0')
				<< std::setw(2) << time->tm_min << ":" << std::setfill('0')
				<< std::setw(2) << time->tm_sec << " ";
		if (i < 4) {
			stringBuffer << "[" << types[i] << "]" << "		" << message << "\n";
		} else {
			stringBuffer << types[2] << "	"
					<< "Logger was requested a write of invalid type! The message was: "
					<< message << "\n";
		}
		out_File << stringBuffer.str();
		out_File.flush();
	}

}

Logger::~Logger() {
	write(
			"=====================================================================");
	write(
			"||-----------------------Zeta Engine Log End-----------------------||");
	write(
			"=====================================================================");
	out_File.close();
}

void Logger::pushToLua(lua_State* lstate) {
	tolua_pushusertype(lstate, this, "Zeta::Logger");
}

} /* namespace Zeta */
