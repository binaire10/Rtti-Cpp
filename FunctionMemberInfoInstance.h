#ifndef VFUNCTIONMEMBER_H
#define VFUNCTIONMEMBER_H
#pragma once

#include <string>

#include "vMemberInfo.h"
#include "vFunctionInfo.h"
#include "trait_type.h"
#include "ElementName.h"
#include "arrayOf.h"

class TypeInfo_t;

template<typename FunctionMemberPtr_t, FunctionMemberPtr_t function>
struct trait_FunctionMemberInfoInstance
{
    using element_name_t = ElementName<FunctionMemberPtr_t, function>;

    using functionName_t = typename element_name_t::name_t;
    using memberName_t = typename element_name_t::name_t;

    using this_object_t = typename meta::trait_Member<FunctionMemberPtr_t>::this_object;
    using result_t = typename meta::trait_function<FunctionMemberPtr_t>::result_type;
    using argument_t = typename meta::trait_function<FunctionMemberPtr_t, array_of_typeinfo>::args_type;

    static inline std::string functionName() noexcept;
    static inline TypeInfo_t resultType() noexcept;
    static inline FunctionMemberPtr_t functionPtr() noexcept;
    static inline std::string memberName() noexcept;
    static inline ClassInfo_t thisObject() noexcept;
    static inline std::pair<const TypeInfo_t *, const TypeInfo_t *> argumentsType() noexcept;
};

class vFunctionMemberInfoInstance : public vMemberInfo, public vFunctionInfo
{};

template<typename FunctionMemberPtr_t, FunctionMemberPtr_t function>
class FunctionMemberInfoInstance : public vFunctionMemberInfoInstance, public vGetFunctionPtr<FunctionMemberPtr_t>
{
public:
    constexpr FunctionMemberInfoInstance() noexcept;
    std::string functionName() const noexcept override;
    TypeInfo_t resultType() const noexcept override;
    FunctionMemberPtr_t functionPtr() const noexcept;
    std::string memberName() const noexcept override;
    ClassInfo_t thisObject() const noexcept override;
    std::pair<const TypeInfo_t *, const TypeInfo_t *> argumentsType() const noexcept override;
};

#define B_DEV_DECLARE_FUNCTION_MEMBER_HPP(...) \
class FunctionMemberInfoInstance<decltype(__VA_ARGS__), __VA_ARGS__> : public vFunctionMemberInfoInstance, public vGetFunctionPtr<decltype(__VA_ARGS__)> \
{ \
public: \
    using FunctionMemberPtr_t = decltype(__VA_ARGS__); \
    constexpr FunctionMemberInfoInstance() noexcept \
    {} \
 \
    std::string functionName() const noexcept override; \
 \
    TypeInfo_t resultType() const noexcept override; \
 \
    FunctionMemberPtr_t functionPtr() const noexcept; \
 \
    std::string memberName() const noexcept override; \
 \
    ClassInfo_t thisObject() const noexcept override; \
 \
    std::pair<const TypeInfo_t *, const TypeInfo_t *> argumentsType() const noexcept override; \
}

#define B_DEV_EXPORT_DECLARE_FUNCTION_MEMBER_HPP(E, ...) \
class E FunctionMemberInfoInstance<decltype(__VA_ARGS__), __VA_ARGS__> : public vFunctionMemberInfoInstance, public vGetFunctionPtr<decltype(__VA_ARGS__)> \
{ \
public: \
    using FunctionMemberPtr_t = decltype(__VA_ARGS__); \
    constexpr FunctionMemberInfoInstance() noexcept \
    {} \
 \
    std::string functionName() const noexcept override; \
 \
    TypeInfo_t resultType() const noexcept override; \
 \
    FunctionMemberPtr_t functionPtr() const noexcept; \
 \
    std::string memberName() const noexcept override; \
 \
    ClassInfo_t thisObject() const noexcept override; \
 \
    std::pair<const TypeInfo_t *, const TypeInfo_t *> argumentsType() const noexcept override; \
}

#define B_DECLARE_FUNCTION_MEMBER_HPP(...) template<> B_DEV_DECLARE_FUNCTION_MEMBER_HPP(__VA_ARGS__)
#define B_EXPORT_DECLARE_FUNCTION_MEMBER_HPP(E, ...) template<> B_DEV_EXPORT_DECLARE_FUNCTION_MEMBER_HPP(E, __VA_ARGS__)
#define B_DECLARE_FUNCTION_MEMBER_CPP(...) \
std::string FunctionMemberInfoInstance<decltype(__VA_ARGS__), __VA_ARGS__>::functionName() const noexcept \
{ \
    return trait_FunctionMemberInfoInstance<decltype(__VA_ARGS__), __VA_ARGS__>::functionName(); \
} \
 \
TypeInfo_t FunctionMemberInfoInstance<decltype(__VA_ARGS__), __VA_ARGS__>::resultType() const noexcept \
{ \
    return trait_FunctionMemberInfoInstance<decltype(__VA_ARGS__), __VA_ARGS__>::resultType(); \
} \
 \
decltype(__VA_ARGS__) FunctionMemberInfoInstance<decltype(__VA_ARGS__), __VA_ARGS__>::functionPtr() const noexcept \
{ \
    return trait_FunctionMemberInfoInstance<decltype(__VA_ARGS__), __VA_ARGS__>::functionPtr(); \
} \
 \
std::string FunctionMemberInfoInstance<decltype(__VA_ARGS__), __VA_ARGS__>::memberName() const noexcept \
{ \
    return trait_FunctionMemberInfoInstance<decltype(__VA_ARGS__), __VA_ARGS__>::memberName(); \
} \
 \
ClassInfo_t FunctionMemberInfoInstance<decltype(__VA_ARGS__), __VA_ARGS__>::thisObject() const noexcept \
{ \
    return trait_FunctionMemberInfoInstance<decltype(__VA_ARGS__), __VA_ARGS__>::thisObject(); \
} \
 \
std::pair<const TypeInfo_t *, const TypeInfo_t *> FunctionMemberInfoInstance<decltype(__VA_ARGS__), __VA_ARGS__>::argumentsType() const noexcept \
{ \
    return trait_FunctionMemberInfoInstance<decltype(__VA_ARGS__), __VA_ARGS__>::argumentsType(); \
}

#define B_MAKE_FUNCTION_MEMBER_TYPE(T) FunctionMemberInfoInstance<decltype(T), T>

#endif // VFUNCTIONMEMBER_H
