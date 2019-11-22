#pragma once
#include "IEntity.hpp"



class Brick : public IEntity
{

public:
									Brick(const sf::Texture& _texture, sf::Vector2f _pos = sf::Vector2f{0.f, 0.f});

	void							toggleActivity();
	bool							isActive() const { return m_isActive;}

private: 

	bool							m_isActive{ true };
	
};