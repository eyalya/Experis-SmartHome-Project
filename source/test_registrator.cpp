// #include <utility>      // std::move
// #include "test_registrator.hpp"
// #include "smoke_detector.hpp"
// #include "sprinkler_device.hpp"

// namespace smartHome {
// namespace booter {

// void TestRegistrator::Register(DeviceType const& a_type, DeviceBuilders& a_builders)
// {
//     if (a_type == std::string("Fire"))
//     {
//         // return std::make_shared<FireSensor>(a_data, a_connectors);
//         RegisterSmokeDetectorBuilder(a_builders);
//     }
//     else
//     {
//         RegisterSprinklerBuilder(a_builders);
//     }   
// }

// extern "C"
// {
//     void RegisterSmokeDetectorBuilder(DeviceBuilders& a_builders)
//     {
//         static std::unique_ptr<SmokeDetectorBuilder> s_fireBuilder;
//         a_builders.AddBuilder("Fire", std::move(s_fireBuilder));
//     }

//     void RegisterSprinklerBuilder(DeviceBuilders& a_builders)
//     {
//         static std::unique_ptr<SprinkelBuilder> s_sprinklerBuilder;
//         a_builders.AddBuilder("Sprinkler", std::move(s_sprinklerBuilder));
//     }
// }

// } // namespace booter
// } // namespace smartHome
