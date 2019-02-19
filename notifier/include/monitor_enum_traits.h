#ifndef MONITORENUMTRAITS_H
#define MONITORENUMTRAITS_H

#include <memory>

#include "notifier.h"

template <class MonitorEnum, MonitorEnum value>
class MonitorEnumTraits
{
public:
    MonitorEnumTraits() { notifier.reset(new GenericNotifier(value)); }
    std::shared_ptr<GenericNotifier> notifier;
};

#endif  // MONITORENUMTRAITS_H
