#include "brickblock.hpp"

BrickBlock::BrickBlock(Brick _prototypeBrick, const sf::Vector2i& _dimensions)
	: m_prototypeBrick{ _prototypeBrick }, m_dimensions{ _dimensions }, 
	m_brickMatrix{(unsigned)_dimensions.x, std::vector<Brick*>{(unsigned)_dimensions.y, new Brick{_prototypeBrick}}}
{
	
}

void BrickBlock::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (auto col : m_brickMatrix)
	{
		for (auto row : col)
		{
			target.draw(*row);
		}
	}
}

void BrickBlock::initMatrix()
{
	for (int col = 0; col < m_dimensions.x; ++col)
	{
		for (int row = 0; row < m_dimensions.y; ++row)
		{
			m_brickMatrix[col][row]->setPosition(sf::Vector2f{ col * m_prototypeBrick.getDimensions().x, row * m_prototypeBrick.getDimensions().y });
		}
	}
}


