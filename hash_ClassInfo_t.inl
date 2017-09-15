#ifndef HASH_CLASSINFO_T_INL
#define HASH_CLASSINFO_T_INL

#include "hash_ClassInfo_t.h"

inline std::size_t std::hash<ClassInfo_t>::operator ()(const ClassInfo_t &ci) const noexcept
{
    return hash<const void *>()(ci.d_ptr);
}

#endif // HASH_CLASSINFO_T_INL
