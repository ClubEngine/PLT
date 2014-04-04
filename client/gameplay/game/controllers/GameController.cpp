#include "GameController.hpp"

#include <iostream>

GameController::GameController(ControllerHelper & helper)
	: AbstractStateController(helper)
{
	//netInterface.init("localhost", 55001);
	
}

bool GameController::processAuthoritativeMessage()
{
	
//	{
//		sf::Packet packet;
//		bool hasone=false;
//		while (netInterface.getPacket(packet)) {
//			hasone = true;
//			std::cout << "* Receive : ";
//			std::string s;
//			if (packet >> s)
//				std::cout << s;
//			cout << endl;
//			s = "Patate !";
//			packet.clear();
//			packet << s;
//			netInterface.send(packet);
//			netInterface.send(packet);
//			netInterface.send(packet);
//		}
//		if (hasone)
//			std::cout << "end" << endl;
//	}
	
	return false;
}


void GameController::setModel(GameModel &model)
{
	mModel = &model;
}

void GameController::setView(GameView &view)
{
	mView = &view;
}

void GameController::pause()
{
	mHelper.requestStackPush(States::Pause);
}

void GameController::moveUnits(const EntityVector &selectedEntities, const sf::Vector2f &target)
{
	CommandMove command(selectedEntities, target);
	mHelper.sendToAuthoritativeController(command);
}
