#include"common.hpp"

namespace advcpp
{
    
inline void Sleep(Nano const& a_nano)
{
    timespec ts = a_nano;
    nanosleep(&ts, 0);
}

inline void Sleep(Second const& a_sec)
{
    timespec ts = a_sec;
    nanosleep(&ts, 0);
}

} // namespace advcpp


