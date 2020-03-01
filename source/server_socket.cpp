#include "server_socket.hpp"

#include <errno.h> //errno
#include <unistd.h> // close
#include <stdlib.h> 
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h> 
#include <string.h> //memset
#include <arpa/inet.h> //recv bind accept

namespace advcpp
{

ServerSocket::ServerSocket(const char* a_ip, int a_port, size_t a_Qsize)
: m_socketFd(socket(AF_INET, SOCK_STREAM, 0))
{
    if (m_socketFd < 0)
    {
        throw(SocketException(errno, XINFO));
    }
    bindPort(a_ip, a_port);
    setTolisten(a_Qsize);
    setReuse();
}

ServerSocket::ServerSocket(int a_socketNum)
: m_socketFd(a_socketNum)
{
}

ServerSocket::~ServerSocket()
{
    close(m_socketFd);
}


void ServerSocket::bindPort(const char* a_ip, int a_port)
{
    struct sockaddr_in sin;
	
	memset(&sin, 0, sizeof(sin));
	sin.sin_family = AF_INET;
	sin.sin_addr.s_addr = inet_addr(a_ip);
	sin.sin_port = htons(a_port);
	
	if(bind(m_socketFd, (struct sockaddr*) &sin, sizeof(sin)) < 0)
	{
		throw(SocketException(errno, XINFO));
	}
}

void ServerSocket::setTolisten(size_t a_Qsize)
{
	if(listen(m_socketFd, a_Qsize) < 0)
	{
        throw(SocketException(errno, XINFO));
	}
}

std::shared_ptr<ClientSocket> ServerSocket::Accept()
{
    struct sockaddr_in clientSin;
	int addrLen = sizeof(clientSin);
    int newSocket = accept(m_socketFd, (struct sockaddr*)&clientSin, (socklen_t*)&addrLen);
    if(newSocket < 0)
    {	
		throw(SocketException(errno, XINFO));
	}

    return std::make_shared<ClientSocket>(newSocket);
}

void ServerSocket::setReuse()
{
    int optval = 1;
    if(setsockopt(m_socketFd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval))) 
    {
        throw(SocketException(errno, XINFO));
    }
}

int ServerSocket::GetFd()
{
    return m_socketFd;
}

} // namespace advcpp
