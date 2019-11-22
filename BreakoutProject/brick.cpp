#include "brick.hpp"



Brick::Brick(const sf::Texture& _texture, sf::Vector2f _pos) 
	: IEntity{_texture, _pos}
{
	setVelocity(sf::Vector2f{ 0.f,0.f });
}

void Brick::toggleActivity()
{
	if (m_isActive)
	{
		m_isActive = false;
	}
	else
	{
		m_isActive = true;
	}

}
