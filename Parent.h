#ifndef PARENT_H
#define PARENT_H
#pragma once

#include <meta_Utility.hpp>
#include "arrayOf.h"

template<typename D, typename... T>
class parent_check
{
    static_assert(b_and(std::is_base_of<T, D>()...), "class D not derived by T");
};

template<typename T>
struct Parent : array_of_classinfo<>
{};

#define B_DECLARE_PARENTS_HPP(Target, ...) \
    template<> \
    struct Parent<Target> : parent_check<Target, __VA_ARGS__> \
    { \
        static const std::array<ClassInfo_t, meta::arg_size<__VA_ARGS__>::count> &value; \
        using types = std::tuple<__VA_ARGS__>; \
    }

#define B_EXPORT_DECLARE_PARENTS_HPP(E, Target, ...) \
    template<> \
    struct Parent<Target> : parent_check<Target, __VA_ARGS__> \
    { \
        static const std::array<ClassInfo_t, meta::arg_size<__VA_ARGS__>::count> &value; \
        using types = std::tuple<__VA_ARGS__>; \
    }

#define B_DECLARE_PARENTS_CPP(Target, ...) \
   const std::array<ClassInfo_t, meta::arg_size<__VA_ARGS__>::count> &Parent<Target>::value = array_of_classinfo<__VA_ARGS__>::value

#endif // PARENT_H