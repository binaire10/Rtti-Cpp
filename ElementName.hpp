#ifndef ELEMENTNAME_H
#define ELEMENTNAME_H
#pragma once

#include <meta_MetaStringManipulator.hpp>
#include "NameType.hpp"

template<typename Prototype, Prototype element_ptr>
struct ElementName
{
    static constexpr bool isLogged = false;
    using name_t = meta::Serialize<meta::Content<char, 'U', 'N', 'K', 'N', 'O', 'W', 'N'>>;
    using type = Prototype;
};

#define B_SET_ELEMENT_NAME(E, ...) \
    template<> \
    struct ElementName<__VA_ARGS__, E> \
    { \
        static constexpr bool isLogged = true; \
        MAKE_STRING(name, #E); \
    }

#define B_SET_ELEMENT_NAME_EASY(E) B_SET_ELEMENT_NAME(E, decltype(E))


#endif // ELEMENTNAME_H
