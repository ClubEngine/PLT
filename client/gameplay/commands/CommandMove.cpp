#include "CommandMove.hpp"
#include "CommandsType.hpp"
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

