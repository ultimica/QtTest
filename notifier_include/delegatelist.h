#ifndef DELEGATELIST_H
#define DELEGATELIST_H

#include "notifier.h"

class DelegateList
{
public:
    DelegateList(Notifier* del);

    template<class ParameterType>
    GenericNotifier<ParameterType>* GetGenericNotifier()
    {
        return nullptr;
    }

private:
    Notifier* delegate_;
};

#endif // DELEGATELIST_H
