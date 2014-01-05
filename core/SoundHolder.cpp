#include "SoundHolder.hpp"

SoundHolder::SoundHolder()
{
}

void SoundHolder::load(Sounds::ID id, const std::string & filename)
{
    sf::SoundBuffer * buf = new sf::SoundBuffer();
    if (buf->loadFromFile(filename))
        mSoundMap[id] = buf;
}

void SoundHolder::play(Sounds::ID id)
{
    SoundMap::iterator it = mSoundMap.find(id);

    // @TODO: problem when a new sound is launched before the end of the last one
    // (work for a SoundManager)
    if (it != mSoundMap.end()) {
        masterSound.setBuffer(*it->second);
        masterSound.play();
    }
}


SoundHolder::~SoundHolder()
{
    for(SoundMap::iterator it = mSoundMap.begin();
        it != mSoundMap.end(); ++it)
        delete it->second;
}
