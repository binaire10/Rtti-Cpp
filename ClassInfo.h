#ifndef CLASSINFO_H
#define CLASSINFO_H
#pragma once

#include "TypeInfo.h"
#include "Parent.h"

template<typename>
struct FunctionMember;
template<typename T>
struct ClassInfo : TypeInfo<T>
{
    using parent_t = Parent<T>;
    using functionMeber_t = FunctionMember<T>;
};

#include "FunctionMember.h"

#endif // CLASSINFO_H
