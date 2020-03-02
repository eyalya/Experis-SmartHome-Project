#ifndef IDISTRIBUTOR_HPP
#define IDISTRIBUTOR_HPP

#include <memory> //std::shared_ptr

#include "ievent.hpp" 

namespace smartHome {
namespace hub {

class IDistributor
{
public:
    typedef std::shared_ptr<IEvent> EventPtr;

    virtual ~IDistributor() = default;
    virtual void DistributeToDevice(EventPtr a_event) = 0;

protected:
    IDistributor() = default;
    IDistributor(IDistributor const& a_other) = default;
    IDistributor& operator=(IDistributor const& a_other) = default;
};

} // namespace hub
} // namespace smartHome

#endif //IDISTRIBUTOR_HPP