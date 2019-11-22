#pragma once
#include <SFML/Graphics.hpp>// parent of sf::Sprite
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>

class Background : public sf::Drawable
{
public:
	Background(const sf::Texture& _texture, sf::Vector2f _pos = sf::Vector2f{0.f,0.f});

	void						setPosition(const sf::Vector2f& _position) { m_sprite.setPosition(_position); }
	sf::Vector2f				getPosition() const { return m_sprite.getPosition(); }
	void						setScale(sf::Vector2f _scale) { m_sprite.setScale(_scale); }


	virtual void				draw(sf::RenderTarget& _target, sf::RenderStates _states) const; // override of sf::Drawable::draw()

private: // Private Methods

	void						pApplyTexture(const sf::Texture& _texture) { m_sprite.setTexture(_texture, true); }

private:
	sf::Sprite					m_sprite;
};