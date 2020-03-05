#ifndef IREGISTRATOR_HPP
#define IREGISTRATOR_HPP

#include "event_base.hpp" //location
#include "ievent_handler.hpp"
#include "device.hpp"
#include <memory> //std::shared_ptr

namespace smartHome {
namespace booter {

class IRegistrator
{
public:
    virtual ~IRegistrator() = default;

    virtual void RegisterDevice(std::shared_ptr<Device> a_agent) = 0;

protected:
    IRegistrator() = default;
    IRegistrator(IRegistrator const& a_other) = default;
    IRegistrator& operator=(IRegistrator const& a_other) = default;
};

} //namespace booter
} //namespace smartHome

#endif //IREGISTRATOR_HPP