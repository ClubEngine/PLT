#include "CommandBuild.hpp"

CommandBuild::CommandBuild(const sf::Vector2i &cordinates, const sf::Int32 &buildingType)
    : Command(CT_BUILD), mCordinates(cordinates), mBuildingType(buildingType)
{

}

CommandBuild::CommandBuild(sf::Packet &packet)
	: Command(CT_BUILD)
{
    packet >> mCordinates.x >> mCordinates.y >> mBuildingType;
}

void CommandBuild::specialPackStep(sf::Packet &packet) const
{
    packet << mCordinates.x << mCordinates.y << mBuildingType;
}

void CommandBuild::specialUnpackStep(sf::Packet &packet)
{
}
