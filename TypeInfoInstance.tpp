#ifndef TYPEINFOINSTANCE_TPP
#define TYPEINFOINSTANCE_TPP
#pragma once

#include "TypeInfoInstance.h"
#include "vTypeLogger.h"

template<typename T, typename = typename std::enable_if<(std::is_fundamental<T>::value || std::is_pointer<T>::value) && NameType<T>::isLogged>::type>
TypeInfo_t make_type() noexcept
{
#if __cplusplus >= 201402L
    static TypeInfo_t typeInfo(v2::load_type(std::make_unique<TypeInfoInstance<T>>()));
#else
    static TypeInfo_t typeInfo(v2::load_type(std::unique_ptr<TypeInfoInstance<T>>(new TypeInfoInstance<T>())));
#endif
    return typeInfo;
}

template<typename T>
constexpr TypeInfoInstance<T>::TypeInfoInstance() noexcept
{}

template<typename T>
std::string TypeInfoInstance<T>::name() const noexcept
{
    return trait_TypeInfoInstance<T>::name();
}

template<typename T>
std::pair<const TypeInfo_t *, const TypeInfo_t *> TypeInfoInstance<T>::transtypes() const noexcept
{
    return trait_TypeInfoInstance<T>::transtypes();
}

template<typename T>
std::pair<const vFunctionInfo *, const vFunctionInfo *> TypeInfoInstance<T>::operators() const noexcept
{
    return trait_TypeInfoInstance<T>::operators();
}

template<typename T>
std::pair<const TypeInfo_t *, const TypeInfo_t *> TypeInfoInstance<T>::transtypesExt() const noexcept
{
    return trait_TypeInfoInstance<T>::transtypesExt();
}

#include "trait_TypeInfoInstance.inl"

#endif // TYPEINFOINSTANCE_TPP
