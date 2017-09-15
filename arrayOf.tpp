#ifndef ARRAYOF_TPP
#define ARRAYOF_TPP
#pragma once

#include "arrayOf.h"
#include "ClassInfoInstance.tpp"
#include "TypeInfoInstance.tpp"


template<typename... T>
const std::array<TypeInfo_t, sizeof...(T)> array_of_typeinfo<T...>::value   = {make_type<T>()...};

template<typename... T>
const std::array<ClassInfo_t, sizeof...(T)> array_of_classinfo<T...>::value = {make_type<T>()...};

template<typename... T>
const std::array<FunctionMemberInfo_t, sizeof...(T)> array_of_functionmemberinfo<T...>::value = {make_element<T>()...};

#endif // ARRAYVTYPE_TPP
