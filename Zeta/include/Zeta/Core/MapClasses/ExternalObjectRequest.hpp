/*
 * ExternalObjectRequest.hpp
 *
 *  Created on: 13 Δεκ 2014
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

#ifndef ZETA_CORE_MAPCLASSES_EXTERNALOBJECTREQUEST_HPP_
#define ZETA_CORE_MAPCLASSES_EXTERNALOBJECTREQUEST_HPP_

#include <Zeta/Core/ContextOperation.hpp>
#include <Zeta/Core/RenderingContext.hpp>
#include <Zeta/Core/ZetaConfig.hpp>
#include <string>
#include <vector>

namespace Zeta {

class Object;

/**
 * Class for loading Objects on the Main Thread
 */
class ExternalObjectRequest: public ContextOperation<RenderingContext> {
public:

	struct ObjectSource {
		std::string module;
		Float spawnX;
		Float spawnY;
		enum class ObjectType {
			Field, Enemy, Npc
		} type;
	};

	/**
	 * Gets the Loaded objects
	 * \note Do not call this before the Operation was handled
	 * @return The loaded objects
	 */
	std::vector<Object*>& getObjects() {
		return objects;
	}

	void handle(RenderingContext& context);

	/**
	 * Constructs a Load Request from the list provided
	 * @param objecClasses The Object list to load
	 */
	ExternalObjectRequest(const std::vector<ObjectSource>& objectClasses);
	~ExternalObjectRequest();
private:
	const std::vector<ObjectSource> *objectClasses;
	std::vector<Object*> objects;
	void getEnemy(lua_State* lstate, Float x, Float y);
	void getNpc(lua_State* lstate, Float x, Float y);
};

} /* namespace Zeta */

#endif /* ZETA_CORE_MAPCLASSES_EXTERNALOBJECTREQUEST_HPP_ */
