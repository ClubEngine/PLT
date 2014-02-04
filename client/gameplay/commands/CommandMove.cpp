#include "CommandMove.hpp"
#include "../../Log.hpp"

CommandMove::CommandMove(const EntityVector &entities, const sf::Vector2f &target)
	: Command(MOVE), mIds(), mTarget(target)
{
	for(EntityVector::const_iterator it = entities.begin();
		it != entities.end() ; ++it) {
		mIds.push_back((*it).getId());
	}
	
	//LOG(target.x << " " << target.y)
}

void CommandMove::specialPackStep(sf::Packet &packet) const
{
	int size = mIds.size();
	packet << size;
	for (int i = 0; i < size; ++i)
		packet << mIds[i];
	packet << mTarget.x << mTarget.y;		
}

