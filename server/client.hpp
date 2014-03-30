#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <SFML/Network.hpp>


/*
 * classe client
 * gère un client de la connexion à la mort de celui-ci :'(
 *
 */
class Client
{
public:

    typedef enum {
        New,
        In_Game
    } State;

    Client();
    ~Client();

    sf::TcpSocket* getSocket();

    void notify();

private:
    State state;
    sf::TcpSocket* socket;

};

#endif // CLIENT_HPP
