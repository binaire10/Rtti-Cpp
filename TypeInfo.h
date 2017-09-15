#ifndef TYPEINFO_H
#define TYPEINFO_H
#pragma once

#include "NameType.hpp"
#include "ElementName.hpp"
#include "Transtype.h"

template<typename type>
struct TypeInfo
{
    using name_t = typename NameType<type>::name_t;
    using transtype_t = Transtype<type>;
    using transtypeExt_t = TranstypeExt<type>;
};

#endif // TYPEINFO_H
