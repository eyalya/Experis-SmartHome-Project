#include <cassert>

#include "thread.hpp"
#include "utils.hpp"
namespace advcpp
{
    
Thread::Thread(IRunnable *a_prun) THROW1(ThreadException)
: m_joinable(true)
{
    if(a_prun == 0)
    {
        throw BadParamException("a_prun is null" ,XINFO);
    }

    int errnum = pthread_create(&m_thread, 0, thunk, static_cast<void*>(a_prun));

    if(errnum != 0)
    {
        throw ThreadException(errnum, XINFO);
    }
}

Thread::~Thread() NOEXCEPT
{
    if(m_joinable)
    {
        std::terminate();
    }
}
 
void Thread::Detach() NOEXCEPT
{
    pthread_detach(m_thread);
    m_joinable = false;
}

void Thread::Join(void* a_retVal) THROW1(ThreadException)
{
    int errnum = pthread_join(m_thread, &a_retVal);

    if(errnum != 0)
    {
        throw ThreadException(errnum, XINFO);
    }
    m_joinable = false;
}

void Thread::Cancel() NOEXCEPT
{
    pthread_cancel(m_thread);
}

void Thread::Kill(int a_sig) THROW1(ThreadException)
{
    int errnum = pthread_kill(m_thread, a_sig);

    if(errnum != 0)
    {
        throw ThreadException(errnum, XINFO);
    }
}

void Thread::Yield() THROW1(ThreadException)
{
    int errnum = pthread_yield();

    if(errnum != 0)
    {
        throw ThreadException(errnum, XINFO);
    }
}

void Thread::Exit(void* a_retVal) NOEXCEPT
{
    pthread_exit(a_retVal);
}

void* Thread::thunk(void* a_pctx)
{
    assert(a_pctx != 0);

    IRunnable* r = static_cast<IRunnable*>(a_pctx);

    try
    {
        r->Run();
    }
    catch(const std::exception& e)
    {
        assert(0 != 1);
    }

    return 0;
}

ThreadException::ThreadException(int a_errorNum, Information a_info)
: InformativeException(std::to_string(a_errorNum), a_info)
{
}

BadParamException::BadParamException(std::string const& a_msg, Information a_info)
: InformativeException(a_msg, a_info)
{
}


IRunnable::~IRunnable()
{
}


} // namespace advcpp