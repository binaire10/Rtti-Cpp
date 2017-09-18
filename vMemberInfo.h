#ifndef VMEMBERINFO_H
#define VMEMBERINFO_H

/*!
 * \class vMemberInfo
 * \brief class to any Object Member
 */

#include <string>

class ClassInfo_t;

class vMemberInfo
{
public:
    constexpr vMemberInfo() noexcept
    {}
    virtual inline ~vMemberInfo() noexcept
    {}
    virtual std::string memberName() const noexcept = undefined;
    virtual ClassInfo_t thisObject() const noexcept = undefined;
};

#include "ClassInfo_t.h"

#endif // VMEMBERINFO_H
