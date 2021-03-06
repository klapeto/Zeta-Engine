/*
 * SeekingProjectile.hpp
 *
 *  Created on: 23 Ιουλ 2014
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

#ifndef SEEKINGPROJECTILE_HPP_
#define SEEKINGPROJECTILE_HPP_

#include <Zeta/Core/RPGClasses/Projectile.hpp>
#include <Zeta/Core/ZetaConfig.hpp>

namespace Zeta {

class SeekingProjectile: public Projectile {
public:
	void onCollidedWith(Object *other);
	void resetState();
	void setTarget(Lifeform* target) {
		this->target = target;
	}
	void pushToLua(lua_State* lstate);
	SeekingProjectile(const ProjectileClass *cls, ActiveAbility *parent,
			Float x, Float y);
	~SeekingProjectile();
private:
	Lifeform *target;
	bool destinationReached;
	void move(Float elapsedTime);
};

} /* namespace Zeta */

#endif /* SEEKINGPROJECTILE_HPP_ */
