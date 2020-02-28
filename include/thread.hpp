#ifndef THREAD_HPP
#define THREAD_HPP

#include <pthread.h> //pthread_t
#include <signal.h>
#include <string>

#include "common.hpp" //Uncopyable
#include "informative_exception.hpp" //InformativeException

namespace advcpp
{
class ThreadException :  public InformativeException
{
public:
    ThreadException(int a_errorNum, Information a_info);
};

class BadParamException : public InformativeException
{
public:
    BadParamException(std::string const& a_msg, Information a_info);
};

class IRunnable
{
public:
    virtual ~IRunnable() = default;
    virtual void Run() NOEXCEPT = 0;
};

class Thread : private UnCopyable 
{
public:
    Thread(IRunnable *a_prun) THROW1(ThreadException);
    ~Thread() NOEXCEPT;
    void Detach() NOEXCEPT;
    void Join(void* a_retVal = 0) THROW1(ThreadException);
    // void TryJoin(timeOut);
    void Cancel() NOEXCEPT;
    void Kill(int a_sig = SIGINT) THROW1(ThreadException);
    static void Yield() THROW1(ThreadException);
    static void Exit(void* a_retVal = 0) NOEXCEPT;

private:
    static void* thunk(void* a_pctx);

private:
    pthread_t m_thread;
    bool m_joinable;
};

} // namespace advcpp
#endif //THREAD_HPP