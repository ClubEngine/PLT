#include "ReusableTcpListener.hpp"

#ifdef SFML_SYSTEM_WINDOWS
    #include <winsock2.h>
#else
    #include <sys/socket.h>
#endif

Network::ReusableTcpListener::ReusableTcpListener() : TcpListener()
{
}

void Network::ReusableTcpListener::reuse()
{
	char reuse = 1;
	setsockopt( getHandle(), SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof( reuse ) );	       
}
