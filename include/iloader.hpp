#ifndef ILOADER_HPP
#define ILOADER_HPP

#include "iregistrator.hpp" //IRegistrator
#include "ievent_reciver.hpp" //IEventReciver

namespace smartHome {
namespace booter {

class ILoader
{
public:
    virtual ~ILoader() = default;

    virtual IRegistrator& GetRegistrator() = 0;
    virtual eventor::IEventReciver& GetEventReciever() = 0;

protected:
    ILoader() = default;
    ILoader(ILoader const& a_other) = default;
    ILoader& operator=(ILoader const& a_other) = default;
};

} //namespace booter
} //namespace smartHome

#endif //ILOADER_HPP