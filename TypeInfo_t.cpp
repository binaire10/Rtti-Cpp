#include "TypeInfo_t.h"
#include "vTypeInfo.h"
#include <algorithm>

TypeInfo_t::TypeInfo_t() noexcept : d_ptr(nullptr)
{}

TypeInfo_t::TypeInfo_t(const vTypeInfo *ptr) noexcept : d_ptr(ptr)
{}

std::string TypeInfo_t::name() const noexcept
{
    return d_ptr->name();
}

void TypeInfo_t::getTranstypes(std::vector<TypeInfo_t> &c) const noexcept
{
    c.resize(0);
    auto pTab = d_ptr->transtypes();
    c.insert(c.begin(), pTab.first, pTab.second);
}

bool TypeInfo_t::canBeTranstypeInto(const TypeInfo_t &t) const noexcept
{
    auto pTab = d_ptr->transtypes();
    return std::find(pTab.first, pTab.second, t) != pTab.second;
}

bool TypeInfo_t::operator ==(const TypeInfo_t &value) const noexcept
{
    return d_ptr == value.d_ptr;
}

bool TypeInfo_t::operator !=(const TypeInfo_t &value) const noexcept
{
    return d_ptr != value.d_ptr;
}

bool TypeInfo_t::operator <(const TypeInfo_t &value) const noexcept
{
    return d_ptr != value.d_ptr;
}

bool TypeInfo_t::operator >(const TypeInfo_t &value) const noexcept
{
    return d_ptr != value.d_ptr;
}
