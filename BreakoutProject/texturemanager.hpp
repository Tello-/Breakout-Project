#pragma once
#include <unordered_map>
#include <vector>
#include <iostream>
#include <SFML/Graphics/Texture.hpp>



namespace textures
{
	enum TextureID
	{
		PADDLE,
		BRICK,
		STRONG_BRICK,
		INDESTRUCTABLE_BRICK,
		INVISIBLE_BRICK,
		BALL,
		BACKGROUND
	};
	enum ExceptionID
	{
		NO_MATCHING_TEXTURE,
		TEXTURE_STRUCTURE_EMPTY
	};


	 

	class TextureManager
	{
	public:
		
														TextureManager() = default;
														TextureManager(std::vector< std::pair< std::string, textures::TextureID> >);

		bool											registerTexture(std::string, textures::TextureID);
		bool											batchRegisterTexture(std::vector< std::pair< std::string, textures::TextureID> >);
		const sf::Texture&								retrieveTexture(textures::TextureID) const;
	private:

		struct TextureData	{ std::string m_filePath; TextureID	m_textureID; sf::Texture* m_texture; };

		std::unordered_map<TextureID, TextureData*>		m_textureMap;
		
	};
};