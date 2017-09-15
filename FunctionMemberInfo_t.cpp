#include "FunctionMemberInfo_t.h"
#include "FunctionMemberInfoInstance.h"
#include <map>
#include <memory>
#include <unordered_map>
#include "hash_ClassInfo_t.hpp"
#include "hash_pair.hpp"
#include <memory>

namespace {
    std::map<std::pair<std::string, ClassInfo_t>, std::unique_ptr<vFunctionMemberInfoInstance> > &instance_functionMember() noexcept
    {
        static std::map<std::pair<std::string, ClassInfo_t>, std::unique_ptr<vFunctionMemberInfoInstance> > instance;
        return instance;
    }
}

FunctionMemberInfo_t::FunctionMemberInfo_t() noexcept : d_ptr(nullptr)
{}

FunctionMemberInfo_t::FunctionMemberInfo_t(vFunctionMemberInfoInstance *ptr) noexcept : d_ptr(ptr)
{}

std::string FunctionMemberInfo_t::functionName() const noexcept
{
    return d_ptr->functionName();
}

std::string FunctionMemberInfo_t::memberName() const noexcept
{
    return d_ptr->memberName();
}

TypeInfo_t FunctionMemberInfo_t::thisObject() const noexcept
{
    return d_ptr->thisObject();
}

void FunctionMemberInfo_t::getArguments(std::vector<TypeInfo_t> &c) const noexcept
{
    c.resize(0);
    auto pTab = d_ptr->argumentsType();
    c.insert(c.begin(), pTab.first, pTab.second);
}

bool FunctionMemberInfo_t::operator <(const FunctionMemberInfo_t &value) const noexcept
{
    return d_ptr < value.d_ptr;
}

bool FunctionMemberInfo_t::operator ==(const FunctionMemberInfo_t &value) const noexcept
{
    return d_ptr == value.d_ptr;
}

bool FunctionMemberInfo_t::operator >(const FunctionMemberInfo_t &value) const noexcept
{
    return d_ptr > value.d_ptr;
}

bool FunctionMemberInfo_t::operator !=(const FunctionMemberInfo_t &value) const noexcept
{
    return d_ptr != value.d_ptr;
}

vFunctionMemberInfoInstance *v2::load_element(std::unique_ptr<vFunctionMemberInfoInstance> &t) noexcept
{
    std::map<std::pair<std::string, ClassInfo_t>, std::unique_ptr<vFunctionMemberInfoInstance>>  &i = instance_functionMember();
    std::map<std::pair<std::string, ClassInfo_t>, std::unique_ptr<vFunctionMemberInfoInstance>>::const_iterator it = i.find({t->memberName(), t->thisObject()});
    if(it == i.end())
    {
        std::pair<std::string, ClassInfo_t> key = {t->memberName(), t->thisObject()};
        i[key] = std::move(t);
    }
    return it->second.get();
}

vFunctionMemberInfoInstance *v2::load_element(std::unique_ptr<vFunctionMemberInfoInstance> &&t) noexcept
{
    std::map<std::pair<std::string, ClassInfo_t>, std::unique_ptr<vFunctionMemberInfoInstance>>  &i = instance_functionMember();
    std::map<std::pair<std::string, ClassInfo_t>, std::unique_ptr<vFunctionMemberInfoInstance>>::const_iterator it = i.find({t->memberName(), t->thisObject()});
    if(it == i.end())
    {
        vFunctionMemberInfoInstance *inst = t.get();
        std::pair<std::string, ClassInfo_t> key = {t->memberName(), t->thisObject()};
        i[key] = std::move(t);
        return inst;
    }
    return it->second.get();
}
