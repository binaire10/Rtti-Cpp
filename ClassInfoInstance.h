#ifndef CLASSINFOINSTANCE_H
#define CLASSINFOINSTANCE_H
#pragma once

#include <type_traits>
#include "vClassInfo.h"
#include "ClassInfo.h"
#include "TypeInfoInstance.h"
#include "trait_type.h"

/**
 * \class trait_ClassInfoInstance
 * \brief trait_ClassInfoInstance is class to store the code use into the ClassInfoInstance
 * \tparam T origine type. Can contains & / const symbole
 * \tparam ClassCXX true class type it work like a proxy to genererate right function of type T.
 *
 * \class ClassInfoInstance
 * \brief ClassInfoInstance is an instanciable type, one instance of this type must be existe.
 * This class cannot use singleton patern because I don't want to have more than one instance by type
 * and be compatible with any type of build.
 * \tparam T
 */

template<typename T>
class ClassInfoInstance;

template<typename T, typename ClassCXX = typename meta::get_baseType<T>::type>
struct trait_ClassInfoInstance : trait_TypeInfoInstance<ClassCXX>
{
    template<typename Ts, typename = decltype(ClassInfoInstance<Ts>::make_type())>
    static std::true_type hasMakeType(Ts *);
    template<typename Ts>
    static std::false_type hasMakeType(...);
    static constexpr bool declareMakeTyp = decltype(hasMakeType<T>(nullptr))();

    // static_assert(std::is_class<ClassCXX>::value, "T is not a class");
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
    using trait_t = trait_ClassInfoInstance<T>;
    constexpr ClassInfoInstance() noexcept;
    std::string name() const noexcept override;
    std::pair<const TypeInfo_t *, const TypeInfo_t *> transtypes() const noexcept override;
    std::pair<const vFunctionInfo *, const vFunctionInfo *> operators() const noexcept override;
    std::pair<const FunctionMemberInfo_t *, const FunctionMemberInfo_t *> members() const noexcept override;
    std::pair<const ClassInfo_t *, const ClassInfo_t *> parents() const noexcept override;
    std::pair<const TypeInfo_t *, const TypeInfo_t *> transtypesExt() const noexcept override;
};

B_SET_TYPE_NAME_GENERIC(ClassInfoInstance);

template<typename T, typename = typename std::enable_if<std::is_class<typename std::decay<T>::type>::value && NameType<T>::isLogged>::type>
ClassInfo_t make_type() noexcept;

#define B_DECLARE_CLASS_HPP(T) \
    template<> \
    class ClassInfoInstance<T> : public vClassInfo \
    { \
    public: \
        using trait_t = trait_ClassInfoInstance<T>; \
        constexpr ClassInfoInstance() noexcept \
        {} \
        std::string name() const noexcept override; \
        std::pair<const TypeInfo_t *, const TypeInfo_t *> transtypes() const noexcept override; \
        std::pair<const vFunctionInfo *, const vFunctionInfo *> operators() const noexcept override; \
        std::pair<const TypeInfo_t *, const TypeInfo_t *> transtypesExt() const noexcept override; \
  \
        std::pair<const FunctionMemberInfo_t *, const FunctionMemberInfo_t *> members() const noexcept override; \
        std::pair<const ClassInfo_t *, const ClassInfo_t *> parents() const noexcept override; \
        static ClassInfo_t make_type() noexcept; \
    }

#if __cplusplus >= 201402L
#define B_DECLARE_CLASS_CPP(T) \
    ClassInfo_t ClassInfoInstance<T>::make_type() noexcept \
    { \
        static ClassInfo_t typeInfo(reinterpret_cast<const vClassInfo *>(v2::load_type(std::make_unique<ClassInfoInstance<T>>()))); \
        return typeInfo; \
    } \
  \
    std::string ClassInfoInstance<T>::name() const noexcept \
    { \
        return trait_t::name(); \
    } \
  \
    std::pair<const TypeInfo_t *, const TypeInfo_t *> ClassInfoInstance<T>::transtypes() const noexcept \
    { \
        return trait_t::transtypes(); \
    } \
  \
    std::pair<const vFunctionInfo *, const vFunctionInfo *> ClassInfoInstance<T>::operators() const noexcept \
    { \
        return trait_t::operators(); \
    } \
  \
    std::pair<const FunctionMemberInfo_t *, const FunctionMemberInfo_t *> ClassInfoInstance<T>::members() const noexcept \
    { \
        return trait_t::members(); \
    } \
  \
    std::pair<const ClassInfo_t *, const ClassInfo_t *> ClassInfoInstance<T>::parents() const noexcept \
    { \
        return trait_t::parents(); \
    } \
  \
    std::pair<const TypeInfo_t *, const TypeInfo_t *> ClassInfoInstance<T>::transtypesExt() const noexcept \
    { \
        return trait_t::transtypesExt(); \
    }

#else
#define B_DECLARE_CLASS_CPP(T) \
    ClassInfo_t ClassInfoInstance<T>::make_type() noexcept \
    { \
        static ClassInfo_t typeInfo(reinterpret_cast<const vClassInfo *>(v2::load_type(std::unique_ptr<ClassInfoInstance<T>>(new ClassInfoInstance<T>)))); \
        return typeInfo; \
    } \
  \
    std::string ClassInfoInstance<T>::name() const noexcept \
    { \
        return trait_t::name(); \
    } \
  \
    std::pair<const TypeInfo_t *, const TypeInfo_t *> ClassInfoInstance<T>::transtypes() const noexcept \
    { \
        return trait_t::transtypes(); \
    } \
  \
    std::pair<const vFunctionInfo *, const vFunctionInfo *> ClassInfoInstance<T>::operators() const noexcept \
    { \
        return trait_t::operators(); \
    } \
  \
    std::pair<const FunctionMemberInfo_t *, const FunctionMemberInfo_t *> ClassInfoInstance<T>::members() const noexcept \
    { \
        return trait_t::members(); \
    } \
  \
    std::pair<const ClassInfo_t *, const ClassInfo_t *> ClassInfoInstance<T>::parents() const noexcept \
    { \
        return trait_t::parents(); \
    } \
  \
    std::pair<const TypeInfo_t *, const TypeInfo_t *> ClassInfoInstance<T>::transtypesExt() const noexcept \
    { \
        return trait_t::transtypesExt(); \
    }
#endif
#endif // CLASSINFOINSTANCE_H
