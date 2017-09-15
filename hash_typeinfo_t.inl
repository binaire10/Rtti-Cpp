#ifndef HASH_TYPEINFO_T_INL
#define HASH_TYPEINFO_T_INL

#include "hash_TypeInfo_t.h"

inline std::size_t std::hash<TypeInfo_t>::operator ()(const TypeInfo_t &ci) const noexcept
{
    return hash<const void *>()(ci.d_ptr);
}

#endif // HASH_TYPEINFO_T_INL
