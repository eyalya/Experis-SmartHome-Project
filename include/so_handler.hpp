#ifndef SO_HANDLER_HPP
#define SO_HANDLER_HPP 

#include <string> //std::string
#include <functional> //std::function<>

#include "informative_exception.hpp"

namespace advcpp {

class SOHandler
{
public:
    SOHandler(std::string const& a_filePath);
    ~SOHandler(); 

    // SOHandler(SOHandler const& a_other) = delete;
    // SOHandler& operator=(SOHandler const& a_other) = delete;

    template<typename F>
    std::function<F> GetFunc(const char* a_funcName);

private:
    void* m_handle;
};

class SOException: public InformativeException
{
public:
    SOException(std::string const& a_msg, Information const& a_info);
};

} // namespace advcpp
    
#include "inl/so_handler.inl"
#endif //SO_HANDLER_HPP