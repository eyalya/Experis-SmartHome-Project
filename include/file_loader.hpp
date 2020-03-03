#ifndef FILE_LOADER_HPP
#define FILE_LOADER_HPP

#include <string> //std::string

#include "iloader.hpp" //ILoader

namespace smartHome{
namespace booter {

class FileLoader: public ILoader
{
public:
    FileLoader(std::string const& a_filename);

    ~FileLoader() = default;
    FileLoader(FileLoader const& a_rhs) = default;
    FileLoader& operator=(FileLoader const& a_rhs) = default;

    virtual void LoadDevices();

private:
    std::string m_fileName;
};

} //namespace eventor 
} //namespace smartHome

#endif //FILE_LOADER_HPP