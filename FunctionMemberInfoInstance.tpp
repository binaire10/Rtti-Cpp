#ifndef FUNCTIONMEMBERINFOINSTANCE_TPP
#define FUNCTIONMEMBERINFOINSTANCE_TPP
#pragma once

#include "FunctionMemberInfoInstance.h"

template<typename FunctionMemberPtr_t, FunctionMemberPtr_t function>
constexpr FunctionMemberInfoInstance<FunctionMemberPtr_t, function>::FunctionMemberInfoInstance() noexcept
{}

template<typename FunctionMemberPtr_t, FunctionMemberPtr_t function>
std::string FunctionMemberInfoInstance<FunctionMemberPtr_t, function>::functionName() const noexcept
{
    return trait_FunctionMemberInfoInstance<FunctionMemberPtr_t, function>::functionName();
}

template<typename FunctionMemberPtr_t, FunctionMemberPtr_t function>
TypeInfo_t FunctionMemberInfoInstance<FunctionMemberPtr_t, function>::resultType() const noexcept
{
    return trait_FunctionMemberInfoInstance<FunctionMemberPtr_t, function>::resultType();
}

template<typename FunctionMemberPtr_t, FunctionMemberPtr_t function>
FunctionMemberPtr_t FunctionMemberInfoInstance<FunctionMemberPtr_t, function>::functionPtr() const noexcept
{
    return trait_FunctionMemberInfoInstance<FunctionMemberPtr_t, function>::functionPtr();
}

template<typename FunctionMemberPtr_t, FunctionMemberPtr_t function>
std::string FunctionMemberInfoInstance<FunctionMemberPtr_t, function>::memberName() const noexcept
{
    return trait_FunctionMemberInfoInstance<FunctionMemberPtr_t, function>::memberName();
}

template<typename FunctionMemberPtr_t, FunctionMemberPtr_t function>
ClassInfo_t FunctionMemberInfoInstance<FunctionMemberPtr_t, function>::thisObject() const noexcept
{
    return trait_FunctionMemberInfoInstance<FunctionMemberPtr_t, function>::thisObject();
}

template<typename FunctionMemberPtr_t, FunctionMemberPtr_t function>
std::pair<const TypeInfo_t *, const TypeInfo_t *> FunctionMemberInfoInstance<FunctionMemberPtr_t, function>::argumentsType() const noexcept
{
    return trait_FunctionMemberInfoInstance<FunctionMemberPtr_t, function>::argumentsType();
}

#include "trait_FunctionMemberInfoInstance.inl"

#endif // FUNCTIONMEMBERINFOINSTANCE_TPP
