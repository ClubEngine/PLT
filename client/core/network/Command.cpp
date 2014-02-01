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

Command::~Command()
{
}
