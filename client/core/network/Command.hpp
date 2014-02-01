#ifndef COMMAND_HPP
#define COMMAND_HPP

#include <SFML/System.hpp>

typedef sf::Uint16 CommandType;

class Command
{
	public:
		Command();
		Command(CommandType type);
		
		CommandType getType() const;
		
		virtual ~Command();
	
	protected:
		CommandType mType;
				
};

#endif // COMMAND_HPP
