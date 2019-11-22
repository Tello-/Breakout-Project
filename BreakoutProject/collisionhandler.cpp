//#include "collisionhandler.hpp"
//
//void CollisionHandler::resolveBallBrickCollision(const IEntity* _ball, const IEntity* _brick, sf::Vector2f& _reflectionFactor)
//{
//	
//	CollisionBox::BoundaryID intersectionPoint;
//	if (_ball->getCollisionBox() == _brick->getCollisionBox())
//	{
//		_brick->getCollisionBox().intersectsWith(sf::FloatRect{ _ball->getPosition().x, _ball->getPosition().y,
//			_ball->getDimensions().x, _ball->getDimensions().y }, intersectionPoint);
//		switch (intersectionPoint)
//		{
//		case CollisionBox::LEFT:
//		case CollisionBox::RIGHT:
//			_reflectionFactor = sf::Vector2f{ -1.f, 1.f };
//			break;
//		case CollisionBox::TOP:
//		case CollisionBox::BOTTOM:
//			_reflectionFactor = sf::Vector2f{ 1.f, -1.f };
//			break;
//		default:
//			break;
//		}
//	}
//	
//	
//}
