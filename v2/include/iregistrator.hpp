#ifndef IREGISTRATOR_HPP
#define IREGISTRATOR_HPP

#include "event_base.hpp" //location

namespace smartHome {
namespace booter {

class IRegistrator
{
public:
    virtual ~IRegistrator() = default;

    void RegisterForTopic(Topic const& a_topic, IEventHandler& a_handler, Device& a_device);

protected:
    IRegistrator() = default;
    IRegistrator(IRegistrator const& a_other) = default;
    IRegistrator& operator=(IRegistrator const& a_other) = default;
};

} //namespace booter
} //namespace smartHome

#endif //IREGISTRATOR_HPP