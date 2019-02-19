#ifndef _FUN_PROTOTYPE_TRAITS_
#define _FUN_PROTOTYPE_TRAITS_

#include "update_traits.h"

template <class ClassEnum, ClassEnum nvalue, class Parameter>
struct NotifyFunTraits
{
    using FunType = UpdateTraits<Parameter>;
    ClassEnum enum_value = nvalue;
};

#endif