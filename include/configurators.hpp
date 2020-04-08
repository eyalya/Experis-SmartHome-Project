#ifndef CONFIGURATORS_HPP
#define CONFIGURATORS_HPP

#include "iconfigurator.hpp" //IConfigurator
#include "system_connector_api.hpp" //SystemConnectorApi
#include "device_data_factory.hpp" //DeviceDataFactory
#include "idevice_maker.hpp" //IDeviceMaker
#include "idistributor.hpp" //IDistributor

namespace smartHome 
{

class HsConnectorConfig: public IConfigurator 
{
public:
    HsConnectorConfig();

    booter::SystemConnectorApi& GetConnector();

private:
    booter::SystemConnectorApi& m_connectors;
};

class HsBooterConfig: public IConfigurator 
{
public:
    HsBooterConfig();

    booter::DeviceDataFactory& GetDataFactory();
    booter::IDeviceMaker& GetDeviceMaker();

private:
    booter::DeviceDataFactory& m_factory;
    booter::IDeviceMaker& m_maker;
};

class HsDistributerConfig: public IConfigurator 
{
public:
    HsDistributerConfig();

    hub::IDistributor& GetDistributor();

private:
    hub::IDistributor& m_distributor;
};



} //namespace smarthome
#endif //CONFIGURATORS_HPP