#include "listner_aa.h"

#include <QDebug>

#include <functional>

#include "DataMonitorManager.h"
#include "monitorenum.h"

Listner_AA::Listner_AA()

{
    MONMAN.RegisterFunction(MonitorType::MONITOR_SAMPLEA,
                            [this]() { qDebug() << "GAGAGAGAGAGA"; });
}

Listner_BB::Listner_BB()
{
    MONMAN.RegisterFunction(MonitorType::MONITOR_SAMPLEA,
                            std::bind(&Listner_BB::LISTENFUN, this));
}

void Listner_BB::LISTENFUN()
{
    qDebug() << "LISTEN _BB_B_B_B";
}

Listner_CC::Listner_CC()
{
    std::function<void()> myf = std::bind(&Listner_CC::ListenFunParm, this, 2);
    MONMAN.RegisterFunction(MonitorType::MONITOR_SAMPLEA, myf);
}

void Listner_CC::ListenFunParm(int FUNFN)
{
    qDebug() << "LISTEN _CC==>" << FUNFN;
}
