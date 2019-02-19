#ifndef MODULEOBSERVER_H
#define MODULEOBSERVER_H

#include <memory>
#include <functional>

#include "notifier_helper.h"

class DelegateList;
class ModuleObserver
{
public:
    ModuleObserver();

//    void GetDelegator(std::string& str)
//    {
//        EnumType ret=GetValueFromStr(str);
//        GetDelegator(enumvalue);
//    }

//    template<class Montype>
//    void GetDelegator(Montype value)
//    {
//        del_=NotifierHelper<Montype>::GetDelegator(value);
//    }

//    template<class Parameter>
//    void RegisterFunction(std::function<void(Parameter)> fun)
//    {
//       // del_.get()
//    }

//    template<class MonType,class Param>
//    void Update(MonType value,Param parm)
//    {
//        NotifierHelper<MonType>::CallUpdate(value, parm);
//    }

private:
    std::shared_ptr<DelegateList> del_;
};

#endif // MODULEOBSERVER_H
