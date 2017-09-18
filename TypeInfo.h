#ifndef TYPEINFO_H
#define TYPEINFO_H
#pragma once

#include "NameType.h"
#include "ElementName.h"
#include "Conversion.h"

template<typename type>
struct TypeInfo
{
    using name_t = typename NameType<type>::name_t;
    using transtype_t = Conversion<type>;
    using transtypeExt_t = ConversionExt<type>;
};

#endif // TYPEINFO_H
