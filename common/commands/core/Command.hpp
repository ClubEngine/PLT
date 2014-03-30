#ifndef COMMAND_HPP
#define COMMAND_HPP

#include <SFML/System.hpp>
#include <SFML/Network/Packet.hpp>

typedef sf::Uint16 CommandType;

class Command
{
	public:
		const static std::string PACKET_TYPE;
		
		
		Command();
		Command(CommandType type);
		// {"COMMAND" <CommandType>} must be extracted
		Command(CommandType type, sf::Packet &packet);
		
		CommandType getType() const;
		
		// serialize the command into the packet
		// format: {"COMMAND" <CommandType> args...}
		void pack(sf::Packet & packet) const;
		
		virtual ~Command();
		
	protected:
		virtual void specialPackStep(sf::Packet & packet) const = 0;
		
		CommandType mType;
};



#endif // COMMAND_HPP