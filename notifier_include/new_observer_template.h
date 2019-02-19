#ifndef NEW_OBSERVER_TEMPLATE_H
#define NEW_OBSERVER_TEMPLATE_H

#include <memory>
#include <type_traits>

#include "data_monitor_manager.h"
#include "notifier.h"
#include "sender_reciever_traits.h"
#include "update_traits.h"


//template<class EnumType>
//struct MonitorObj
//{
//   constexpr MonitorObj(EnumType nvalue)
//   {

//   }
//   constexpr  EnumType value_;
//};

//template <class MonitorType>
//class NewObseverTemplateInterface
//{
//public:

//    virtual ~NewObseverTemplateInterface() {}

//    template <class Functor>
//    constexpr void RegisterNotifyFunction(const MonitorObj<MonitorType> &nobj,Functor func)
//    {
//         Internal_RegisterNotifyFunction(nobj.value_,func);
//    }

//    template <MonitorType nvalue, class Parameter>
//    void CallUpdate(Parameter&& param)
//    {
//        Internal_CallUpdate<nvalue>(param);
//    }

//    template <MonitorType nvalue>
//    void CallUpdate()
//    {
//        Internal_CallUpdate<nvalue>();
//    }

//    template <MonitorType nvalue>
//    void RegisterNotifier()
//    {
//        MONMAN(MonitorType)
//            .RegisterNotifier(new GenericNotifier<
//                                  NotifyFunParameter<MonitorType, nvalue>>(),
//                              nvalue);
//    }

//protected:
//    template <class Functor>
//    constexpr void Internal_RegisterNotifyFunction(const MonitorType& nvalue, Functor fun)
//    {
//        auto notiflist = MONMAN(MonitorType).GetNotifier(nvalue);
//        for (auto notifier : notiflist) {
//            auto gennotifier = dynamic_cast<
//                GenericNotifier<NotifyFunParameter<MonitorType, nvalue>> *>(
//                notifier);
//            if (gennotifier) {
//                gennotifier->RegisterFunction(fun);
//            }
//        }
//    }

//    template <MonitorType nvalue, class Parameter>
//    void Internal_CallUpdate(Parameter&& param)
//    {
//        auto notiflist = MONMAN(MonitorType).GetNotifier(nvalue);
//        for (auto notifier : notiflist) {
//            auto gennotifier = dynamic_cast<
//                GenericNotifier<NotifyFunParameter<MonitorType, nvalue>> *>(
//                notifier);
//            if (gennotifier) {
//                gennotifier->onUpdate(param);
//            }
//        }
//    }

//    template <MonitorType nvalue>
//    void Internal_CallUpdate()
//    {
//        auto notiflist = MONMAN(MonitorType).GetNotifier(nvalue);
//        for (auto notifier : notiflist) {
//            auto gennotifier = dynamic_cast<GenericNotifier<void> *>(notifier);
//            if (gennotifier) {
//                gennotifier->onUpdate();
//            }
//        }
//    }

//private:
//};

#endif // NEW_OBSERVER_TEMPLATE_H
