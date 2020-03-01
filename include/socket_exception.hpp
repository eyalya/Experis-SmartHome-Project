#ifndef ISOCKET_HPP
#define ISOCKET_HPP

#include "informative_exception.hpp"
#include "common.hpp" //UnCopyable

namespace advcpp
{

class SocketException : public InformativeException
{
public:
    SocketException(int a_msg, Information const& a_info);
};


} // namespace advcpp

#endif //SOCKET_HPP