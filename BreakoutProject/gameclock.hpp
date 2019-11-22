#pragma once
#include "SFML/System/Clock.hpp"

class GameClock
{
public:
									GameClock(const float _fps) : m_frameTime{ 1.f / _fps } {}

	const sf::Time&					getElapsed() { return m_elapsedTime; }	
	const float						getFrameTime() { return m_frameTime; }
	void							restartClock() { m_elapsedTime += m_clock.restart(); }
	void							tick() { m_elapsedTime -= sf::seconds(m_frameTime); }
	bool							readyForTick() const { return m_elapsedTime.asSeconds() >= m_frameTime; }
private:
	

	sf::Time						m_elapsedTime;
	float							m_frameTime;
	sf::Clock						m_clock;
};