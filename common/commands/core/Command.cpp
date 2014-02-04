#include "Command.hpp"

Command::Command() :
	mType(0)
{
}

Command::Command(CommandType type) :
	mType(type)
{
}


Command::Command(sf::Packet &packet)
{
	unpack(packet);
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

void Command::unpack(sf::Packet &packet)
{
	//suppose "COMMAND" and type were already extracted
}

Command::~Command()
{
}
