#include "test_registrator.hpp"
#include "smoke_detector.hpp"
#include "sprinkler_device.hpp"

namespace smartHome {
namespace booter {

void TestRegistrator::Register(DeviceType const& a_type, DeviceBuilders& a_builders)
{
    if (a_type == std::string("Fire"))
    {
        // return std::make_shared<FireSensor>(a_data, a_connectors);
        RegisterSmokeDetectorBuilder(a_builders);
    }
    else
    {
        RegisterSprinklerBuilder(a_builders);
    }   
}

void RegisterSmokeDetectorBuilder(DeviceBuilders&)
{
    // static std::unique_ptr<FireSensorBuilder> s_fireBuilder;
    // a_builders.AddBuilder("Fire", std::move(s_fireBuilder));
}

void RegisterSprinklerBuilder(DeviceBuilders&)
{
    // static std::unique_ptr<FireSensorBuilder> s_fireBuilder;
    // a_builders.AddBuilder("Fire", std::move(s_fireBuilder));
}


} // namespace booter
} // namespace smartHome
