#ifndef MYCOMMANDFACTORY_HPP
#define MYCOMMANDFACTORY_HPP

#include "../../core/network/AbstractCommandFactory.hpp"

class MyCommandFactory : public AbstractCommandFactory
{
	public:
		MyCommandFactory();
		
	protected:
		virtual void prepareToSend(sf::Packet &packet, Command &command) const;
};

#endif // MYCOMMANDFACTORY_HPP
