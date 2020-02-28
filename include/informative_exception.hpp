#ifndef INFORMATIVE_EXCEPTION_HPP
#define INFORMATIVE_EXCEPTION_HPP

#include <string>
#include <ios>
#include <exception>
#include <stdexcept>
#include <cstddef>

// #define NOEXCEPT noexcept
// #define THROW(x) //throw(x)
// #define THROW2(x,y) //throw(x,y)
// #define THROW3(x,y,z) //throw(x,y,z)
// #define XINFO Information(__FILE__, __func__, __LINE__ )

namespace advcpp
{

struct Information
{
	Information(const char* a_file, const char* a_function, size_t a_line) NOEXCEPT;
 	
	const std::string& Function() const NOEXCEPT;
	const std::string& File() const NOEXCEPT;
	size_t Line() const NOEXCEPT;
	
private:
	const std::string m_function;
	const std::string m_file;
	size_t m_line;
};

struct InformativeException :  public std::logic_error
{
public:
	const std::string& Function() const NOEXCEPT;
	const std::string& File() const NOEXCEPT;
	size_t Line() const NOEXCEPT;
	std::string What() const THROW(std::ios_base::failure);

protected:
	InformativeException(char const* a_msg, Information const& a_info) THROW(std::logic_error);
	InformativeException(std::string a_msg, Information const& a_info) THROW(std::logic_error);
	virtual ~InformativeException() NOEXCEPT;

private:
	Information m_info;
};

}//namespace advcpp

#include "./inl/informative_exception.inl"

#endif /*INFORMATIVE_EXCEPTION_HPP*/
