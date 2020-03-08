#ifndef COMMON_TYPES_HPP
#define COMMON_TYPES_HPP

#include "ievent_handler.hpp" //IEventHandler

namespace smartHome {
class Device;
class DeviceData; 

using DevicePtr = std::shared_ptr<Device>;
using DeviceDataPtr = std::shared_ptr<DeviceData>;

namespace booter {

using EventHandlerPtr = std::shared_ptr<hub::IEventHandler>;

} //namespace booter

namespace hub {



} //namespace hub

} //namespace smartHome

#endif //COMMON_TYPES_HPP