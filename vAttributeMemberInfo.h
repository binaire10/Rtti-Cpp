/*!
 * \author Alexandre Wery
 * \file vAttributeMemberInfo.h
 * \brief Declaration of vAttributeMemberInfo prototype
 * \date 04/09/2017
 */
#ifndef VATTRIBUTEMEMBER_H
#define VATTRIBUTEMEMBER_H
#pragma once

/*!
 * Interface to any Interface Object
 */

#include "vMemberInfo.h"

class vTypeInfo;

template<typename Cast>
class vAttributeMember : public vMemberInfo
{
public:
    constexpr vAttributeMember() noexcept
    {}
    virtual Cast attribute() const noexcept = undefined;
    virtual TypeInfo_t attributeType() const noexcept = undefined;
};

#endif // VATTRIBUTEMEMBER_H
