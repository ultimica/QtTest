#ifndef MONITORENUMTRAITS_H
#define MONITORENUMTRAITS_H

#include <memory>
#include <functional>

#include "notifier.h"

template <class MonitorEnum, MonitorEnum value,class UpdateParam>
class MonitorEnumTraits
{
public:
    MonitorEnumTraits()
    {
        notifier.reset(new GenericNotifier(value));
    }
    std::shared_ptr<GenericNotifier> notifier;
    using funtraits= std::function<void(UpdateParam)>;

};

#endif  // MONITORENUMTRAITS_H
