#include <ctime>
#include"common.hpp"

namespace advcpp
{

Nano::Nano(size_t a_nano)
: value(a_nano)
{
}

Nano::operator size_t() const
{
    return value;
}        

Nano::operator timespec() const
{ 
    struct timespec ts;

    ts.tv_nsec = value;
    ts.tv_sec = 0;

    return ts;    
}

Second::Second(size_t a_seconds)
: value(a_seconds)
{
}

Second::operator size_t() const
{
    return value;
}        

Second::operator timespec() const
{ 
    struct timespec ts;

    ts.tv_nsec = 0;
    ts.tv_sec = value;

    return ts;    
}

} //namespace advcpp
