#ifndef COMMANDFACTORY_HPP
#define COMMANDFACTORY_HPP

#include <list>
#include <SFML/System/NonCopyable.hpp>
#include <SFML/Network.hpp>
#include "Command.hpp"

class CommandFactory : public sf::NonCopyable
{
	public:
		CommandFactory();
		
		void prepareToSend(sf::Packet & packet, const Command & command) const;
		//Command * receive(sf::Packet & packet);
		
		//~CommandFactory();
		
	private:
		//typedef std::list<Command *> CommandList;
		
		//CommandList mGarbage;
};

#endif // COMMANDFACTORY_HPP
