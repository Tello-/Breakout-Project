// Entity is an interface for any in game object
// Entity inherits from sf::Drawable and ICollidable
#pragma once

#include "ICollidable.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/System/Time.hpp>

class IEntity : 
	public sf::Drawable, public ICollidable
{
public:

	enum Handle	
	{ 
		TOP_LEFT,    TOP_CENTER,    TOP_RIGHT, 
		MID_LEFT,    CENTER,        MID_RIGHT, 
		BOTTOM_LEFT, BOTTOM_CENTER, BOTTOM_RIGHT

	};
public:

									IEntity() = default;
									IEntity(const sf::Texture& _texture, sf::Vector2f _pos = sf::Vector2f{ 0.f, 0.f });
	virtual							~IEntity() {}
	void							setPosition(const sf::Vector2f&);
	void							offsetPosition(const sf::Vector2f&);
	const sf::Vector2f&				getPosition() const;

	void							setVelocity(const sf::Vector2f& _newVeloc) { m_pVelocity = _newVeloc; }
	const sf::Vector2f&				getVelocity() const { return m_pVelocity; }

	virtual void					onTick(const sf::Time& _elapsed = sf::Time{});
	virtual void					draw(sf::RenderTarget& target, sf::RenderStates states) const { target.draw(m_sprite); }
	virtual const sf::Vector2f		getHandlePosition(IEntity::Handle);
	virtual const sf::Vector2f&		getDimensions() const;
	const sf::Vector2f				getHalfDimensions() const;
	

protected:
	virtual void					pNotifyCollisionBox() { this->m_pCollisionBox.update(this->m_sprite.getGlobalBounds()); }
	virtual void					pApplyTexture(const sf::Texture& _texture) { m_sprite.setTexture(_texture, true); }
	sf::Sprite						m_sprite;
	sf::Vector2f					m_pVelocity;
	

};