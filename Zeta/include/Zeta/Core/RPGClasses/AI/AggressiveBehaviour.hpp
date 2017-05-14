/*
 * AggressiveBehaviour.hpp
 *
 *  Created on: 3 Οκτ 2014
 *      Author: klapeto
 */

#ifndef AGGRESSIVEBEHAVIOUR_HPP_
#define AGGRESSIVEBEHAVIOUR_HPP_

#include <Zeta/Core/RPGClasses/AI/Behaviour.hpp>
#include <Zeta/Core/UtilityClasses/Vector2.hpp>
#include <Zeta/Core/ZetaConfig.hpp>

namespace Zeta {

class Lifeform;
class ActiveAbility;

class AggressiveBehaviour: public Behaviour {
public:
	void update(Float elapsedTime);
	void onDeath();
	AggressiveBehaviour(Lifeform &owner, Float agroRange = 300,
			Float driftRange = 600);
	virtual ~AggressiveBehaviour();
private:
	enum class State {
		Scanning, Attacking, FallBack, Moving, Casting
	};
	Vector2 initialPosition;
	Lifeform *target;
	ActiveAbility *curAbility;
	Float agroRange;
	Float driftRange;
	State state;

	void scan();
	void attack();
	void getAbility();
};

} /* namespace Zeta */

#endif /* AGGRESSIVEBEHAVIOUR_HPP_ */
