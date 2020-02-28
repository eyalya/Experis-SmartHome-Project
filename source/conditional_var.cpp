#include "utils.hpp" //NumToString
#include "conditional_var.hpp"
#include "locks.hpp"

namespace advcpp
{

ConditionalVar::ConditionalVar() THROW1(CondExcept)
{
    int errorNum;
    size_t tryTimes = 5;
    do
    {
        errorNum = pthread_cond_init(&m_cond, 0);
    } while (errorNum == EAGAIN && --tryTimes > 0);
    
    if(errorNum != 0)
    {
        THROW1(CondExcept(errorNum, XINFO));
    }
}

ConditionalVar::~ConditionalVar() NOEXCEPT
{
    pthread_cond_destroy(&m_cond);
}

void ConditionalVar::Notify() NOEXCEPT
{
    pthread_cond_signal(&m_cond);
}

void ConditionalVar::NotifyAll() NOEXCEPT
{
    pthread_cond_broadcast(&m_cond);
}

CondExcept::CondExcept(int a_errorNum, Information a_info)
: InformativeException(NumToString(a_errorNum), a_info)
{
}

} // namespace advcpp
#include "inl/conditional_var.inl"
