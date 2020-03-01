#ifndef GENERIC_SERVER_HPP
#define GENERIC_SERVER_HPP

#include <list> //std::list
#include <atomic> //std::atomic

#include "server_socket.hpp"

namespace advcpp
{

template<typename Msg>    
class IServerFuncs
{
public:
    virtual ~IServerFuncs() = default;

    // false to deny connection true to accept
    virtual bool NewClientAction(TcpSocket & a_newClient) = 0;

    // false to close connection true to don't change
    virtual bool ProcessData(TcpSocket & a_socket, Msg a_newMsg, size_t a_msgSize) = 0;
    
    virtual void SocketCloseAction(TcpSocket & a_socket) = 0;
};

template<typename Msg>
class TcpServer;                                                                                                                                  

template<typename Msg>    
class ReadFromActive
{
public:
    ReadFromActive(TcpServer<Msg>& a_server);
    bool operator()(size_t a_socket);
private:
    TcpServer<Msg>& m_server;
};


template<typename Msg>
class TcpServer 
{
public:
    TcpServer(IServerFuncs<Msg> & a_serverFuncs, size_t a_numMaxClients,
                    size_t a_QSize, const char* a_ipAdd, int a_portNum, size_t a_maxMsgSize);
    ~TcpServer();

    void Run();

    friend bool ReadFromActive<Msg>::operator()(size_t a_socket);

private:
    ServerSocket m_serverSocket;
    IServerFuncs<Msg>& m_serverFuncs;
    size_t m_maxClients;
    size_t m_clientNum;
    size_t m_activeSockets;
    size_t m_maxMsgSize;
    std::atomic<bool> m_on;

    // std::list<size_t> m_clientSockets;
};

template<typename Msg>    
class ProcessHandler : public IRunnable
{
public:
    ProcessHandler(IServerFuncs<Msg> & a_serverFuncs);

    virtual void Run() noexcept;

private:
    IServerFuncs<Msg> & m_serverFuncs;
    std::shared_ptr<client_socket>m_clientSocket;
};

class ServerException : public InformativeException
{
public:
    ServerException(int a_msgNum, Information const& a_info);
};

} // namespace advcpp

#include "./inl/generic_server.inl"

#endif //GENERIC_SERVER_HPP