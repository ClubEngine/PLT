#ifndef COMMAND_HPP
#define COMMAND_HPP

#include <SFML/System.hpp>
#include <SFML/Network/Packet.hpp>

typedef sf::Uint16 CommandType;

class Command
{
	public:
		Command();
		Command(CommandType type);
		Command(sf::Packet & packet);
		
		CommandType getType() const;
		
		void pack(sf::Packet & packet) const;
		
		virtual ~Command();
	
	protected:
		void unpack(sf::Packet & packet);
		
		virtual void specialPackStep(sf::Packet & packet) const = 0;
		
		CommandType mType;
				
};

#endif // COMMAND_HPP
