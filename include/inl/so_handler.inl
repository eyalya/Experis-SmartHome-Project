#ifndef SO_HANDLER_INL
#define SO_HANDLER_INL  

#include <dlfcn.h> //dlopen
#include <iostream>

#include "so_handler.hpp"

namespace advcpp
{
    
inline SOHandler::SOHandler(std::string const& a_filePath)
: m_handle(dlopen(a_filePath.c_str(), RTLD_LAZY))
{
    if(!m_handle)
    {
        throw(SOException(a_filePath, XINFO));
    }
}

inline SOHandler::~SOHandler()
{
    dlclose(m_handle);
}

template<typename Func>
void SOHandler::GetFunc(std::string const& a_funcName, Func& a_func)
{
    void* a_res = dlsym(m_handle, a_funcName.c_str());
    std::cout << dlerror() << std::endl;
    if(!a_res)
    {
        throw(SOException(a_funcName, XINFO));
    }
    a_func = *(Func*)a_res;
}
 
inline SOException::SOException(std::string const& a_msg, Information const& a_info)
: InformativeException(a_msg, a_info)
{
}

} // namespace advcpp

#endif //SO_HANDLER_INL