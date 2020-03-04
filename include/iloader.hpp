#ifndef ILOADER_HPP
#define ILOADER_HPP

namespace smartHome {
namespace booter {

class ILoader
{
public:
    virtual ~ILoader() = default;

    virtual void LoadDevices() = 0;

protected:
    ILoader() = default;
    ILoader(ILoader const& a_other) = default;
    ILoader& operator=(ILoader const& a_other) = default;
};

} //namespace booter
} //namespace smartHome

#endif //ILOADER_HPP