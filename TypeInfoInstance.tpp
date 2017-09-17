#ifndef TYPEINFOINSTANCE_TPP
#define TYPEINFOINSTANCE_TPP
#pragma once

#include "TypeInfoInstance.h"
#include "vTypeLogger.h"

template<typename T>
typename _MakeType<T, TypeInfoInstance>::autoType make_type() noexcept
{
#if __cplusplus >= 201402L
    static TypeInfo_t typeInfo(v2::load_type(std::make_unique<TypeInfoInstance<T>>()));
#else
    static TypeInfo_t typeInfo(v2::load_type(std::unique_ptr<TypeInfoInstance<T>>(new TypeInfoInstance<T>())));
#endif
    return typeInfo;
}

template<typename T>
typename _MakeType<T, TypeInfoInstance>::builtinMakeType make_type() noexcept
{
    return TypeInfoInstance<T>::make_type();
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
