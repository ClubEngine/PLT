#include "CommandMove.hpp"
//#include "../../Log.hpp"

CommandMove::CommandMove(const EntityVector &entities, const sf::Vector2f &target)
	: Command(MOVE), mIds(), mTarget(target)
{
	for(EntityVector::const_iterator it = entities.begin();
		it != entities.end() ; ++it) {
		mIds.push_back((*it)->getId());
	}
	
	//LOG(target.x << " " << target.y)
}

CommandMove::CommandMove(sf::Packet &packet) : Command(packet)
{
	specialUnpackStep(packet);
}

void CommandMove::specialPackStep(sf::Packet &packet) const
{
	sf::Int32 size = mIds.size();
	packet << size;
	for (int i = 0; i < size; ++i)
		packet << mIds[i];
	packet << mTarget.x << mTarget.y;
}

void CommandMove::specialUnpackStep(sf::Packet &packet)
{
	mIds.clear();
	sf::Int32 size = 0;
	packet >> size;
	mIds.reserve(size);
	EntityId id;
	for (int i = 0; i < size; ++i) {
		packet >> id;
		mIds.push_back(id);
	}
	packet >> mTarget.x >> mTarget.y;
}

