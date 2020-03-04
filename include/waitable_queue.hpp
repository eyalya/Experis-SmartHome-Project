#ifndef SAFE_QUEUE_HPP
#define SAFE_QUEUE_HPP

#include <queue>// std::queue
#include "conditional_var.hpp" //ConditionalVar
#include "locks.hpp" // mutex
#include "informative_exception.hpp"
#include <string>

namespace advcpp
{
    
template <typename T>
class WQIsempty;

template <typename T>
class WQIsFull;

template <typename T>
class WaitableQ : private UnCopyable
{
public:
    explicit WaitableQ(size_t a_maxSize);

    void Enqueue(T const& a_val);
    void Dequeue(T & a_res);

    size_t Size() const;
    size_t Capacity() const;

    friend class WQIsempty<T>;
    friend class WQIsFull<T>;

private: 
    bool IsEmpty() const;
    bool IsFull() const;

private:
    std::queue<T> m_data;
    ConditionalVar m_cond;
    mutable Mutex m_mutex;
    size_t m_capacity;
    size_t m_size;
};

template <typename T>
class WQIsempty 
{
public:
    WQIsempty(WaitableQ<T> const& a_Q) NOEXCEPT;
    bool operator()() const NOEXCEPT;
private:
    WaitableQ<T> const& m_Q;
};

template <typename T>
class WQIsFull
{
public:
    WQIsFull(WaitableQ<T> const& a_Q) NOEXCEPT;
    bool operator()() const NOEXCEPT;

private:
    WaitableQ<T> const& m_Q;
};


} // namespace advcpp

#include "inl/waitable_queue.inl"

#endif //SAFE_QUEUE_HPP
