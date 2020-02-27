#ifndef COMMON_HPP
#define COMMON_HPP

#include <cstddef>

namespace advcpp
{

class UnCopyable
{
protected:
    UnCopyable() {}

private:
    UnCopyable(UnCopyable const&); // = delete;
    UnCopyable& operator=(UnCopyable const&); // = delete;

};

struct Nano 
{
    size_t value;

    Nano(size_t a_nano);    
    operator size_t() const;      
    operator timespec() const;
};

struct Second 
{
    size_t value;

    Second(size_t a_seconds);    
    operator size_t() const;      
    operator timespec() const;
};

void Sleep(Nano const& a_nano);
void Sleep(Second const& a_sec);

} //namespace advcpp

#include "./inl/common.inl"

#endif /*COMMON_HPP*/
