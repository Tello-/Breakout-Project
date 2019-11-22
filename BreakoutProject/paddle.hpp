#pragma once
#include "IEntity.hpp"



class Paddle : public IEntity
{
	
public:
	Paddle() = default;
									Paddle				(const sf::Texture& _texture, sf::Vector2f _pos);
	virtual void					onTick				(const sf::Vector2f& _elapsed);

	bool							isSticky			() const { return m_isSticky; }
	void							setSticky			(bool _state) { m_isSticky = _state; }

private:
	bool							m_isSticky;
};
