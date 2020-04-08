#include "configurators.hpp" 

#include "publisher.hpp" //Publisher
#include "fifo_event_store.hpp" //FifoEventStore
#include "lite_event_reciver.hpp" //LiteEventReciver 
#include "system_connector.hpp" //SystemConnectors

#include "so_device_registrator.hpp" //SODeviceRegistrator
#include "device_maker.hpp" //SoDeviceMaker 

#include "local_distributor.hpp" //LocalDistributor

namespace smartHome 
{

static hub::Publisher s_publisher;
static eventor::FifoEventStore s_fifoEventStore;
static eventor::LiteEventReciver s_eventReciever(s_fifoEventStore);
static booter::SystemConnectors s_connectors(s_publisher, s_eventReciever, s_publisher, s_fifoEventStore);

static booter::DeviceDataFactory s_factory;
static booter::SODeviceRegistrator s_registrator;
static booter::DeviceBuilders s_builders(s_registrator);
static booter::DeviceMaker s_deviceMaker(s_builders);

static hub::LocalDistributor s_distributor(s_connectors.GetFinder());

HsConnectorConfig::HsConnectorConfig()
: m_connectors(s_connectors)
{
}

booter::SystemConnectorApi& HsConnectorConfig::GetConnector()
{
    return m_connectors;
}

HsBooterConfig::HsBooterConfig()
: m_factory(s_factory)
, m_maker(s_deviceMaker)
{
}

booter::DeviceDataFactory& HsBooterConfig::GetDataFactory()
{
    return m_factory;
}

booter::IDeviceMaker& HsBooterConfig::GetDeviceMaker()
{
    return m_maker;
}

HsDistributerConfig::HsDistributerConfig()
: m_distributor(s_distributor)
{
}

hub::IDistributor& HsDistributerConfig::GetDistributor()
{
    return m_distributor;
}

} //namespace smarthome