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
    using type_t = T;
    using trait_t = trait_TypeInfoInstance<type_t>;
    using name_t = typename trait_t::name_t;
    using transtype_t = typename trait_t::transtype_t;
    using transtypeExt_t = typename trait_t::transtypeExt_t;
    constexpr TypeInfoInstance() noexcept;
    std::string name() const noexcept override;
    std::pair<const TypeInfo_t *, const TypeInfo_t *> transtypes() const noexcept override;
    std::pair<const vFunctionInfo *, const vFunctionInfo *> operators() const noexcept override;
    std::pair<const TypeInfo_t *, const TypeInfo_t *> transtypesExt() const noexcept override;
};

template<typename T, template<typename> class C>
struct _CheckMakeType
{
    template<typename Ts, typename = decltype(C<Ts>::make_type())>
    static std::true_type hasMakeType(Ts *);
    template<typename Ts>
    static std::false_type hasMakeType(...);
    static constexpr bool declareMakeType = decltype(hasMakeType<T>(nullptr))();
};

template<typename T, template<typename> class C, bool d= _CheckMakeType<T, C>::declareMakeType, bool c= std::is_class<typename std::decay<T>::type>::value, bool f= std::is_fundamental<T>::value || std::is_pointer<T>::value, bool l= NameType<T>::isLogged>
struct _MakeType
{};

template<typename T, template<typename> class C, bool a>
struct _MakeType<T, C, a, false, true, true> // requier logged fundamental
{
    using autoType = TypeInfo_t;
};

template<typename T, template<typename> class C>
struct _MakeType<T, C, true, false, true, true>
{
    using builtinMakeType = TypeInfo_t;
};

template<typename T, template<typename> class C, bool a>
struct _MakeType<T, C, a, true, false, true> // requier logged class
{
    using autoClass = ClassInfo_t;
};

template<typename T, template<typename> class C>
struct _MakeType<T, C, true, true, false, true>
{
    using builtinMakeClass = ClassInfo_t;
};

template<typename T>
typename _MakeType<T, TypeInfoInstance>::autoType make_type() noexcept;

template<typename T>
typename _MakeType<T, TypeInfoInstance>::builtinMakeType make_type() noexcept;

#define B_DECLARE_TYPE_HPP(T)  \
    template<>\
    class TypeInfoInstance<T> : public vTypeInfo \
    { \
    public: \
        using type_t = T; \
        using trait_t = trait_TypeInfoInstance<type_t>; \
        using name_t = typename trait_t::name_t; \
        using transtype_t = typename trait_t::transtype_t; \
        using transtypeExt_t = typename trait_t::transtypeExt_t; \
        constexpr TypeInfoInstance() noexcept \
        {} \
        std::string name() const noexcept override; \
        std::pair<const TypeInfo_t *, const TypeInfo_t *> transtypes() const noexcept override; \
        std::pair<const vFunctionInfo *, const vFunctionInfo *> operators() const noexcept override; \
        std::pair<const TypeInfo_t *, const TypeInfo_t *> transtypesExt() const noexcept override; \
        static TypeInfo_t make_type() noexcept; \
    }

#define B_EXPORT_DECLARE_TYPE_HPP(E, T)  \
    template<>\
    class E TypeInfoInstance<T> : public vTypeInfo \
    { \
    public: \
        using type_t = T; \
        using trait_t = trait_TypeInfoInstance<type_t>; \
        using name_t = typename trait_t::name_t; \
        using transtype_t = typename trait_t::transtype_t; \
        using transtypeExt_t = typename trait_t::transtypeExt_t; \
        constexpr TypeInfoInstance() noexcept \
        {} \
        std::string name() const noexcept override; \
        std::pair<const TypeInfo_t *, const TypeInfo_t *> transtypes() const noexcept override; \
        std::pair<const vFunctionInfo *, const vFunctionInfo *> operators() const noexcept override; \
        std::pair<const TypeInfo_t *, const TypeInfo_t *> transtypesExt() const noexcept override; \
        static TypeInfo_t make_type() noexcept; \
    }

#define B_DECLARE_TYPE_CPP(T)  \
    TypeInfo_t TypeInfoInstance<T>::make_type() noexcept \
    { \
        static TypeInfo_t typeInfo(v2::load_type(std::make_unique<TypeInfoInstance<T>>())); \
        return typeInfo; \
    } \
  \
    std::string TypeInfoInstance<T>::name() const noexcept \
    { \
        return trait_t::name(); \
    } \
    \
    std::pair<const TypeInfo_t *, const TypeInfo_t *> TypeInfoInstance<T>::transtypes() const noexcept \
    { \
        return trait_t::transtypes();\
    } \
    \
    std::pair<const vFunctionInfo *, const vFunctionInfo *> TypeInfoInstance<T>::operators() const noexcept \
    { \
        return trait_t::operators();\
    } \
    \
    std::pair<const TypeInfo_t *, const TypeInfo_t *> TypeInfoInstance<T>::transtypesExt() const noexcept \
    { \
        return trait_t::transtypesExt(); \
    }


#endif // TYPEINFOINSTANCE_H
