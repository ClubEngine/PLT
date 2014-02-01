#include "../../Log.hpp"
#include "NetInterface.hpp"


NetInterface::NetInterface() :
	mReady(false),
	mSocket(),
	mListenThread(&NetInterface::run, this),
	mLTcontinue(true),
	mReceiveMutex()
{
}

void NetInterface::init(const std::string &host, unsigned short port)
{
	if (mReady) {
		mSocket.disconnect();
		mReady = false;
	}
	
	if (mSocket.connect(sf::IpAddress(host), port, sf::seconds(TIMEOUT_CONNECT))
		== sf::Socket::Done) {
		mReady = true;
		LOG("NetInterface : connected to server.");
		mListenThread.launch();
	} else {
		LOG("NetInterface : NOT connected to server.");
	}
}

bool NetInterface::getPacket(sf::Packet &packet)
{
	sf::Lock lock(mReceiveMutex);
	if (mReceiveQueue.size() == 0)
		return false;
	packet = mReceiveQueue.front();
	mReceiveQueue.pop();
	return true;
}

void NetInterface::send(sf::Packet &packet)
{
	if (mReady) {
		if (mSocket.send(packet) != sf::Socket::Done) {
			mReady = false;
			mLTcontinue = false;
			mSocket.disconnect();
		}
	}
}



void NetInterface::run()
{
	mLTcontinue = true;
	
	while (mLTcontinue) {
		sf::Packet packet;
		
		sf::Socket::Status status = mSocket.receive(packet);
		
		if (status == sf::Socket::Done) {
			
			sf::Lock lock(mReceiveMutex);
			
			mReceiveQueue.push(packet);
						
			
		} else if (sf::Socket::Disconnected) {
			// cout <<
			mLTcontinue = false;
		} else {
			mLTcontinue = false;
		}
	}
}


NetInterface::~NetInterface()
{
	mLTcontinue = false;
	mSocket.disconnect();
	mListenThread.wait();
}
