#ifndef HASH_PAIR_TPP
#define HASH_PAIR_TPP

#include "hash_pair.h"


template<typename T1, typename T2>
std::size_t std::hash<std::pair<T1, T2>>::operator ()(const std::pair<T1, T2> &ci) const noexcept
{
    // see http://en.cppreference.com/w/cpp/utility/hash
    return std::hash<T1>()(ci.first) ^ (std::hash<T2>()(ci.second) << 1);
}

#endif // HASH_PAIR_TPP
