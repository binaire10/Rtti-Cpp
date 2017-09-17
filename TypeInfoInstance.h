#ifndef TYPEINFOINSTANCE_H
#define TYPEINFOINSTANCE_H

#include "TypeInfo.h"
#include "vTypeInfo.h"
#include "TypeInfo_t.h"

template<typename T>
struct trait_TypeInfoInstance
{
    using name_t = typename TypeInfo<T>::name_t;
    using transtype_t = typename TypeInfo<T>::transtype_t;
    using transtypeExt_t = typename TypeInfo<T>::transtypeExt_t;
    static inline std::string name() noexcept;
    static inline std::pair<const TypeInfo_t *, const TypeInfo_t *> transtypes() noexcept;
    static inline std::pair<const vFunctionInfo *, const vFunctionInfo *> operators() noexcept;
    static inline std::pair<const TypeInfo_t *, const TypeInfo_t *> transtypesExt() noexcept;
};

template<typename T>
class TypeInfoInstance : public vTypeInfo
{
public:
    constexpr TypeInfoInstance() noexcept;
    std::string name() const noexcept override;
    std::pair<const TypeInfo_t *, const TypeInfo_t *> transtypes() const noexcept override;
    std::pair<const vFunctionInfo *, const vFunctionInfo *> operators() const noexcept override;
    std::pair<const TypeInfo_t *, const TypeInfo_t *> transtypesExt() const noexcept override;
};

template<typename T, typename = typename std::enable_if<(std::is_fundamental<T>::value || std::is_pointer<T>::value) && NameType<T>::isLogged>::type>
TypeInfo_t make_type() noexcept;

#define B_DECLARE_TYPE_HPP(T)  \
    template<>\
    class TypeInfoInstance<T> : public vTypeInfo \
    { \
    public: \
        constexpr TypeInfoInstance() noexcept \
        {} \
        std::string name() const noexcept override; \
        std::pair<const vTypeInfo *, const vTypeInfo *> transtypes() const noexcept override; \
        std::pair<const vFunctionInfo *, const vFunctionInfo *> operators() const noexcept override; \
    }

#define B_EXPORT_DECLARE_TYPE_HPP(E, T)  \
    template<>\
    class E TypeInfoInstance<T> : public vTypeInfo \
    { \
    public: \
        constexpr TypeInfoInstance() noexcept \
        {} \
        std::string name() const noexcept override; \
        std::pair<const TypeInfo_t *, const TypeInfo_t *> transtypes() const noexcept override; \
        std::pair<const vFunctionInfo *, const vFunctionInfo *> operators() const noexcept override; \
        std::pair<const TypeInfo_t *, const TypeInfo_t *> transtypesExt() const noexcept override; \
    }

#define B_DECLARE_TYPE_CPP(T)  \
    std::string TypeInfoInstance<T>::name() const noexcept \
    { \
        return trait_TypeInfoInstance<T>::name(); \
    } \
 \
    std::pair<const TypeInfo_t *, const TypeInfo_t *> TypeInfoInstance<T>::transtypes() const noexcept \
    { \
        return trait_TypeInfoInstance<T>::transtypes();\
    } \
 \
    std::pair<const vFunctionInfo *, const vFunctionInfo *> TypeInfoInstance<T>::operators() const noexcept \
    { \
        return trait_TypeInfoInstance<T>::operators();\
    } \
 \
    std::pair<const TypeInfo_t *, const TypeInfo_t *> TypeInfoInstance<T>::transtypesExt() const noexcept override \
    { \
        return trait_TypeInfoInstance<T>::transtypesExt(); \
    }


#endif // TYPEINFOINSTANCE_H
