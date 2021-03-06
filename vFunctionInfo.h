/*!
 * \author Alexandre Wery
 * \file vFunctionInfo.h
 * \brief Declaration of vFunctionInfo prototype
 * \date 04/09/2017
 */
#ifndef VFUNCTIONINFO_H
#define VFUNCTIONINFO_H
#pragma once

/*!
 * \class vFunctionInfo
 * \brief Interface to any function object info
 */

#include <string>

class TypeInfo_t;
class ClassInfo_t;

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
