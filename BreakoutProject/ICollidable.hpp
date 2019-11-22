#pragma once
#include "collisionbox.hpp"

class ICollidable
{
public:
		
	virtual						~ICollidable() {}
	const CollisionBox&			getCollisionBox() const { return m_pCollisionBox; }
protected:
	virtual void				pNotifyCollisionBox() = 0;
	CollisionBox				m_pCollisionBox;
};