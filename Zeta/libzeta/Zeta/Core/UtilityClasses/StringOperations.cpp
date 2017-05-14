/*
 * StringOperations.cpp
 *
 *  Created on: 11 Μαρ 2014
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

#include <Zeta/Core/UtilityClasses/StringOperations.hpp>
#include <ctype.h>

namespace Zeta {

void StringOperations::getTokens(const std::string& value, char delimiter,
		std::list<std::string>& tokenList, char stopOn, bool ignoreSpace) {

	std::string tmpToken;
	if (ignoreSpace) {
		for (auto chr : value) {
			switch (chr) {
			case ' ':
			case '\t':
			case '\n':
			case '\v':
			case '\f':
			case '\r':
				continue;
				break;
			default:
				if (chr == delimiter){
					if (tmpToken.size() > 0) {
						tokenList.push_back(tmpToken);
						tmpToken.clear();
					}
				} else if (chr==stopOn){
					if (tmpToken.size() > 0) {
						tokenList.push_back(tmpToken);
						tmpToken.clear();
					}
					goto Exit_For;
				} else {
					tmpToken.push_back(chr);
				}
				break;
			}
		}
	} else {
		for (auto chr : value) {
			if (chr != delimiter) {
				tmpToken.push_back(chr);
			} else {
				if (tmpToken.size() > 0) {
					tokenList.push_back(tmpToken);
					tmpToken.clear();
				}
			}
		}
	}
	Exit_For: if (tmpToken.size() > 0) {
		tokenList.push_back(tmpToken);
	}
}

std::string StringOperations::translateUnixPath(const std::string& thisPath,
		const std::string& relativePath) {
	std::list<std::string> resourceTokens;
	std::list<std::string> pathTokens;

	// get the Tokens of the Resources path
	getTokens(relativePath, '/', resourceTokens);

	// get the tokens of the caller Resource
	getTokens(thisPath, '/', pathTokens);

	// Drop away the filename of the caller
	pathTokens.pop_back();

	// for all the tokens in the Resource Path
	for (auto itr = resourceTokens.begin(); itr != resourceTokens.end();) {
		// if it is '..'
		if (*itr == "..") {
			// erase the tail path of the caller
			pathTokens.pop_back();
			// erase the token
			itr = resourceTokens.erase(itr);
		} else {
			// if it is not present, get outta here
			break;
		}
	}

	std::string outPath;
	// concat the path tokens
	for (auto& str : pathTokens) {
		outPath += str + '/';
	}

	// concat the resource Tokens
	for (auto& str : resourceTokens) {
		outPath += str + '/';
	}

	// pop back the last '/'
	outPath.pop_back();

	// return the 'Real path'
	return outPath;
}

} /* namespace Zeta */
