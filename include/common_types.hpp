#ifndef COMMON_TYPES_HPP
#define COMMON_TYPES_HPP

#include <vector> //std::vector
#include <memory> //std::shared_ptr
namespace smartHome {

class IAgent;
class DeviceData; 

using DevicePtr = std::shared_ptr<IAgent>;
using DeviceDataPtr = std::shared_ptr<DeviceData>;

namespace hub{
class IEventHandler;
class DispatcherGroup;

using DgPtr = std::shared_ptr<DispatcherGroup>;
using DgPtrContainer = std::vector<DgPtr>;

} //namespace hub

namespace booter {

class IBuilder;


using DeviceType = std::string;
using EventHandlerPtr = std::shared_ptr<hub::IEventHandler>;
using IBuildPtr = std::shared_ptr<IBuilder>;

} //namespace booter

} //namespace smartHome

#endif //COMMON_TYPES_HPP