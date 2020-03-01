#ifndef SERVER_SOCKET_HPP
#define SERVER_SOCKET_HPP

// #include <arpa/inet.h> /*recv bind accept*/
#include <memory>

#include "socket_exception.hpp"
#include "common.hpp"
#include "client_socket.hpp"

namespace advcpp
{
    
class ServerSocket : private UnCopiable
{
public:
    ServerSocket(const char* a_ip, int a_port, size_t a_Qsize = 1000);
    explicit ServerSocket(int a_socketNum);
    ServerSocket(ServerSocket const& a_other) = delete;
    ~ServerSocket();

    ServerSocket& operator=(ServerSocket const& a_other) = delete;

    std::shared_ptr<ClientSocket> Accept();

    int GetFd();

private:
    void bindPort(const char* a_ip, int a_port);
    void setTolisten(size_t a_Qsize);
    void setReuse();

private:
    int m_socketFd;
};
} // namespace advcpp

#endif //SERVER_SOCKET_HPP