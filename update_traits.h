#ifndef UPDATE_TRAITS_H
#define UPDATE_TRAITS_H

/// Update functon template for Observer

#include <functional>
#include <vector>

template <class NotifyParamType>
class ParamTypeTraits
{
public:
    using funtraits =typename std::function<void(NotifyParamType)>;
    using paramtype=NotifyParamType;
};

template <>
class ParamTypeTraits<void>
{
public:
    using funtraits = std::function<void()>;
    using paramtype=void;
};

template <class NotifyParamType>
using UpdateTraits = typename ParamTypeTraits<NotifyParamType>::funtraits;

template <class NotifyParamType>
using UpdateList = std::vector<UpdateTraits<NotifyParamType>>;

#endif  // UPDATE_TRAITS_H
