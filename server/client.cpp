#include "client.hpp"

Client::Client()
    : state(New), socket(new sf::TcpSocket)
{

}

Client::~Client()
{
    delete socket;
}

// getter de la socket associee au client
sf::TcpSocket *Client::getSocket()
{
    return socket;
}

// methode a appeler pour envoyer les infos sur l'etat du jeu
// mis a jour au client
void Client::notify()
{
}
