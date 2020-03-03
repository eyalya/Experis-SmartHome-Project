#include <fstream> //fstream
#include <cassert>//assert

#include "file_loader.hpp"

using namespace std;

namespace smartHome{
namespace booter {

FileLoader::FileLoader(std::string const& a_filename)
: m_fileName(a_filename)
{
}


void FileLoader::LoadDevices()
{
    //TODO: exceptions
    ifstream file(m_fileName.c_str());
    
#ifdef NDEBAG
    assert(!file.fail());
#endif

    // while(file.good())
    // {
    //     string section = ReadSection(file);
    //     device = createDevice();
    // }
    


}

} //namespace eventor 
} //namespace smartHome
