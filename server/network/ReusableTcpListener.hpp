#ifndef REUSABLETCPLISTENER_HPP
#define REUSABLETCPLISTENER_HPP

#include <SFML/Network.hpp>

namespace Network {

	/** TCP listener which can be reused quickly 
		after application crash/close.
		*/
	class ReusableTcpListener : public sf::TcpListener
	{
		public:
			ReusableTcpListener();
			void reuse();
	};
	
}

#endif // REUSABLETCPLISTENER_HPP
