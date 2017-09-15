#ifndef FUNCTIONMEMBERINFO_T_TPP
#define FUNCTIONMEMBERINFO_T_TPP

#include "FunctionMemberInfo_t.h"

template<typename T, typename = typename std::enable_if<std::is_base_of<vFunctionMemberInfoInstance, T>::value>::type>
FunctionMemberInfo_t make_element() noexcept
{
#if __cplusplus >= 201402L
    static FunctionMemberInfo_t typeInfo(v2::load_element(std::make_unique<T>()));
#else
    static FunctionMemberInfo_t typeInfo(v2::load_element(std::unique_ptr<vFunctionMemberInfoInstance>(new T)));
#endif
    return typeInfo;
}

#endif // FUNCTIONMEMBERINFO_T_TPP
