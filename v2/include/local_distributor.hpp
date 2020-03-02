#ifndef ILOCAL_DISTRIBUTOR_HPP
#define ILOCAL_DISTRIBUTOR_HPP


#include <memory> //std::shared_ptr

#include "idistributor.hpp" //IDistributor
#include "ievent.hpp" //IEvent
#include "ifind_topic_subscriber.hpp" //IFindTopicSubscriber

namespace smartHome {
namespace hub {

class LocalDistributor: public IDistributor
{
public:
    typedef std::shared_ptr<IEvent> EventPtr;
    typedef std::shared_ptr<IFindTopicSubscriber> FindSubscriberPtr;

    LocalDistributor(FindSubscriberPtr a_subscriberContainer);

    virtual ~LocalDistributor() = default;
    LocalDistributor(LocalDistributor const& a_other) = default;
    LocalDistributor& operator=(LocalDistributor const& a_other) = default;

    
    virtual void DistributeToDevice(EventPtr a_event);

private:
    FindSubscriberPtr m_subscriberContainer;
};

} // namespace hub
} // namespace smartHome

#endif //ILOCAL_DISTRIBUTOR_HPP