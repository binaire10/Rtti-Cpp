#ifndef NAMETYPE_H
#define NAMETYPE_H
#pragma once

#include <Content.hpp>
#include <meta_ContentUtility.hpp>
#include <meta_MetaStringManipulator.hpp>

template<typename Type_t>
struct TemplateName
{
    using name_t = meta::Content<char>;
};

template<typename Type_t>
struct NameType
{
    static constexpr bool isLogged = false;
    using name_t = meta::Serialize<meta::Content<char, 'U', 'N', 'K', 'N', 'O', 'W', 'N'>, typename TemplateName<Type_t>::name_t >;
};

template<template<typename...> class Type_t, typename... arg>
struct TemplateName<Type_t<arg...> >
{
    using name_t = meta::Serialize<meta::Content<char, '<'>, meta::FormatArgument<meta::GetName<NameType<arg> >...>, meta::Content<char, '>'> >;
};

template<typename Type_t>
struct NameType<Type_t *>
{
    using last = typename NameType<Type_t>::name_t;
    using name_t = meta::Serialize<last, typename std::conditional<(meta::get_last_value_meta<last>::value)=='*', meta::Content<char, '*'>, meta::Content<char, ' ', '*'> >::type >;
};

template<typename Type_t>
struct NameType<Type_t &>
{
    using last = typename NameType<Type_t>::name_t;
    using name_t = meta::Serialize<last, typename std::conditional<(meta::get_last_value_meta<last>::value)=='*', meta::Content<char, '&'>, meta::Content<char, ' ', '&'> >::type >;
};

template<typename Type_t>
struct NameType<const Type_t>
{
    using name_t = typename std::conditional<!std::is_pointer<Type_t>::value, meta::Serialize<meta::Content<char, 'c', 'o', 'n', 's', 't', ' '>, typename NameType<Type_t>::name_t>, meta::Serialize<typename NameType<Type_t>::name_t, meta::Content<char, ' ', 'c', 'o', 'n', 's', 't'> > >::type;
};

template<typename Type_t>
struct NameType<volatile Type_t>
{
    using name_t = meta::Serialize<meta::Content<char, 'v', 'o', 'l', 'a', 't', 'i', 'l', 'e', ' '>, typename NameType<Type_t>::name_t>;
};

#define B_SET_MANUAL_TYPE_NAME(TagName, ...) \
struct NameType<__VA_ARGS__> \
{\
    static constexpr bool isLogged = true; \
    static constexpr char name[] = #TagName; \
    using name_t = meta::Serialize<meta::UnSerialize<char, sizeof(name), name>, typename TemplateName<__VA_ARGS__>::name_t >;\
}

#define B_SET_TYPE_NAME(T) \
    template<>\
    B_SET_MANUAL_TYPE_NAME(T, T)

#define B_SET_TYPE_NAME_GENERIC(T) \
    template<typename... arg>\
    B_SET_MANUAL_TYPE_NAME(T, T<arg...>)

B_SET_TYPE_NAME_GENERIC(NameType);

#endif // NAMETYPE_H
