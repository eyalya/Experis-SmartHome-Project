#ifndef DEMO_AGENTS_HPP
#define DEMO_AGENTS_HPP

#include <string> //std::string

#include "isensor.hpp" //ISensor
#include "event.hpp" //Location, Room, Floor

namespace smartHome {
namespace eventor {

typedef std::string Type;
typedef std::string Log;

struct TemperatureInfo {
    std::string m_deviceId;
    Type m_deviceType;
    Room  m_room;
    Floor m_floor;
    Log m_log;
    std::string m_config;
};

class TemperatureSensor: public ISensor {
public:
    TemperatureSensor(TemperatureInfo const& a_initInfo);

    ~TemperatureSensor() = default;
    TemperatureSensor(TemperatureSensor const& a_rhs) = default;
    TemperatureSensor& operator=(TemperatureSensor const& a_rhs) = default;

    virtual void Run() noexcept;

private:
    void ReadRandom();

private:
    TemperatureInfo m_info;
    char m_unit;
    int m_minRange;
    int m_maxRange;
    size_t m_period;
};



} //namespace eventor
} //namespace smartHome
#endif //DEMO_AGENTS_HPP