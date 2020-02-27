#include <sstream>	

#include "informative_exception.hpp"

namespace advcpp
{
	
Information::Information(const char* a_file, const char* a_function, size_t a_line) NOEXCEPT
: m_function(a_function)
, m_file(a_file)
, m_line(a_line)
{} 

InformativeException::InformativeException(char const* a_msg, Information const& a_info) THROW(std::logic_error)
: std::logic_error(a_msg)
, m_info(a_info)
{}

InformativeException::InformativeException(std::string a_msg, Information const& a_info) THROW(std::logic_error)
: std::logic_error(a_msg)
, m_info(a_info)
{}

InformativeException::~InformativeException() NOEXCEPT
{}


std::string InformativeException::What() const THROW(std::ios_base::failure)
{
	std::ostringstream sStream;

	sStream << "In File: " << File();
	sStream << ", In Function: " << Function();
	sStream << ", In Line: " << Line() << '\n';
	sStream << what();

	return sStream.str();

}//namespace advcpp


}

