#ifndef OBSERVERYY_H
#define OBSERVERYY_H

#include <QDebug>

#include "statassert.h"

enum class YY
{
    YY_0,
    YY_1,
    YY_2,
};

EXTERN_FUNTRAITS(YY, YY::YY_0,int)

class YY_Observer : public Observer<YY>
{
public:
    //  void RegisterFunction(UpdatePrototype<YY>* prototype);

private:
};

#endif  // OBSERVERYY_H
