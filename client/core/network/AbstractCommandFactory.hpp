#ifndef COMMANDFACTORY_HPP
#define COMMANDFACTORY_HPP

#include <list>
#include <SFML/System/NonCopyable.hpp>
#include <SFML/Network.hpp>
#include "Command.hpp"
#include "NetInterface.hpp"

class AbstractCommandFactory : public sf::NonCopyable
{
	public:
		AbstractCommandFactory();
		
		void send(NetInterface & netinterface, const Command & command) const;
		
	protected:
		virtual void prepareToSend(sf::Packet & packet, Command & command) const = 0;
};

#endif // COMMANDFACTORY_HPP
