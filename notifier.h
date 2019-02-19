#ifndef __NOTIFIER__
#define __NOTIFIER__

#include <memory>

class Notifier
{
public:
    virtual void onUpdate() = 0;
};

enum class MonitorType;

class GenericNotifier : public Notifier
{
public:
    GenericNotifier() = delete;
    GenericNotifier(MonitorType notifytype);
    virtual ~GenericNotifier();
    virtual void onUpdate();

private:
};

#endif
