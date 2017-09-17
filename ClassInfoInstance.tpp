#ifndef CLASSINFOINSTANCE_TPP
#define CLASSINFOINSTANCE_TPP
#pragma once

#include "ClassInfoInstance.h"
#include "ClassInfo_t.h"
#include "vTypeLogger.h"

template<typename T, typename = typename std::enable_if<std::is_class<typename std::decay<T>::type>::value && NameType<T>::isLogged>::type>
ClassInfo_t make_type() noexcept
{
#if __cplusplus >= 201402L
    static ClassInfo_t typeInfo(reinterpret_cast<const vClassInfo *>(v2::load_type(std::make_unique<ClassInfoInstance<T>>())));
#else
    static ClassInfo_t typeInfo(reinterpret_cast<const vClassInfo *>(v2::load_type(std::unique_ptr<ClassInfoInstance<T>>(new ClassInfoInstance<T>))));
#endif
    return typeInfo;
}

template<typename T>
constexpr ClassInfoInstance<T>::ClassInfoInstance() noexcept
{}

template<typename T>
std::string ClassInfoInstance<T>::name() const noexcept
{
    return trait_ClassInfoInstance<T>::name();
}

template<typename T>
std::pair<const TypeInfo_t *, const TypeInfo_t *> ClassInfoInstance<T>::transtypes() const noexcept
{
    return trait_ClassInfoInstance<T>::transtypes();
}

template<typename T>
std::pair<const vFunctionInfo *, const vFunctionInfo *> ClassInfoInstance<T>::operators() const noexcept
{
    return trait_ClassInfoInstance<T>::operators();
}

template<typename T>
std::pair<const FunctionMemberInfo_t *, const FunctionMemberInfo_t *> ClassInfoInstance<T>::members() const noexcept
{
    return trait_ClassInfoInstance<T>::members();
}

template<typename T>
std::pair<const ClassInfo_t *, const ClassInfo_t *> ClassInfoInstance<T>::parents() const noexcept
{
    return trait_ClassInfoInstance<T>::parents();
}

template<typename T>
std::pair<const TypeInfo_t *, const TypeInfo_t *> ClassInfoInstance<T>::transtypesExt() const noexcept
{
    return trait_ClassInfoInstance<T>::transtypesExt();
}

#include "trait_ClassInfoInstance.inl"

#endif // CLASSINFOINSTANCE_TPP
