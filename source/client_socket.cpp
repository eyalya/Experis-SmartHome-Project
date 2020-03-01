#include <unistd.h> // close
#include <stdlib.h> 
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h> 
#include <string.h> //memset
#include <arpa/inet.h> //recv bind accept
#include <errno.h> //errno

#include "socket_exception.hpp"
#include "client_socket.hpp"

namespace advcpp
{
    
ClientSocket::ClientSocket()
: m_socketFd(socket(AF_INET, SOCK_STREAM, 0))
{
    if (m_socketFd < 0)
    {
        throw(SocketException(errno, XINFO));
    }
}

ClientSocket::ClientSocket(int a_socketNum)
: m_socketFd(a_socketNum)
{

}

void ClientSocket::Connect(char const * a_ip, size_t a_port)
{
    struct sockaddr_in servAddr;
    servAddr.sin_family = AF_INET; 
    servAddr.sin_addr.s_addr = inet_addr(a_ip); 
    servAddr.sin_port = htons(a_port);

    if(connect(m_socketFd, (struct sockaddr *)&servAddr, sizeof(servAddr)) < 0) 
    { 
        throw(SocketException(errno, XINFO));
    }
}

} // namespace advcpp
