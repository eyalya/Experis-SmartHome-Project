#ifndef I_CONFIGURATOR_HPP
#define I_CONFIGURATOR_HPP
namespace smartHome 
{


class IConfigurator
{
public:
    virtual ~IConfigurator() = default;
    // virtual void LoadConfigurations() = 0;

protected:
    IConfigurator() = default;
    IConfigurator(IConfigurator const& a_other) = default;
    IConfigurator& operator=(IConfigurator const& a_rhs) = default;
};


} //namespace smarthome
#endif //I_CONFIGURATOR_HPP