#ifndef DATA_MON_MANAGER
#define DATA_MON_MANAGER

#include <functional>
#include <map>
#include <memory>
#include <vector>

enum class MonitorType;
class DataMonitorFactory;
class Notifier;

using ListOfUpdateFun = std::vector<std::function<void()>>;
using ListOfNotifier = std::vector<Notifier *>;

using NotifierMap = std::map<MonitorType, ListOfNotifier>;
using UpdateFunMap = std::map<MonitorType, ListOfUpdateFun>;

template <class T>
class UpdateTraits
{
public:
    // std::function<void(...)> fun_;
};

class MonitorMan
{
public:
    static MonitorMan &Instance();
    void CallUpdate(Notifier *notifier);
    void RegisterNotifier(Notifier *notifier, MonitorType montype);
    void RegisterFunction(MonitorType montype, std::function<void()> fun);
    void UnRegister(Notifier *notifier);

private:
    MonitorMan();
    MonitorType GetNotifyerEnum(Notifier *notifier);
    NotifierMap notifier_map_;
    UpdateFunMap updatelist_;
};

#define MONMAN MonitorMan::Instance()
#endif
