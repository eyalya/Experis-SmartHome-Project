#include"informative_exception.hpp"

namespace advcpp
{
	
inline const std::string& Information::Function() const NOEXCEPT
{
	return m_function;
}

inline const std::string& Information::File() const NOEXCEPT
{
	return m_file;	
}

inline size_t Information::Line() const NOEXCEPT
{
	return m_line;	
}

inline const std::string& InformativeException::Function() const NOEXCEPT
{
	return m_info.Function();
}

inline const std::string& InformativeException::File() const NOEXCEPT
{
	return m_info.File();	
}

inline size_t InformativeException::Line() const NOEXCEPT
{
	return m_info.Line();	
}

} //namespace advcpp

