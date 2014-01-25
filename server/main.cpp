#include <iostream>
#include <list>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>

#include "network/ReusableTcpListener.hpp"

using namespace std;

int main(int argc, char ** argv) {

    cout << endl << "PLT Server " << __DATE__ << " at " << __TIME__ << endl;
	
	bool running = true;
	sf::Time timeout = sf::seconds(1.0f);
		
	// Create a socket to listen to new connections
	Network::ReusableTcpListener listener;
	if (listener.listen(55001) != sf::Socket::Done)
		return 0;
	listener.reuse();
	// Create a list to store the future clients
	std::list<sf::TcpSocket*> clients;
	// Create a selector
	sf::SocketSelector selector;
	// Add the listener to the selector
	selector.add(listener);
	
	// Endless loop that waits for new connections
	while (running)
	{
		// Make the selector wait for data on any socket
		if (selector.wait(timeout))
		{
			std::cout << "Sthg" << endl;
			// Test the listener
			if (selector.isReady(listener))
			{
				// The listener is ready: there is a pending connection
				sf::TcpSocket* clientPtr = new sf::TcpSocket;
				if (listener.accept(*clientPtr) == sf::Socket::Done)
				{
					std::cout << "New client : " << clientPtr->getRemoteAddress() << endl;
					// Add the new client to the clients list
					clients.push_back(clientPtr);
					// Add the new client to the selector so that we will
					// be notified when he sends something
					selector.add(*clientPtr);
				}
				else
				{
					// Error, we won't get a new connection, delete the socket
					delete clientPtr;
				}
			}
			else
			{
				cout << "not the listener. test in " << clients.size() << " client" << endl;
				// The listener socket is not ready, test all other sockets (the clients)
				for (std::list<sf::TcpSocket*>::iterator it = clients.begin(); it != clients.end(); ++it)
				{
					cout << "test socket " << (int*)*it <<endl;
					sf::TcpSocket& client = **it;
					if (selector.isReady(client))
					{
						// The client has sent some data, we can receive it
						sf::Packet packet;
						if (client.receive(packet) == sf::Socket::Done)
						{
							std::cout << "Receive : ";
							std::string s;
							if (packet >> s)
								std::cout << s;
							cout << endl;
							
						} else {
							cout << "Client disconnects : " << client.getRemoteAddress() << endl;
							selector.remove(client);
							delete &client;
							it = clients.erase(it);
						}
					}
				}
			}
		}
	}
	
	

    return 0;
}

