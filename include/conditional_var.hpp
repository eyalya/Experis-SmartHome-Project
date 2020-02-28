#ifndef CONDITIONAL_VAR_HPP
#define CONDITIONAL_VAR_HPP

#include <pthread.h> //pthread_cond_t
#include <errno.h>

// #include "locks.hpp" //Mutex
#include "common.hpp" // UnCopyable
#include "informative_exception.hpp"
#include "locks.hpp"

namespace advcpp
{

class CondExcept : public InformativeException
{
public:
    CondExcept(int a_errorNum, Information a_info);
};

class ConditionalVar : private UnCopyable
{
public:
    ConditionalVar() THROW1(CondExcept);
    ~ConditionalVar() NOEXCEPT;

    template<typename Predicate>
    void Wait(Mutex & a_mu, Predicate const& a_pred);
    void Notify() NOEXCEPT;
    void NotifyAll() NOEXCEPT;

private:
    pthread_cond_t m_cond;
};

} // namespace advcpp
#include "./inl/conditional_var.inl"

#endif //CONDITIONAL_VAR_HPP