#include "AbstractCommandFactory.hpp"

AbstractCommandFactory::AbstractCommandFactory()
{
}

void AbstractCommandFactory::send(NetInterface &netinterface, const Command &command) const
{
	sf::Packet packet;
	prepareToSend(packet, command);
	netinterface.send(packet);
}
