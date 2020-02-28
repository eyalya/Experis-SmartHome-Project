#ifndef ISENSOR_HPP
#define ISENSOR_HPP

#include "thread.hpp"

namespace smartHome{
namespace eventor{

} //namespace eventor
} //namespace smartHome

class ISensor : advcpp::IRunnable
{
public:
    virtual ~ISensor() = default;

    virtual void Run() noexcept = 0;

protected:
    ISensor() = default;
    ISensor(ISensor const& a_rhs) = default;
    ISensor& operator=(ISensor const& a_rhs) = default;
};

#endif //ISENSOR_HPP