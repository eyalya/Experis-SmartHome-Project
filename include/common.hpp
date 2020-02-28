#ifndef COMMON_HPP
#define COMMON_HPP

#include <cstddef>

namespace advcpp
{

#if __cplusplus == 201703L
        #define NOEXCEPT noexcept
#else
        #define NOEXCEPT throw()
#endif

#if __cplusplus == 201703L
        #define THROW1(X)
        #define THROW2(X, Y)
        #define THROW3(X, Y, Z)
#else
        #define THROW1(x) throw(x)
        #define THROW2(x,y) throw(x,y)
        #define THROW3(x,y,z) throw(x,y,z)
#endif


#define THROWX(x) throw x(InfoException(__FILE__, __func__, __LINE__))

#define BYTE 8


inline size_t getHardwareCores() {
    return get_nprocs() - 1; 
}

inline size_t GetMaxThreadsNum()
{
    
    return getHardwareCores() * 25;
}

class DoNothing {
public:
    DoNothing() = default;
    ~DoNothing() noexcept = default;
    DoNothing(DoNothing const& a_rhs) = default; 
    DoNothing& operator=(DoNothing const& a_rhs) = default; 
    
    void operator()(const std::exception& e) {(void) e;};
};

class UnCopiable {
protected:
    UnCopiable() {};
private: 
    UnCopiable(UnCopiable const& a_rhs);
    UnCopiable& operator = (UnCopiable const& a_rhs);
};

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
