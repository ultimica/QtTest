#ifndef TEMPLATETEST_H
#define TEMPLATETEST_H

#include <QDebug>

#include <iostream>
#include <map>
#include <string>

enum class ENUMCLASS
{
    ENUMCLASS_0,
    ENUMCLASS_1,
    ENUMCLASS_2,
};



 template <class EnumClass,
           EnumClass nvalue,
           class Parameter>
 class InternalStatic
 {
 public:
     static void _Register(Parameter parm)
     {
         //static_assert(false, "Not Defefined Prototype");
        // qDebug() <<nvalue << "xxBase ===>" << parm;
     }
 };

 template<>
 class InternalStatic<ENUMCLASS, ENUMCLASS::ENUMCLASS_0, int>
 {
 public:
     static void _Register(int parm)
     {
        // static_assert(true, "Not Defefined Prototype");
         qDebug() << "Special __0 ===>" << parm;
     }
 };


 template<>
 class InternalStatic<ENUMCLASS, ENUMCLASS::ENUMCLASS_1, float>
 {
 public:
     static void _Register(float parm)
     {
        // static_assert(true, "Not Defefined Prototype");
         qDebug() << "Special __1 float===>" << parm;
     }
 };



 class AA
{
 public:
     template <class EnumType,class  Parameter,EnumType value>
     void Register(Parameter parm)
     {
         InternalStatic<EnumType, value, Parameter>::_Register(parm);
     }

};

#endif  // TEMPLATETEST_H
