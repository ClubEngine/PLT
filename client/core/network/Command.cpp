#include "Command.hpp"

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
	packet << "COMMAND" << getType();
	specialPackStep(packet);
}

Command::~Command()
{
}
