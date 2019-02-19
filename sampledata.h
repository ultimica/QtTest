#ifndef SAMPLEDATA_H
#define SAMPLEDATA_H

#include "monitor_enum_traits.h"
#include "monitorenum.h"

class SampleA
  : public MonitorEnumTraits<MonitorType, MonitorType::MONITOR_SAMPLEA,float>
{
public:
    SampleA();
    void SetData();

private:
};

#endif  // SAMPLEDATA_H
