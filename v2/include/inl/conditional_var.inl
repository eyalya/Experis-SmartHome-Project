#ifndef CONDITIONAL_VAR_INL
#define CONDITIONAL_VAR_INL

#include "conditional_var.hpp"

namespace advcpp
{

template<typename Predicate>
void ConditionalVar::Wait(Mutex & a_mutex, Predicate const& a_pred)
{
    while (a_pred())
    {
        int errorNum = pthread_cond_wait(&m_cond, &a_mutex.getLock());
        
        if(errorNum != 0)
        {
            THROW1(CondExcept(errorNum, XINFO));
        }
    }
}


} // namespace advcpp

#endif //CONDITIONAL_VAR_INL
