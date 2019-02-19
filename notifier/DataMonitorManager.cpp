#include "DataMonitorManager.h"

#include <algorithm>

#include "monitorenum.h"
#include "notifier.h"

MonitorMan &MonitorMan::Instance()
{
    static MonitorMan g_staticInstance;
    return g_staticInstance;
}

void MonitorMan::CallUpdate(Notifier *notifier)
{
    MonitorType curtype = GetNotifyerEnum(notifier);
    for (auto listfun : updatelist_[curtype])
        listfun();
}

MonitorType MonitorMan::GetNotifyerEnum(Notifier *notifier)
{
    MonitorType retType = MonitorType::MONITOR_ERROR;
    auto pos = notifier_map_.begin();
    auto endpos = notifier_map_.end();
    for (; pos != endpos; pos++) {
        auto result =
            std::find(std::begin(pos->second), std::end(pos->second), notifier);
        if (result != std::end(pos->second)) {
            retType = pos->first;
            break;
        }
    }
    return retType;
}

MonitorMan::MonitorMan() {}

void MonitorMan::RegisterNotifier(Notifier *notifier, MonitorType montype)
{
    notifier_map_[montype].push_back(notifier);
}

void MonitorMan::UnRegister(Notifier *notifier)
{
    auto pos = notifier_map_.begin();
    auto endpos = notifier_map_.end();
    for (; pos != endpos; pos++) {
        auto curvec = pos->second;
        curvec.erase(std::remove(curvec.begin(), curvec.end(), notifier),
                     curvec.end());
    }
}

void MonitorMan::RegisterFunction(MonitorType montype,
                                  std::function<void()> fun)
{
    updatelist_[montype].push_back(fun);
}
