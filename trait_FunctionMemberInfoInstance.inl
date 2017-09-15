#ifndef TRAIT_FUNCTIONMEMBERINFOINSTANCE_INL
#define TRAIT_FUNCTIONMEMBERINFOINSTANCE_INL
#pragma once

#include "FunctionMemberInfoInstance.h"

template<typename FunctionMemberPtr_t, FunctionMemberPtr_t function>
inline std::string trait_FunctionMemberInfoInstance<FunctionMemberPtr_t, function>::functionName() noexcept
{
    return std::string(functionName_t());
}

template<typename FunctionMemberPtr_t, FunctionMemberPtr_t function>
inline TypeInfo_t trait_FunctionMemberInfoInstance<FunctionMemberPtr_t, function>::resultType() noexcept
{
    return make_type<result_t>();
}

template<typename FunctionMemberPtr_t, FunctionMemberPtr_t function>
inline FunctionMemberPtr_t trait_FunctionMemberInfoInstance<FunctionMemberPtr_t, function>::functionPtr() noexcept
{
    return function;
}

template<typename FunctionMemberPtr_t, FunctionMemberPtr_t function>
inline std::string trait_FunctionMemberInfoInstance<FunctionMemberPtr_t, function>::memberName() noexcept
{
    return std::string(memberName_t());
}

template<typename FunctionMemberPtr_t, FunctionMemberPtr_t function>
inline ClassInfo_t trait_FunctionMemberInfoInstance<FunctionMemberPtr_t, function>::thisObject() noexcept
{
    return make_type<this_object_t>();
}

template<typename FunctionMemberPtr_t, FunctionMemberPtr_t function>
inline std::pair<const TypeInfo_t *, const TypeInfo_t *> trait_FunctionMemberInfoInstance<FunctionMemberPtr_t, function>::argumentsType() noexcept
{
    return {&argument_t::value.front(), &argument_t::value[argument_t::value.size()]};
}

#endif // TRAIT_FUNCTIONMEMBERINFOINSTANCE_INL
