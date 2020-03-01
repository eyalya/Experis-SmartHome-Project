#ifndef CLIENT_SOCKET_HPP
#define CLIENT_SOCKET_HPP

#include "cstddef" //size_t

namespace advcpp
{

class ClientSocket
{
public:
    ClientSocket();
    explicit ClientSocket(int a_socketNum);

    void Connect(char const * a_ip, size_t a_port);

    template<typename Msg>
    size_t Send(Msg const& a_msg, size_t a_msgLen);

    template<typename Msg>
    size_t Receive(Msg & a_msg, size_t a_maxSize);

    // void DisableNigel();

private:
    int m_socketFd;
};

} // namespace advcpp

#include "inl/client_socket.inl"

#endif // !CLIENT_SOCKET_HPP

