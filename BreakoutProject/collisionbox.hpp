#pragma once
#include "SFML/Graphics/Drawable.hpp"
class CollisionBox
{
public:

	enum BoundaryID{LEFT, TOP, RIGHT, BOTTOM};

public:
	CollisionBox() {}
	
	void update(const sf::FloatRect _newBoundState) { m_box = _newBoundState; }
	void intersectsWith(const sf::FloatRect&, CollisionBox::BoundaryID&) const;


	bool operator==(const CollisionBox& _rhs) const { return this->m_box.intersects(_rhs.m_box); }
private:
	sf::FloatRect m_box;
};

// TODO: Calc Top Bound
// TODO: Calc Left Bound
// TODO: Calc Right Bound
// TODO: Calc Bottom Bound
