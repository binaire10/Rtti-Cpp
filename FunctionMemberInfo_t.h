#ifndef FUNCTIONMEMBERINFO_T_H
#define FUNCTIONMEMBERINFO_T_H
#pragma once

#include <string>
#include "TypeInfo_t.h"
#include <vector>
#include <type_traits>
#include <memory>

class vFunctionMemberInfoInstance;

class FunctionMemberInfo_t
{
public:
    FunctionMemberInfo_t() noexcept;
    FunctionMemberInfo_t(vFunctionMemberInfoInstance *) noexcept;
    std::string functionName() const noexcept;
    std::string memberName() const noexcept;
    TypeInfo_t thisObject() const noexcept;
    void getArguments(std::vector<TypeInfo_t> &) const noexcept;
    bool operator <(const FunctionMemberInfo_t &) const noexcept;
    bool operator ==(const FunctionMemberInfo_t &) const noexcept;
    bool operator >(const FunctionMemberInfo_t &) const noexcept;
    bool operator !=(const FunctionMemberInfo_t &) const noexcept;

private:
    vFunctionMemberInfoInstance *d_ptr;
};

namespace v2 {
    vFunctionMemberInfoInstance *load_element(std::unique_ptr<vFunctionMemberInfoInstance> &) noexcept;
    vFunctionMemberInfoInstance *load_element(std::unique_ptr<vFunctionMemberInfoInstance> &&) noexcept;
}

template<typename T, typename = typename std::enable_if<std::is_base_of<vFunctionMemberInfoInstance, T>::value>::type>
FunctionMemberInfo_t make_element() noexcept;

#endif // FUNCTIONMEMBERINFO_T_H
