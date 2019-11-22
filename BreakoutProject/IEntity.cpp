#include "IEntity.hpp"

IEntity::IEntity(const sf::Texture& _texture, sf::Vector2f _pos)
{
	this->pApplyTexture(_texture);
	m_sprite.setOrigin(getHalfDimensions());
	this->setPosition(_pos);
	this->pNotifyCollisionBox();
	
}

void IEntity::setPosition(const sf::Vector2f& _pos)
{
	m_sprite.setPosition(_pos);
	pNotifyCollisionBox();
}

void IEntity::offsetPosition(const sf::Vector2f& _offset)
{
	m_sprite.move(_offset);
	pNotifyCollisionBox();
}

const sf::Vector2f& IEntity::getPosition() const
{
	return m_sprite.getPosition();
}

void IEntity::onTick(const sf::Time& _elapsed)
{
	sf::Vector2f tempOffset;
	tempOffset.x = m_pVelocity.x * _elapsed.asSeconds();
	tempOffset.y = m_pVelocity.y * _elapsed.asSeconds();
	offsetPosition(tempOffset);
}

const sf::Vector2f IEntity::getHandlePosition(IEntity::Handle _handle)
{
	sf::Vector2f returnCoord;
	switch (_handle)
	{
	case IEntity::TOP_LEFT:
		returnCoord = getPosition() / 2.f;
		break;
	case IEntity::TOP_CENTER:
		returnCoord.x = getPosition().x; 
		returnCoord.y = getPosition().y - getHalfDimensions().y;
		break;
	case IEntity::TOP_RIGHT:
		returnCoord.x = getPosition().x + getHalfDimensions().x;
		returnCoord.y = getPosition().y - getHalfDimensions().y;
		break;
	case IEntity::MID_LEFT:
		returnCoord.x = getPosition().x - getHalfDimensions().x;
		returnCoord.y = getPosition().y;
		break;
	case IEntity::CENTER:
		returnCoord = getPosition();
		break;
	case IEntity::MID_RIGHT:
		returnCoord.x = getPosition().x + getHalfDimensions().x;
		returnCoord.y = getPosition().y;
		break;
	case IEntity::BOTTOM_LEFT:
		returnCoord.x = getPosition().x - getHalfDimensions().x;
		returnCoord.y = getPosition().y + getHalfDimensions().y;
		break;
	case IEntity::BOTTOM_CENTER:
		returnCoord.x = getPosition().x;
		returnCoord.y = getPosition().y + getHalfDimensions().y;

		break;
	case IEntity::BOTTOM_RIGHT:
		returnCoord = getPosition() + getHalfDimensions();
		break;
	default:
		// should never make it here
		break;
	}

	return returnCoord;
}

const sf::Vector2f& IEntity::getDimensions() const
{
	return sf::Vector2f{ float{m_sprite.getLocalBounds().width}, float{m_sprite.getLocalBounds().height} };
}

const sf::Vector2f IEntity::getHalfDimensions() const
{
	sf::Vector2f halfDimensions;
	halfDimensions.x = getDimensions().x / 2.f;
	halfDimensions.y = getDimensions().y / 2.f;
	return halfDimensions;
}
