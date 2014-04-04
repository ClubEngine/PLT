#ifndef SOUNDHOLDER_HPP
#define SOUNDHOLDER_HPP

#include <map>
#include <string>

#include <SFML/Audio.hpp>

#include "Sounds.hpp"

namespace engine {

	/** Manage sounds
	  */
	class SoundHolder
	{
		public:
			SoundHolder();
	
			void load(Sounds::ID id, const std::string & filename);
			void play(Sounds::ID id);
	
			virtual ~SoundHolder();
	
		private:
			typedef std::map<Sounds::ID, sf::SoundBuffer *> SoundMap;
			SoundMap mSoundMap;
			sf::Sound masterSound;
			sf::Sound minorSound;
	};

}

#endif // SOUNDHOLDER_HPP
