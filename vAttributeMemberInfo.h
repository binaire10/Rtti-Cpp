#ifndef VATTRIBUTEMEMBER_H
#define VATTRIBUTEMEMBER_H
#pragma once

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
