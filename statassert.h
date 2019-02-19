
#ifndef STATASSERT_H
#define STATASSERT_H

#include <QDebug>

#include <memory>
#include <type_traits>

#include "sender_reciever_traits.h"
#include "update_traits.h"

// You must use a helper class
template <typename T>
struct FalseType : std::false_type
{
};

template <class ClassEnum, ClassEnum nvalue>
struct NotifyFunTraits
{
    static_assert(std::is_enum<ClassEnum>::value,
                  "ClassEnum must be enumeration type!");
    static_assert(FalseType<ClassEnum>::value,
                  "You must specifiy the function traits!");

    template <class Parameter>
    using FunProtoType = UpdateTraits<Parameter>;
    template <class Parameter>
    using FunParameter = Parameter;
};

template <class ClassEnum, ClassEnum nvalue>
using NotifyFunType = typename NotifyFunTraits<ClassEnum, nvalue>::FunProtoType;

template <class ClassEnum, ClassEnum nvalue>
using NotifyFunParameter = typename NotifyFunTraits<ClassEnum, nvalue>::FunParameter;

#define EXTERN_FUNTRAITS(EnumType, Value, ParmType) \
    template <>                                     \
    struct NotifyFunTraits<EnumType, Value>         \
    {                                               \
        using FunProtoType = UpdateTraits<ParmType>;\
        using FunParameter = ParmType;\
    };

template <class MonitorType>
struct Observer
{
    template <MonitorType nvalue>
    void RegisterFunction(NotifyFunType<MonitorType, nvalue> fun)
    {

        // Internal_Register(nvalue, fun)
        //   NotifierHelper<int, MonitorType>::RegisterNotifyFunction(montype,
        //                                                       fun);
    }
};

// template <class MonitorType>
// class ObseverTemplateInterface
//{
// public:
//    virtual ~ObseverTemplateInterface() {}

//    template <class ListenerType, class Parameter>
//    struct RegisterFunction
//    {
//        template <MonitorType nValue>
//        static void RegisterNotifyFunction(UpdateTraits<Parameter> fun,
//                                    ListenerType listner,
//                                    const std::string &str)
//        {

//            static_assert(AlwaysFalse<Parameter>::value, "Not Register
//            Prototype");
//            //listentraits_.AddListner(montype, listner, str);
//        }

//    };

//    template <class ListenerType, class Parameter>
//    void RegisterNotifyFunction(MonitorType montype,
//                                UpdateTraits<Parameter> fun,
//                                ListenerType listner,
//                                const std::string &str)
//    {
//      //  Internal_RegisterNotifyFunction(montype, fun);
//        listentraits_.AddListner(montype, listner, str);
//    }

// private:
//    std::shared_ptr<NotifyObj> sender_;
//    SenderRecieverTraits<MonitorType> listentraits_;
//};

#endif  // STATASSERT_H
