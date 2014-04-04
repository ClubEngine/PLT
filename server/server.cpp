#include "server.hpp"

Server::Server()
    :running(true)
{
    // Create a socket to listen to new connection
    if (listener.listen(COMMON_PORT) != sf::Socket::Done)
        exit(-1);
    listener.reuse();
    // Add the listener to the selector
    selector.add(listener);
}

// server routine
void Server::run()
{
    // Endless loop that waits for new connections
    while (running)
    {
        listenClients();

        doStepTurn();

        notifyClients();
    }
}

// listen the clients changes
void Server::listenClients()
{

    sf::Time timeout = sf::seconds(1.0f);
    // Make the selector wait for data on any socket
    if (selector.wait(timeout))
    {
        std::cout << "Sthg" << std::endl;
        // Test the listener
        if (selector.isReady(listener))
        {
            // The listener is ready: there is a pending connection
            Client* client = new Client;
            if (listener.accept(*(client->getSocket())) == sf::Socket::Done)
            {
                std::cout << "New client : " << client->getSocket()->getRemoteAddress() << std::endl;
                // Add the new client to the clients list
                clients.push_back(client);
                // Add the new client to the selector so that we will
                // be notified when he sends something
                selector.add(*(client->getSocket()));

            }
            else
            {
                // Error, we won't get a new connection, delete the socket
                delete client;
            }
        }
        else
        {
            std::cout << "not the listener. test in " << clients.size() << " client" << std::endl;
            // The listener socket is not ready, test all other sockets (the clients)
            for (std::list<Client*>::iterator it = clients.begin(); it != clients.end(); ++it)
            {
                std::cout << "test socket " << (int*)*it << std::endl;
                Client& client = **it;
                sf::TcpSocket& socketClient = *(client.getSocket());
                if (selector.isReady(socketClient))
                {
                    // The client has sent some data, we can receive it
                    sf::Packet packet;
                    if (socketClient.receive(packet) == sf::Socket::Done)
                    {
						std::string s;
						packet >> s;
						std::cout << s << std::endl;
						packet.clear();
						packet << "HELLO WORLD";
						socketClient.send(packet);

                    }
                    else
                    {
                        std::cout << "Client disconnects : " << socketClient.getRemoteAddress() << std::endl;
                        selector.remove(socketClient);
                        delete &client;
                        it = clients.erase(it);
                    }
                }
            }
        }
    }
}


// compute the next step
void Server::doStepTurn()
{
}


// Notify all clients about the game state
void Server::notifyClients()
{
    for (std::list<Client*>::iterator it = clients.begin(); it != clients.end(); ++it)
    {
        (**it).notify();
    }
}
