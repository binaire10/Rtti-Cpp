#ifndef HASH_PAIR_H
#define HASH_PAIR_H

#include <utility>

namespace std {
    template<typename>
    struct hash;

    template<typename T1, typename T2>
    struct hash<std::pair<T1, T2> >
    {
        std::size_t operator ()(const std::pair<T1, T2> &ci) const noexcept;
    };
}

#endif // HASH_PAIR_H
