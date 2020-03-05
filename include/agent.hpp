#ifndef IAGENT_HPP
#define IAGENT_HPP

#include <memory> //std::shared_ptr

#include "iloader.hpp" //ILoader
#include "event_base.hpp" //Topic, Location
#include "ievent_handler.hpp" //IEventHandler
#include "isubscribers_register.hpp" //ISubscribersRegister

namespace smartHome {
namespace booter {

using HandlerPtr = std::shared_ptr<hub::IEventHandler>;

struct DeviceData {
    std::string m_type;
    std::string m_log;
    Location m_location;
};

class Agent : public std::enable_shared_from_this<Agent>
{
public:
    
    // typedef std::shared_ptr<hub::IEventHandler> HandlerPtr;

    Agent(DeviceData& a_data);

    virtual void LoadToSystem(ILoader& a_loader) = 0; 
    virtual HandlerPtr GetHandler(Topic a_topic) = 0;

private:
    DeviceData m_data;
};

} // namespace eventor
} //namespace smartHome

#endif //IAGENT_HPP