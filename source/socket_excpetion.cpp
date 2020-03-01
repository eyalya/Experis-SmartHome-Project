#include "socket_exception.hpp"

namespace advcpp
{
    
SocketException::SocketException(int a_msgNum, Information const& a_info)
: InformativeException(std::to_string(a_msgNum), a_info)
{
}

} // namespace advcpp

