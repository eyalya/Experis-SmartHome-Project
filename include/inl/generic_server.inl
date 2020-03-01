#include "generic_serve.hpp"

namespace advcpp
{

template<typename Msg>    
TcpServer<Msg>::TcpServerTcpServer(IServerFuncs<Msg> & a_serverFuncs, size_t a_numMaxClients,
                    size_t a_QSize, const char* a_ipAdd, int a_portNum, size_t a_maxMsgSize)
: m_serverFuncs(a_serverFuncs)
, m_maxClients(a_numMaxClients)
, m_clientNum(0)
, m_maxMsgSize(a_maxMsgSize)
{
}

template<typename Msg>    
TcpServer<Msg>::~TcpServer()
{
}

template<typename Msg>    
void TcpServer<Msg>::Run()
{    
    while (m_on.load())
    {
        auto newClient = m_serverSocket.Accept();

        //TODO: create thread for the new client
    }
}


ServerException::ServerException(int a_msgNum, Information const& a_info)
: InformativeException(std::to_string(a_msgNum), a_info)
{
}
    
} // namespace advcpp
