#include "MyCommandFactory.hpp"
#include "CommandsType.hpp"
#include "CommandMove.hpp"

MyCommandFactory::MyCommandFactory()
{
}

void MyCommandFactory::prepareToSend(sf::Packet &packet, Command &command) const
{
	packet << "COMMAND" << command.getType();
		
	switch(command.getType()) {
	case MOVE:
		CommandMove * move = dynamic_cast<CommandMove*>(&command);
		if (move != 0) {
			packet << move->mTarget.x << move->mTarget.y;
		}
		break;
	}
}
