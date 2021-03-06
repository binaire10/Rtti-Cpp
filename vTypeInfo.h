/*!
 * \author Alexandre Wery
 * \file vTypeInfo.h
 * \brief Declaration of vTypeInfo prototype
 * \date 04/09/2017
 */
#ifndef VTYPEINFO_H
#define VTYPEINFO_H
#pragma once

/*!
 * \class vTypeInfo
 * \brief Interface of any type info cast
 */

#include <string>
#include "vFunctionInfo.h"

class TypeInfo_t;
class vTypeInfo
{
public:
    constexpr vTypeInfo() noexcept
    {}
    virtual inline ~vTypeInfo() noexcept
    {}
    virtual std::string name() const noexcept = undefined;
    virtual std::pair<const TypeInfo_t *, const TypeInfo_t *> transtypes() const noexcept = undefined;
    virtual std::pair<const TypeInfo_t *, const TypeInfo_t *> transtypesExt() const noexcept = undefined;
    virtual std::pair<const vFunctionInfo *, const vFunctionInfo *> operators() const noexcept = undefined;
};

#endif // VTYPEINFO_H
