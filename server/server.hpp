#ifndef SERVER_HPP
#define SERVER_HPP

#include <iostream>
#include <list>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>

#include "network/ReusableTcpListener.hpp"

#include "client.hpp"

//test
#include "../common/commands/gameplay/CommandMove.hpp"
// or
#include "commands/gameplay/CommandMove.hpp"
#include "commands/gameplay/CommandBuild.hpp"

#include "Common.hpp"


// gere tout^^
class Server
{
public:
    Server();
    void run();

private:
    void listenClients();
    void doStepTurn();
    void notifyClients();

    bool running;
    Network::ReusableTcpListener listener;
    std::list<Client*> clients;
    sf::SocketSelector selector;

};

#endif // SERVER_HPP
