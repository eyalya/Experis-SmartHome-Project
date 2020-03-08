#ifndef SHARED_LIBRARY_LOADER_HPP
#define SHARED_LIBRARY_LOADER_HPP 

#include <string> //std::string

namespace smartHome {
namespace booter {
    
class SharedLibraryHandler
{
public:
    SharedLibraryHandler(std::string const& a_filePath);
    ~SharedLibraryHandler();

    template<typename Func>
    void GetFunc(std::string const& a_filePath, Func& a_func);

private:
    void* m_handle;
};

} // namespace booter
} // namespace smartHome

#include "inl/shared_library_handler.inl"
#endif //SHARED_LIBRARY_LOADER_HPP