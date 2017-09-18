#ifndef CLASSINFO_H
#define CLASSINFO_H
#pragma once

#include "TypeInfo.h"
#include "Parent.h"
#include "FunctionMember.h"

/*!
 * \struct ClassInfo
 * \brief Proxy to outside instrospective tool
 */

// it's a proxy class to outside information

template<typename T>
struct ClassInfo : TypeInfo<T>
{
    using parent_t = Parent<T>;
    using functionMember_t = FunctionMember<T>;
};

#endif // CLASSINFO_H
