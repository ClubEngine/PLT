#include "TextureHolder.hpp"

TextureHolder::TextureHolder()
{
	mDefaultTexture.create(32, 32);
}

void TextureHolder::load(Textures::ID id, const std::string &filename)
{
	sf::Texture * texture = new sf::Texture();
	if (texture->loadFromFile(filename))
		mTextureMap[id] = texture;
}

sf::Texture &TextureHolder::get(Textures::ID id)
{
	TextureMap::iterator it = mTextureMap.find(id);
	
	if (it != mTextureMap.end())
		return *it->second;
	return mDefaultTexture;
}

const sf::Texture &TextureHolder::get(Textures::ID id) const
{
	TextureMap::const_iterator it = mTextureMap.find(id);
	
	if (it != mTextureMap.end())
		return *it->second;
	return mDefaultTexture;
}

TextureHolder::~TextureHolder()
{
	for(TextureMap::iterator it = mTextureMap.begin();
		it != mTextureMap.end(); ++it)
		delete it->second;
}
