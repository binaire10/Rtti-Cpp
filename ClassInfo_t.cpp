/*!
 * \author Alexandre Wery
 * \file ClassInfo_t.cpp
 * \brief Implementation of the instance of type
 * \date 04/09/2017
 */
#include "ClassInfo_t.h"
#include "vClassInfo.h"
#include <iostream>
#include <algorithm>
#include <typeinfo>

ClassInfo_t::ClassInfo_t() noexcept : d_ptr(nullptr)
{}

ClassInfo_t::ClassInfo_t(const vClassInfo *ptr) noexcept : d_ptr(ptr)
{}

ClassInfo_t::operator TypeInfo_t() const noexcept
{
    return TypeInfo_t(d_ptr);
}

std::string ClassInfo_t::name() const noexcept
{
    return d_ptr->name();
}

bool ClassInfo_t::canBeTranstypeInto(const TypeInfo_t &t) const noexcept
{
    auto pTab = d_ptr->transtypes();
    auto pTabExt = t.d_ptr->transtypesExt();
    return std::find(pTab.first, pTab.second, t) != pTab.second || std::find(pTabExt.first, pTabExt.second, TypeInfo_t(*this)) != pTabExt.second;
}

bool ClassInfo_t::isDerivedOf(const ClassInfo_t &t) const noexcept
{
    auto pTab = d_ptr->parents();
    return std::find(pTab.first, pTab.second, t) != pTab.second;
}

void ClassInfo_t::getTranstype(std::vector<TypeInfo_t> &c) const noexcept
{
    c.resize(0);
    auto pTab = d_ptr->transtypes();
    c.insert(c.begin(), pTab.first, pTab.second);
}

void ClassInfo_t::getParents(std::vector<ClassInfo_t> &c) const noexcept
{
    c.resize(0);
    auto pTab = d_ptr->parents();
    c.insert(c.begin(), pTab.first, pTab.second);
}

void ClassInfo_t::getFunctionMemberInfo(std::vector<FunctionMemberInfo_t> &c) const noexcept
{
    c.resize(0);
    auto pTab = d_ptr->members();
    c.insert(c.begin(), pTab.first, pTab.second);
}

bool ClassInfo_t::operator ==(const ClassInfo_t &value) const noexcept
{
    return d_ptr == value.d_ptr;
}

bool ClassInfo_t::operator !=(const ClassInfo_t &value) const noexcept
{
    return d_ptr != value.d_ptr;
}

bool ClassInfo_t::operator <(const ClassInfo_t &value) const noexcept
{
    return d_ptr < value.d_ptr;
}

bool ClassInfo_t::operator >(const ClassInfo_t &value) const noexcept
{
    return d_ptr > value.d_ptr;
}

ClassInfo_t import(const TypeInfo_t &c)
{
    return ClassInfo_t(&dynamic_cast<const vClassInfo &>(*c.d_ptr));
}
