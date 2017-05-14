/*
 * LifeformState.hpp
 *
 *  Created on: 29 Δεκ 2015
 *      Author: spiti
 */

#ifndef ZETA_CORE_RPGCLASSES_LIFEFORMSTATE_HPP_
#define ZETA_CORE_RPGCLASSES_LIFEFORMSTATE_HPP_

namespace Zeta {

class LifeformState {
public:
	typedef int CombinedState;

	enum Direction {
		Down = 1, Up, Left, Right
	};
	enum Action {
		Idle = (1 << 4),
		Moving = (2 << 4),
		Dying = (3 << 4),
		Dead = (4 << 4),
		Casting = (5 << 4)
	};

	static const int maxDirectionValue = Right;
	static const int maxActionValue = Casting >> 4;

	void set(int combinedState) {
		if ((combinedState & 0xF) > 0
				&& (combinedState & 0xF) <= Direction::Right) {
			m_direction = (Direction) (combinedState & 0xF);
		}
		if ((combinedState & 0xF0) >= Action::Idle
				&& (combinedState & 0xF0) <= Action::Casting) {
			m_action = (Action) (combinedState & 0xF0);
		}
	}

	CombinedState getCombinedState() const {
		return m_direction | m_action;
	}

	void setAction(Action action) {
		m_action = action;
	}

	void setDirection(Direction direction) {
		m_direction = direction;
	}

	inline Action getAction() const {
		return m_action;
	}

	inline Direction getDirection() const {
		return m_direction;
	}

	void operator=(int combinedState) {
		set(combinedState);
	}

	LifeformState() :
			m_direction(Direction::Down), m_action(Action::Idle) {

	}
	LifeformState(int combinedState) :
			m_direction(Direction::Down), m_action(Action::Idle) {
		set(combinedState);
	}
	LifeformState(const LifeformState&) = default;
	LifeformState(LifeformState&&) = default;
	LifeformState& operator=(const LifeformState&) = default;
	~LifeformState() {

	}
private:
	Direction m_direction;
	Action m_action;
};

} /* namespace Zeta */

#endif /* ZETA_CORE_RPGCLASSES_LIFEFORMSTATE_HPP_ */
