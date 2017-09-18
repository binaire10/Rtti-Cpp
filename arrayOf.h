#ifndef ARRAYOF_H
#define ARRAYOF_H
#pragma once

#include <memory>
#include <array>
#include <meta_ContentUtility.hpp>
#include "TypeInfo_t.h"
#include "ClassInfo_t.h"
#include "FunctionMemberInfo_t.h"

/*!
 * \struct array_of_typeinfo
 * \brief tool to generate an array of TypeInfo_t with the parameter T.
 *
 * \struct array_of_classinfo
 * \brief tool to generate an array of ClassInfo_t with the parameter T.
 *
 * \struct array_of_functionmemberinfo
 * \brief tool to generate an array of FunctionMemberInfo_t with the parameter T.
 */

// tool to generate an array of TypeInfo_t

template<typename... T>
struct array_of_typeinfo
{
    static const std::array<TypeInfo_t, sizeof...(T)> value;
};

// tool to generate an array of ClassInfo_t

template<typename... T>
struct array_of_classinfo
{
    static const std::array<ClassInfo_t, sizeof...(T)> value;
};

// tool to generate an array of FunctionMemberInfo_t

template<typename... T>
struct array_of_functionmemberinfo
{
    static const std::array<FunctionMemberInfo_t, sizeof...(T)> value;
};

#endif // ARRAYOF_H
