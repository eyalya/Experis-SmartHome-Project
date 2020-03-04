#ifndef IEVENT_STORE_REMOVER_HPP
#define IEVENT_STORE_REMOVER_HPP

#include <memory> //std::shared_ptr

#include "ievent.hpp"

namespace smartHome {
namespace eventor {

class IEventStoreRemover
{
public: 
    virtual ~IEventStoreRemover() = default;

    virtual std::shared_ptr<IEvent> RemoverEvent() = 0;

protected:
    IEventStoreRemover() = default;
    IEventStoreRemover(IEventStoreRemover const& a_other) = default;
    IEventStoreRemover& operator=(IEventStoreRemover const& a_other) = default;
};

} // namespace eventor
} //namespace smartHome

#endif //IEVENT_STORE_REMOVER_HPP