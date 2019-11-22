#include "paddle.hpp"


Paddle::Paddle(const sf::Texture& _texture, sf::Vector2f _pos = sf::Vector2f{0.f, 0.f})
	: IEntity{_texture, _pos}
{
	setVelocity(sf::Vector2f{ 0.f,0.f });
	m_isSticky = true;
}

void Paddle::onTick(const sf::Vector2f& _position)
{
	// Paddle doesn't use elapsed time for its movement when based on mouse position
	setPosition(_position);
}
