#ifndef VFUNCTIONINFO_H
#define VFUNCTIONINFO_H
#pragma once

#include <string>

class TypeInfo_t;
class ClassInfo_t;

template<typename T, typename = typename std::enable_if<std::is_class<typename std::remove_reference<T>::type>::value>::type>
ClassInfo_t make_type() noexcept;
template<typename T, typename = typename std::enable_if<std::is_fundamental<T>::value || std::is_pointer<T>::value>::type>
TypeInfo_t make_type() noexcept;

class vFunctionInfo
{
public:
    constexpr vFunctionInfo() noexcept
    {}
    virtual inline ~vFunctionInfo() noexcept
    {}
    virtual std::string functionName() const noexcept = undefined;
    virtual TypeInfo_t resultType() const noexcept = undefined;
    virtual std::pair<const TypeInfo_t *, const TypeInfo_t *> argumentsType() const noexcept = undefined;
};

template<typename FunctionPtr_t>
class vGetFunctionPtr
{
public:
    constexpr vGetFunctionPtr() noexcept
    {}
    virtual inline ~vGetFunctionPtr() noexcept
    {}
    virtual FunctionPtr_t functionPtr() const noexcept = undefined;
};

#endif // VFUNCTIONINFO_H
