#include "mu_test.h"
#include <iostream> //cout
#include <memory> //shared_ptr
#include <unistd.h> // sleep

#include "thread_pool.hpp"
#include "waitable_queue.hpp"
#include "taskers.hpp"
// #include "irunnable.hpp"
#include "task_submiters.hpp"

using namespace advcpp;
using namespace std;

class Looper: public IRunnable{
public:
    const static size_t stopNumber = 13;
    explicit Looper(size_t a_loops = 100);

    ~Looper() = default;
    Looper(Looper const& a_rhs) = default;
    Looper& operator = (Looper const& a_rhs) = default;

    void Run() noexcept;
    size_t GetLoops();
private:
    size_t m_loops;
};

UNIT(Loop_test)
    size_t nTasks = 10000;

    ThreadPool pool;
    std::vector<shared_ptr<Looper> > loopers;
    loopers.reserve(nTasks);

    while (nTasks)
    {
        loopers.push_back(make_shared<Looper>());
        pool.Submit(loopers.back());
        --nTasks;
    }
    
    pool.ShutDown(ThreadPool<>::NOOB);

    const size_t size = loopers.size();
    for (size_t i = 0; i < size; ++i)
    {
        ASSERT_THAT(loopers[i]->GetLoops() == Looper::stopNumber || loopers[i]->GetLoops() == 100);
    }
END_UNIT

UNIT(add_more_threads)
    size_t nTasks = 10000;

    ThreadPool pool;
    std::vector<shared_ptr<Looper> > loopers;
    loopers.reserve(nTasks);

    while (nTasks)
    {
        loopers.push_back(make_shared<Looper>());
        pool.Submit(loopers.back());
        --nTasks;
    }
    
    const size_t addedWorkers = 4;
    pool.AddWorkers(addedWorkers);
    ASSERT_EQUAL(pool.NumOfWorkers(), addedWorkers + getHardwareCores()); 
    
    while (nTasks)
    {
        loopers.push_back(make_shared<Looper>());
        pool.Submit(loopers.back());
        --nTasks;
    }

    pool.ShutDown(ThreadPool<>::NOOB);

    const size_t size = loopers.size();

    for (size_t i = 0; i < size; ++i)
    {
        ASSERT_THAT(loopers[i]->GetLoops() == Looper::stopNumber || loopers[i]->GetLoops() == 100);
    }
END_UNIT

UNIT(remove_threads)
    size_t nTasks = 10000;
    const size_t nThreads = 10;

    ThreadPool pool;
    std::vector<shared_ptr<Looper> > loopers;
    loopers.reserve(nTasks);

    while (nTasks)
    {
        loopers.push_back(make_shared<Looper>());
        pool.Submit(loopers.back());
        --nTasks;
    }
    
    const size_t removedWorkers = 10;
    pool.RemoveWorker(removedWorkers);
    ASSERT_EQUAL(pool.NumOfWorkers(), nThreads - removedWorkers); 
    
    while (nTasks)
    {
    }
    
    pool.ShutDown(ThreadPool<>::NOOB);

    const size_t size = loopers.size();
    for (size_t i = 0; i < size; ++i)
    {
        ASSERT_THAT(loopers[i]->GetLoops() == Looper::stopNumber || loopers[i]->GetLoops() == 100);
    }
END_UNIT

UNIT(add_and_remove_threads)
    size_t nTasks = 10000;
    const size_t nThreads = 10;

    ThreadPool pool(nThreads);
    std::vector<shared_ptr<Looper> > loopers;
    loopers.reserve(nTasks);

    while (nTasks)
    {
        loopers.push_back(make_shared<Looper>());
        pool.Submit(loopers.back());
        --nTasks;
    }
    
    const size_t removedWorkers = nThreads;
    pool.RemoveWorker(removedWorkers);
    ASSERT_EQUAL(pool.NumOfWorkers(), 0); 

    ASSERT_EQUAL(pool.Submit(make_shared<Looper>()), false); 

    const size_t addedWorkers = 4;
    pool.AddWorkers(addedWorkers);
    ASSERT_EQUAL(pool.NumOfWorkers(), addedWorkers); 
    
    while (nTasks)
    {
        loopers.push_back(make_shared<Looper>());
        pool.Submit(loopers.back());
        --nTasks;
    }

    pool.ShutDown(ThreadPool<>::NOOB);

    const size_t size = loopers.size();
    for (size_t i = 0; i < size; ++i)
    {
        ASSERT_THAT(loopers[i]->GetLoops() == Looper::stopNumber || loopers[i]->GetLoops() == 100);
    }
    
END_UNIT

UNIT(submit_in_multi_threads)
    size_t nTasks = 10000;
    const size_t nThreads = 10;
    const size_t nSubmiters = 10;

    ThreadPool pool(nTasks);

    ThreadsGroup<TasksSubmiter<Looper> > sumbiters;    
    sumbiters.AddThreads(nSubmiters, pool, nTasks, nThreads);

    sumbiters.JoinAll();
    
    pool.ShutDown(ThreadPool<>::NOOB);    


    ASSERT_PASS();
END_UNIT


TEST_SUITE(Tip#556898 an overwhelming big mission can be broken to many possible small misions)
    TEST(Loop_test)
    TEST(add_more_threads)
    TEST(remove_threads)
    TEST(add_and_remove_threads)
    TEST(submit_in_multi_threads)
END_SUITE   

Looper::Looper(size_t a_loops)
: m_loops(a_loops)
{
}

void Looper::Run() noexcept
{
    while (--m_loops != stopNumber)
    {
    }
}

size_t Looper::GetLoops()
{
    return m_loops;
}
