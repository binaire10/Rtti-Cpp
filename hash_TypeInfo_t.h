/*!
 * \author Alexandre Wery
 * \file hash_TypeInfo_t.h
 * \brief Declaration of hash<TypeInfo_t> prototype
 * \date 04/09/2017
 */
#ifndef HASH_TYPEINFO_T_H
#define HASH_TYPEINFO_T_H

class TypeInfo_t;

namespace std {
    template<typename>
    struct hash;

    template<>
    struct hash<TypeInfo_t>
    {
        inline std::size_t operator ()(const TypeInfo_t &ci) const noexcept;
    };
}

#include "TypeInfo_t.h"

#endif // HASH_TYPEINFO_T_H
