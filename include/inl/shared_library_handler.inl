#include <dlfcn.h> //dlopen

#include "shared_library_handler.hpp"

namespace smartHome {
namespace booter {
    
inline SharedLibraryHandler::SharedLibraryHandler(std::string const& a_filePath)
: m_handle(dlopen(a_filePath.c_str(), RTLD_LAZY))
{
    if(!m_handle)
    {
        //TODO: throw exception
    }
}

inline SharedLibraryHandler::~SharedLibraryHandler()
{
    dlclose(m_handle);
}

template<typename Func>
void SharedLibraryHandler::GetFunc(std::string const& a_funcName, Func& a_func)
{
    Func a_res* = dlsym(m_handle, a_funcName.c_str());
    if(!a_res)
    {
        //TODO: throw exception
    }
    a_func = *a_res;
}

} // namespace booter
} // namespace smartHome
