#include "background.hpp"

Background::Background(const sf::Texture& _texture, sf::Vector2f _pos)
{
	pApplyTexture(_texture);
	setPosition(_pos);
}

void Background::draw(sf::RenderTarget& _target, sf::RenderStates _states) const
{
	_target.draw(m_sprite);
	return;
}