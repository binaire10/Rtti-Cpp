#ifndef TRAIT_TYPEINFOINSTANCE_INL
#define TRAIT_TYPEINFOINSTANCE_INL
#pragma once

#include "TypeInfoInstance.h"

template<typename T>
inline std::string trait_TypeInfoInstance<T>::name() noexcept
{
    return std::string(name_t());
}

template<typename T>
inline std::pair<const TypeInfo_t *, const TypeInfo_t *> trait_TypeInfoInstance<T>::transtypes() noexcept
{
    return {&transtype_t::value.front(), &transtype_t::value[transtype_t::value.size()]};
}

template<typename T>
inline std::pair<const vFunctionInfo *, const vFunctionInfo *> trait_TypeInfoInstance<T>::operators() noexcept
{}

template<typename T>
inline std::pair<const TypeInfo_t *, const TypeInfo_t *> trait_TypeInfoInstance<T>::transtypesExt() noexcept
{
    return {&transtypeExt_t::value.front(), &transtypeExt_t::value[transtypeExt_t::value.size()]};
}

#endif // TRAIT_TYPEINFOINSTANCE_INL
