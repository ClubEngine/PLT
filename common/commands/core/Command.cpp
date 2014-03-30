#include "Command.hpp"

const std::string Command::PACKET_TYPE = "COMMAND";

Command::Command() :
	mType(0)
{
}

Command::Command(CommandType type) :
	mType(type)
{
}


CommandType Command::getType() const
{
	return mType;
}

void Command::pack(sf::Packet &packet) const
{
	packet << PACKET_TYPE << getType();
	specialPackStep(packet);
}

Command::~Command()
{
}
