/*!
 * \author Alexandre Wery
 * \file TypeInfo.h
 * \brief Declaration of TypeInfo prototype
 * \date 04/09/2017
 */
#ifndef TYPEINFO_H
#define TYPEINFO_H
#pragma once

/*!
 * \struct TypeInfo
 * \brief Proxy class to any type info.
 * \typedef TypeInfo::name_t
 * \brief store the name of type
 */

#include "NameType.h"
#include "ElementName.h"
#include "Conversion.h"

template<typename type>
struct TypeInfo
{
    using name_t = typename NameType<type>::name_t;
    using conversion_t = Conversion<type>;
    using conversionExt_t = ConversionExt<type>;
};

#endif // TYPEINFO_H
