#include "system.h"
#include "plugin_impl_base.h"

namespace mavsdk {

PluginImplBase::PluginImplBase(System& system) :
    _parent(system.system_impl()),
    _parents({system.system_impl()})
{}
PluginImplBase::PluginImplBase(std::shared_ptr<System> system) :
    _parent(system->system_impl()),
    _parents({system->system_impl()})
{}
PluginImplBase::PluginImplBase(std::vector<std::shared_ptr<System>> systems)
{
    for (auto& system : systems) {
        _parents.push_back(system->system_impl());
    }

    if (systems.size() > 0) {
        _parent = systems.front()->system_impl();
    }
}

} // namespace mavsdk
