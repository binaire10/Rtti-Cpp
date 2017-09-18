#ifndef TRANSTYPE_H
#define TRANSTYPE_H
#pragma once

#include "arrayOf.h"
#include <meta_typestorage.h>

template<typename D, typename... T>
class Conversion_check
{
    using arguments_type = std::tuple<T...>;
    using argumentsSet_type = MakeSet<arguments_type>;
    template<typename From, typename To, typename = decltype(*static_cast<To *>(nullptr) = *static_cast<const From *>(nullptr))>
    static std::true_type cansTranstype(From *);
    template<typename From, typename To>
    static std::false_type cansTranstype(...);

    static_assert(b_and(decltype(cansTranstype<D, T>(nullptr))::value...), "class D cannot be transtype into T");
    static_assert(std::is_same<arguments_type, argumentsSet_type>(), "T already add int transtype array");
};

template<typename D, typename... T>
class ConversionExt_check
{
    using arguments_type = std::tuple<T...>;
    using argumentsSet_type = MakeSet<arguments_type>;
    template<typename From, typename To, typename = decltype(*static_cast<To *>(nullptr) = *static_cast<const From *>(nullptr))>
    static std::true_type cansTranstype(From *);
    template<typename From, typename To>
    static std::false_type cansTranstype(...);

    static_assert(b_and(decltype(cansTranstype<T, D>(nullptr))::value...), "class D cannot be transtype into T");
    static_assert(std::is_same<arguments_type, argumentsSet_type>(), "T already add int transtype array");
};

template<typename T>
struct Conversion : array_of_typeinfo<>
{};

template<typename T>
struct ConversionExt : array_of_typeinfo<>
{};

#define B_DECLARE_CONVERSION_HPP(Target, ...) \
    template<> \
    struct Conversion<Target> : Conversion_check<Target, __VA_ARGS__> \
    { \
        static const std::array<TypeInfo_t, meta::arg_size<__VA_ARGS__>::count> &value; \
        using types = std::tuple<__VA_ARGS__>;\
    }

#define B_DECLARE_CONVERSION_EXT_HPP(Target, ...) \
    template<> \
    struct ConversionExt<Target> : ConversionExt_check<Target, __VA_ARGS__> \
    { \
        static const std::array<TypeInfo_t, meta::arg_size<__VA_ARGS__>::count> &value; \
        using types = std::tuple<__VA_ARGS__>;\
    }

#define B_EXPORT_DECLARE_CONVERSION_HPP(E, Target, ...) \
    template<> \
    struct E Conversion<Target> : Conversion_check<Target, __VA_ARGS__> \
    { \
        static const std::array<TypeInfo_t, meta::arg_size<__VA_ARGS__>::count> &value; \
        using types = std::tuple<__VA_ARGS__>;\
    }

#define B_EXPORT_DECLARE_CONVERSION_EXT_HPP(E, Target, ...) \
    template<> \
    struct E ConversionExt<Target> : ConversionExt_check<Target, __VA_ARGS__> \
    { \
        static const std::array<TypeInfo_t, meta::arg_size<__VA_ARGS__>::count> &value; \
        using types = std::tuple<__VA_ARGS__>;\
    }

 #define B_DECLARE_CONVERSION_CPP(Target, ...) \
    const std::array<TypeInfo_t, meta::arg_size<__VA_ARGS__>::count> &Conversion<Target>::value = array_of_typeinfo<__VA_ARGS__>::value

#define B_DECLARE_CONVERSION_EXT_CPP(Target, ...) \
   const std::array<TypeInfo_t, meta::arg_size<__VA_ARGS__>::count> &ConversionExt<Target>::value = array_of_typeinfo<__VA_ARGS__>::value

#endif // TRANSTYPE_H
