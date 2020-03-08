#include "test_registrator.hpp"
#include "fire_sensor.hpp"
#include "sprinkler_device.hpp"

namespace smartHome {
namespace booter {

void TestRegistrator::Registrate(DeviceType const& a_type, DeviceBuilders& a_builders)
{
    if (a_type == std::string("Fire"))
    {
        // return std::make_shared<FireSensor>(a_data, a_connectors);
        RegistrateFireBuilder(DeviceBuilders& a_builders);
    }
    else
    {
        RegistrateSprinklerBuilder(DeviceBuilders& a_builders);
    }   
}

void RegistrateFireBuilder(DeviceBuilders& a_builders)
{
    static std::unique_ptr<FireSensorBuilder> s_fireBuilder;
    a_builders.AddBuilder("Fire", std::move(s_fireBuilder));
}

void RegistrateSprinklerBuilder(DeviceBuilders& a_builders)
{
    // static std::unique_ptr<FireSensorBuilder> s_fireBuilder;
    // a_builders.AddBuilder("Fire", std::move(s_fireBuilder));
}


} // namespace booter
} // namespace smartHome
