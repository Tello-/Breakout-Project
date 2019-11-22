#include "texturemanager.hpp"

textures::TextureManager::TextureManager(std::vector< std::pair< std::string, textures::TextureID> > _batch)
{
	batchRegisterTexture(_batch);
}

bool textures::TextureManager::registerTexture(std::string _filePath, textures::TextureID _textureID)
{
	sf::Texture* tempTexturePtr = new sf::Texture;

	if (!tempTexturePtr->loadFromFile(_filePath))
	{
		std::cerr << "Failed to load texture from filepath: " << _filePath << std::endl;
		return false;
	}

	TextureData* newTextureDataPtr = new TextureData{ _filePath, _textureID, tempTexturePtr };

	m_textureMap.insert({ _textureID, newTextureDataPtr });

	return true;
}

bool textures::TextureManager::batchRegisterTexture(std::vector< std::pair< std::string, textures::TextureID> > _batch)
{
	for (auto pair : _batch)
	{
		registerTexture(pair.first, pair.second);
	}
	return true;
}

const sf::Texture& textures::TextureManager::retrieveTexture(textures::TextureID _textureID) const
{
	if (m_textureMap.empty())
	{
		throw ExceptionID::TEXTURE_STRUCTURE_EMPTY;
	}
	else if (m_textureMap.find(_textureID) == m_textureMap.end())
	{
		throw ExceptionID::NO_MATCHING_TEXTURE;
	}
	else
	{
		auto foundTextureData = m_textureMap.find(_textureID);
		return *(foundTextureData->second->m_texture);
	}

}
