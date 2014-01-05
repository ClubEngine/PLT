#ifndef TEXTUREHOLDER_HPP
#define TEXTUREHOLDER_HPP

#include <map>
#include <string>

#include <SFML/Graphics/Texture.hpp>

#include "Textures.hpp"

class TextureHolder
{
	public:
		TextureHolder();
		
		void load(Textures::ID id, const std::string & filename);
		
		sf::Texture & get(Textures::ID id);
		const sf::Texture & get(Textures::ID id) const;
		
        virtual ~TextureHolder();
		
	private:
		typedef std::map<Textures::ID, sf::Texture *> TextureMap;
		TextureMap mTextureMap;
		
		sf::Texture mDefaultTexture;
};

#endif // TEXTUREHOLDER_HPP
