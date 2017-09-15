#ifndef ARRAYOF_H
#define ARRAYOF_H
#pragma once

#include <memory>
#include <array>
#include <meta_ContentUtility.hpp>
#include "TypeInfo_t.h"
#include "ClassInfo_t.h"
#include "FunctionMemberInfo_t.h"

template<typename... T>
struct array_of_typeinfo
{
    static const std::array<TypeInfo_t, sizeof...(T)> value;
};

template<typename... T>
struct array_of_classinfo
{
    static const std::array<ClassInfo_t, sizeof...(T)> value;
};

template<typename... T>
struct array_of_functionmemberinfo
{
    static const std::array<FunctionMemberInfo_t, sizeof...(T)> value;
};

#endif // ARRAYOF_H
