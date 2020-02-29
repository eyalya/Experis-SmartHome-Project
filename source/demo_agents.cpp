#include <iostream> //cout

#include "demo_agents.hpp"
#include "utils.hpp" 

using namespace std;

namespace smartHome {
namespace eventor {

TemperatureSensor::TemperatureSensor(TemperatureInfo const& a_initInfo)
: m_info (a_initInfo)
{
    //TODO:parse config file
    m_unit  = 'F';
    m_minRange = -5;
    m_maxRange = 55;
    m_period = 12;
}

void TemperatureSensor::Run() noexcept
{
    while (true)
    {
      ReadRandom();
    //TODO:   Sleep()

    }
}

void TemperatureSensor::ReadRandom()
{
    cout << "print temp";
}

} //namespace eventor
} //namespace smartHome