/*!
 * \author Alexandre Wery
 * \file hash_ClassInfo_t.h
 * \brief Declaration of hash<ClassInfo_t> prototype
 * \date 04/09/2017
 */
#ifndef HASH_CLASSINFO_T_H
#define HASH_CLASSINFO_T_H

#include "ClassInfo_t.h"

namespace std {
    template<typename>
    struct hash;

    template<>
    struct hash<ClassInfo_t>
    {
        inline std::size_t operator ()(const ClassInfo_t &ci) const noexcept;
    };
}

#endif // HASH_CLASSINFO_T_H
