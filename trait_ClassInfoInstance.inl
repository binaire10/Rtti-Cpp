#ifndef TRAIT_CLASSSINFOINSTANCE_INL
#define TRAIT_CLASSSINFOINSTANCE_INL
#pragma once

#include "ClassInfoInstance.h"

template<typename T, typename ClassCXX>
inline std::string trait_ClassInfoInstance<T, ClassCXX>::name() noexcept
{
    return std::string(name_t());
}

template<typename T, typename ClassCXX>
inline std::pair<const FunctionMemberInfo_t *, const FunctionMemberInfo_t *> trait_ClassInfoInstance<T, ClassCXX>::members() noexcept
{
    return {&functionMember_t::value.front(), &functionMember_t::value[functionMember_t::value.size()]};
}

template<typename T, typename ClassCXX>
inline std::pair<const ClassInfo_t *, const ClassInfo_t *> trait_ClassInfoInstance<T, ClassCXX>::parents() noexcept
{
    return {&parent_t::value.front(), &parent_t::value[parent_t::value.size()]};
}

#include "trait_TypeInfoInstance.inl"
#endif // TRAIT_CLASSSINFOINSTANCE_INL
