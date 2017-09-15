#ifndef VCLASSINFO_H
#define VCLASSINFO_H
#pragma once

#include "vTypeInfo.h"

class ClassInfo_t;
class FunctionMemberInfo_t;
class vClassInfo : public vTypeInfo
{
public:
    constexpr vClassInfo() noexcept
    {}
    inline ~vClassInfo() noexcept
    {}
    virtual std::pair<const FunctionMemberInfo_t *, const FunctionMemberInfo_t *> members() const noexcept = undefined;
    virtual std::pair<const ClassInfo_t *, const ClassInfo_t *> parents() const noexcept = undefined;
};

#include "ClassInfo_t.h"
#include "FunctionMemberInfo_t.h"

#endif // VCLASSINFO_H
