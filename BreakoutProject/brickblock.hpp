#pragma once
#include <vector>
/* Brick Block is a class for formatting groups of Brick objects.*/



#include "SFML/Graphics.hpp"
#include "brick.hpp"


class BrickBlock : public sf::Drawable
{

public:
	BrickBlock() = default;
	BrickBlock(Brick, const sf::Vector2i&);

	

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

private:

	void initMatrix();

	Brick	m_prototypeBrick;
	sf::Vector2i m_dimensions;
	
	std::vector<std::vector<Brick*>> m_brickMatrix;


	
};