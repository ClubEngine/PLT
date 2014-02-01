#ifndef NETINTERFACE_HPP
#define NETINTERFACE_HPP

#include <queue>
#include <SFML/Network.hpp>

#define TIMEOUT_CONNECT 2

class NetInterface : public sf::NonCopyable
{
	public:
		NetInterface();
		
		void init(const std::string & host, unsigned short port);
	
		bool getPacket(sf::Packet & packet);
		
		void send(sf::Packet & packet);
		
		~NetInterface();
		
	protected:
		void run();
		
		bool mReady;
		sf::TcpSocket mSocket;
		sf::Thread mListenThread;
		bool mLTcontinue; // control listening thread
		sf::Mutex mReceiveMutex;
		
		typedef std::queue<sf::Packet> PacketQueue;
		PacketQueue mReceiveQueue;
		
};

#endif // NETINTERFACE_HPP
