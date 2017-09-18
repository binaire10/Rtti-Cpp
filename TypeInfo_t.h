/*!
 * \author Alexandre Wery
 * \file TypeInfo_t.h
 * \brief Declaration of TypeInfo_t prototype
 * \date 04/09/2017
 */
#ifndef TYPEINFO_T_H
#define TYPEINFO_T_H
#pragma once

#include <string>
#include <vector>

class vTypeInfo;
class ClassInfo_t;
class TypeInfo_t;
ClassInfo_t import(const TypeInfo_t &);
class TypeInfo_t
{
    friend ClassInfo_t import(const TypeInfo_t &);
    friend class ClassInfo_t;
    friend struct std::hash<TypeInfo_t>;
public:
    TypeInfo_t() noexcept;
    TypeInfo_t(const vTypeInfo *) noexcept;
    std::string name() const noexcept;
    void getTranstypes(std::vector<TypeInfo_t> &) const noexcept;
    bool canBeTranstypeInto(const TypeInfo_t &t) const noexcept;
    bool operator ==(const TypeInfo_t &) const noexcept;
    bool operator !=(const TypeInfo_t &) const noexcept;
    bool operator <(const TypeInfo_t &) const noexcept;
    bool operator >(const TypeInfo_t &) const noexcept;


private:
    const vTypeInfo *d_ptr;
};

#include "ClassInfo_t.h"

#endif // TYPEINFO_T_H
