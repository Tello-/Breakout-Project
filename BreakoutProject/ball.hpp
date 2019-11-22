#pragma once
#include "IEntity.hpp"


class Ball : public IEntity
{
public:
	Ball(const sf::Texture& _texture, sf::Vector2f _pos = sf::Vector2f{ 0.f, 0.f })
		: IEntity{ _texture, _pos } {}
	//virtual void onTick(const sf::Time& _elapsed);
};