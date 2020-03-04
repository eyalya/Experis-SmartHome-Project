#ifndef BASIC_LOADER_HPP
#define BASIC_LOADER_HPP

#include "iloader.hpp"
#include "device_group.hpp"
#include "isensor.hpp" //ISensor
#include "thread_group.hpp" //ThreadGroup
#include "ievent_store_remover.hpp" //IEventStoreRemover

namespace smartHome {
namespace booter {

class BasicLoader : public ILoader
{
public:
    BasicLoader(hub::DeviceGroup& a_devices, eventor::IEventStoreRemover& a_storeRemover);

    virtual void LoadDevices();

private:
    hub::DeviceGroup& m_devices;
    eventor::IEventStoreRemover& m_storeRemover;
    advcpp::ThreadsGroup<eventor::ISensor> m_sensors;
};

} //namespace booter
} //namespace smartHome

#endif //BASIC_LOADER_HPP