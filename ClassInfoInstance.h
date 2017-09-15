#ifndef CLASSINFOINSTANCE_H
#define CLASSINFOINSTANCE_H
#pragma once

#include <type_traits>
#include "vClassInfo.h"
#include "ClassInfo.h"
#include "TypeInfoInstance.h"
#include "trait_type.h"

template<typename T, typename ClassCXX = typename meta::get_baseType<T>::type>
struct trait_ClassInfoInstance : trait_TypeInfoInstance<ClassCXX>
{
    static_assert(std::is_class<ClassCXX>::value, "T is not a class");
    using class_t = ClassCXX;
    using name_t = typename ClassInfo<T>::name_t;
    using transtype_t = typename ClassInfo<ClassCXX>::transtype_t;
    using parent_t = typename ClassInfo<ClassCXX>::parent_t;
    using transtypeExt_t = typename ClassInfo<ClassCXX>::transtypeExt_t;
    using functionMember_t = typename ClassInfo<ClassCXX>::functionMeber_t;

    static inline std::string name() noexcept;
    static inline std::pair<const FunctionMemberInfo_t *, const FunctionMemberInfo_t *> members() noexcept;
    static inline std::pair<const ClassInfo_t *, const ClassInfo_t *> parents() noexcept;
};

template<typename T>
class ClassInfoInstance : public vClassInfo
{
public:
    constexpr ClassInfoInstance() noexcept;
    std::string name() const noexcept override;
    std::pair<const TypeInfo_t *, const TypeInfo_t *> transtypes() const noexcept override;
    std::pair<const vFunctionInfo *, const vFunctionInfo *> operators() const noexcept override;
    std::pair<const FunctionMemberInfo_t *, const FunctionMemberInfo_t *> members() const noexcept override;
    std::pair<const ClassInfo_t *, const ClassInfo_t *> parents() const noexcept override;
    std::pair<const TypeInfo_t *, const TypeInfo_t *> transtypesExt() const noexcept override;
};

B_SET_TYPE_NAME_GENERIC(ClassInfoInstance);

template<typename T, typename = typename std::enable_if<std::is_class<typename std::decay<T>::type>::value>::type>
ClassInfo_t make_type() noexcept;

#define B_DECLARE_CLASS_HPP(T) \
    template<> \
    class ClassInfoInstance<T> : public vClassInfo \
    { \
    public: \
        constexpr ClassInfoInstance() noexcept \
        {} \
        std::string name() const noexcept override; \
        std::pair<const TypeInfo_t *, const TypeInfo_t *> transtypes() const noexcept override; \
        std::pair<const vFunctionInfo *, const vFunctionInfo *> operators() const noexcept override; \
        std::pair<const TypeInfo_t *, const TypeInfo_t *> transtypesExt() const noexcept override; \
  \
        std::pair<const FunctionMemberInfo_t *, const FunctionMemberInfo_t *> members() const noexcept override; \
        std::pair<const ClassInfo_t *, const ClassInfo_t *> parents() const noexcept override; \
    }

#define B_DECLARE_CLASS_CPP(T) \
    std::string ClassInfoInstance<T>::name() const noexcept \
    { \
        return trait_ClassInfoInstance<T>::name(); \
    } \
  \
    std::pair<const TypeInfo_t *, const TypeInfo_t *> ClassInfoInstance<T>::transtypes() const noexcept \
    { \
        return trait_ClassInfoInstance<T>::transtypes(); \
    } \
  \
    std::pair<const vFunctionInfo *, const vFunctionInfo *> ClassInfoInstance<T>::operators() const noexcept \
    { \
        return trait_ClassInfoInstance<T>::operators(); \
    } \
  \
    std::pair<const FunctionMemberInfo_t *, const FunctionMemberInfo_t *> ClassInfoInstance<T>::members() const noexcept \
    { \
        return trait_ClassInfoInstance<T>::members(); \
    } \
  \
    std::pair<const ClassInfo_t *, const ClassInfo_t *> ClassInfoInstance<T>::parents() const noexcept \
    { \
        return trait_ClassInfoInstance<T>::parents(); \
    } \
  \
    std::pair<const TypeInfo_t *, const TypeInfo_t *> ClassInfoInstance<T>::transtypesExt() const noexcept \
    { \
        return trait_ClassInfoInstance<T>::transtypesExt(); \
    }

#endif // CLASSINFOINSTANCE_H
