#ifndef DEVICE_INL
#define DEVICE_INL

namespace smartHome {

inline DeviceData::DeviceData(std::string a_type, Location a_location, std::string a_log, std::string a_config)
: m_type(a_type)
, m_log(a_log)
, m_location(a_location)
, m_config(a_config)
{
}

inline Device::Device(DeviceDataPtr a_data, booter::SystemConnectorApi& a_connector)
: m_data(a_data)
, m_connector(a_connector)
{

}

inline DeviceDataPtr Device::GetData()
{
    return m_data;
}

inline booter::SystemConnectorApi& Device::GetConnector()
{
    return m_connector;
}

} //namespace smartHome

#endif //DEVICE_INL