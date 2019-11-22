#include "collisionbox.hpp"
 
 void CollisionBox::intersectsWith(const sf::FloatRect& _subject, CollisionBox::BoundaryID& _returnID) const
{
	// Create temp sf::FloatRect to represent the bound currently in question
	// Initialize tempFloatRectBound{left, top, width, height}

	sf::FloatRect tempLeftBound{ m_box.left, m_box.top, 1.f, m_box.height }; // left boundary created
	if (_subject.intersects(tempLeftBound))
		_returnID = CollisionBox::BoundaryID::LEFT;

	sf::FloatRect tempTopBound{ m_box.left, m_box.top, m_box.width, 1.f };
	if (_subject.intersects(tempTopBound))
		_returnID = CollisionBox::BoundaryID::TOP;

	sf::FloatRect tempRightBound{ m_box.left + m_box.width, m_box.top, 1.f, m_box.height };
	if (_subject.intersects(tempRightBound))
		_returnID = CollisionBox::BoundaryID::RIGHT;

	sf::FloatRect tempBottomBound{ m_box.left, m_box.top + m_box.height, m_box.width, 1.f };
	if (_subject.intersects(tempBottomBound))
		_returnID = CollisionBox::BoundaryID::BOTTOM;


}
