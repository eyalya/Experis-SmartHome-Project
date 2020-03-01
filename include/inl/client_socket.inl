#ifndef CLIENT_SOCKET_INL
#define CLIENT_SOCKET_INL

#include "client_socket.hpp"

namespace advcpp
{ 

template<typename Msg>
size_t ClientSocket::Send(Msg const& a_msg, size_t a_msgLen)
{
    return send(m_socketFd, a_msg, a_msgLen, 0);
}

template<typename Msg>
size_t ClientSocket::Receive(Msg & a_msg, size_t a_maxSize)
{
    return recv(m_socketFd, a_msg, a_maxSize, 0);
}

template<typename Msg>
size_t SendMsg(ClientSocket & a_socket, Msg const& a_msg, size_t a_msgLen)
{
    return a_socket.Send(a_msg, a_msgLen);
}

template<typename Msg>
size_t ReciveMsg(ClientSocket & a_socket, Msg & a_msg, size_t a_maxSize)
{
    return a_socket.Receive(a_msg, a_maxSize);
}

} // namespace advcpp

#endif //CLIENT_SOCKET_INL
