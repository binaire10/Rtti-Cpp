/*!
 * \author Alexandre Wery
 * \file ClassInfo_t.h
 * \brief Declaration of ClassInfo_t class
 * \date 04/09/2017
 */
#ifndef CLASSINFO_T_H
#define CLASSINFO_T_H

/*!
 * \class ClassInfo_t
 * \brief ClassInfo_t is an instanciable class who allow to do dynamic introspection.
 */

#include <string>
#include "TypeInfo_t.h"

class vClassInfo;
class FunctionMemberInfo_t;
class ClassInfo_t
{
    friend struct std::hash<ClassInfo_t>;
public:
    ClassInfo_t() noexcept;
    ClassInfo_t(const vClassInfo *) noexcept;
    operator TypeInfo_t() const noexcept;
    std::string name() const noexcept;
    bool canBeTranstypeInto(const TypeInfo_t &) const noexcept;
    bool isDerivedOf(const ClassInfo_t &) const noexcept;
    void getTranstype(std::vector<TypeInfo_t> &) const noexcept;
    void getParents(std::vector<ClassInfo_t> &) const noexcept;
    void getFunctionMemberInfo(std::vector<FunctionMemberInfo_t> &) const noexcept;
    bool operator ==(const ClassInfo_t &) const noexcept;
    bool operator !=(const ClassInfo_t &) const noexcept;
    bool operator <(const ClassInfo_t &) const noexcept;
    bool operator >(const ClassInfo_t &) const noexcept;

private:
    const vClassInfo *d_ptr;
};

ClassInfo_t import(const TypeInfo_t &);

#include "FunctionMemberInfo_t.h"

#endif // CLASSINFO_T_H
