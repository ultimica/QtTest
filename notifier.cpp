#include "notifier.h"

#include "DataMonitorManager.h"
#include "monitorenum.h"

GenericNotifier::GenericNotifier(MonitorType notifytype)
{
    MONMAN.RegisterNotifier(this, notifytype);
}

GenericNotifier::~GenericNotifier()
{
    MONMAN.UnRegister(this);
}

void GenericNotifier::onUpdate()
{
    MONMAN.CallUpdate(this);
}
