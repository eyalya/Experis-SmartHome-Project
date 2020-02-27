#include "waitable_queue.hpp"

namespace advcpp
{

template <typename T>
WaitableQ<T>::WaitableQ(size_t a_maxSize)
: m_cond()
, m_mutex()
, m_capacity(a_maxSize)
, m_size(0)
{
}

template <typename T>
void WaitableQ<T>::Enqueue(T const& a_val)
{
    {
        Guard g(m_mutex);
        while (m_data.size() == m_capacity)
        {
            m_cond.Wait(m_mutex, WQIsFull<T>(*this));
        }
        m_data.push(a_val);
    }
    m_cond.Notify();
}

template <typename T>
void WaitableQ<T>::Dequeue(T & a_res) 
{
    {
        Guard g(m_mutex);
        while (m_data.size() == 0)
        {
            m_cond.Wait(m_mutex, WQIsempty<T>(*this));
        }

        a_res = m_data.front();
        m_data.pop();
    }
    m_cond.Notify();
}

template <typename T>
size_t WaitableQ<T>::Size() const
{
    m_mutex.Lock();
    size_t res = m_data.size();
    m_mutex.Unlock();
    return res;
}

template <typename T>
size_t WaitableQ<T>::Capacity() const
{
    return m_capacity;
}

template <typename T>
bool WaitableQ<T>::IsEmpty() const
{
    return m_data.size() == 0;
}

template <typename T>
bool WaitableQ<T>::IsFull() const
{
    return m_data.size() == m_capacity;
}

template <typename T>
WQIsempty<T>::WQIsempty(WaitableQ<T> const& a_Q) NOEXCEPT
: m_Q(a_Q)
{
}

template <typename T>
bool WQIsempty<T>::operator()() const NOEXCEPT
{
    return m_Q.IsEmpty();
}

template <typename T>
WQIsFull<T>::WQIsFull(WaitableQ<T> const& a_Q) NOEXCEPT
: m_Q(a_Q)
{
}

template <typename T>
bool WQIsFull<T>::operator()() const NOEXCEPT
{
    return m_Q.IsFull();
}

} // namespace advcpp
