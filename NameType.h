/*!
 * \author Alexandre Wery
 * \file NameType.h
 * \brief Declaration of NameType helper
 * \date 04/09/2017
 */
#ifndef NAMETYPE_H
#define NAMETYPE_H
#pragma once

/*!
 * \struct TemplateName
 * \brief generate the string of template arguments
 *
 * \struct NameType
 * \brief generate the string of name type
 *
 * \def B_SET_TYPE_NAME
 * \brief set name of type to make a best name type.
 *
 * \def B_SET_TYPE_NAME_GENERIC
 * \brief set name of generic name to make a best name type.
 */

#include <Content.hpp>
#include <meta_ContentUtility.hpp>
#include <meta_MetaStringManipulator.hpp>

template<typename Type_t>
struct TemplateName
{
    static constexpr bool isLogged = true;
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
    static constexpr bool isLogged = b_and(NameType<arg>::isLogged...);
    using name_t = meta::Serialize<meta::Content<char, '<'>, meta::FormatArgument<meta::GetName<NameType<arg> >...>, meta::Content<char, '>'> >;
};

#if __cplusplus >= 201402L
template<typename Type_t, std::size_t N>
struct NameType<Type_t [N]>
{
    using last = typename NameType<Type_t>::name_t;
    using name_t = meta::Serialize<last, meta::Content<char, '['> , meta::NumberToStr<N>, meta::Content<char, ']'> >;
};
#else
template<typename Type_t, std::size_t N>
struct NameType<Type_t [N]> : NameType<Type_t *>
{};
#endif

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
    static constexpr bool isLogged = TemplateName<__VA_ARGS__>::isLogged; \
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
