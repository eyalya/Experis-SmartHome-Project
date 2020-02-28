#ifndef ITOPIC_DISTRIBUTER_HPP
#define ITOPIC_DISTRIBUTER_HPP

#include "event.hpp" //Topic
#include "ievent_contorller.hpp" //eventControllers

namespace smartHome 
{
namespace hub 
{

class ITopicDistributer {
public:
    
    virtual ~ITopicDistributer() = default;
    
    virtual void ExecuteTopic(eventor::Topic const& a_topic, Event a_event) const = 0;

protected:
    ITopicDistributer() = default;
    ITopicDistributer(ITopicDistributer const& a_rhs) = default;
    ITopicDistributer& operator=(ITopicDistributer const& a_rhs) = default;

};


} //namespace hub
} //namespace smartHome 

#endif //ITOPIC_DISTRIBUTER_HPP