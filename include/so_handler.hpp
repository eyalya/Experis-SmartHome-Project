#ifndef SO_HANDLER_HPP
#define SO_HANDLER_HPP 

#include <string> //std::string

#include "informative_exception.hpp"

namespace advcpp {

class SOHandler
{
public:
    SOHandler(std::string const& a_filePath);
    ~SOHandler(); 

    template<typename Func>
    void GetFunc(std::string const& a_filePath, Func& a_func);

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