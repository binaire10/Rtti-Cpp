#ifndef TRAIT_TYPE_H
#define TRAIT_TYPE_H
#pragma once

#include <tuple>
#include <type_traits>

namespace meta
{
    template<typename Type_t>
    struct get_baseType
    {
        using type = Type_t;
    };

    template<typename Type_t, std::size_t N>
    struct get_baseType<Type_t [N]>
    {
        using type = typename get_baseType<Type_t>::type [N];
    };

    template<typename Type_t>
    struct get_baseType<const Type_t>
    {
        using type = typename get_baseType<Type_t>::type;
    };

    template<typename Type_t>
    struct get_baseType<Type_t *>
    {
        using type = typename get_baseType<Type_t>::type *;
    };

    template<typename Type_t>
    struct get_baseType<Type_t &&>
    {
        using type = typename get_baseType<Type_t>::type &&;
    };

    template<typename Type_t>
    struct get_baseType<Type_t &>
    {
        using type = typename get_baseType<Type_t>::type &;
    };

    template<typename Type_t>
    struct get_baseType<volatile Type_t>
    {
        using type = typename get_baseType<Type_t>::type;
    };

    template<typename Type_t>
    struct trait_Member
    {

        // helper to get the object type of member

        template<typename T, typename O>
        static T valueType(T (O::*));
        template<typename T, typename O>
        static O objectType(T (O::*));
        template<typename T>
        static T valueType(T);
        template<typename T, typename O, typename... arg>
        static O objectType(T (O::*)(arg...));
        template<typename T, typename O, typename... arg>
        static O objectType(T (O::*)(arg...) const);
#if __cplusplus >= 201703L
        template<typename T, typename O, typename... arg>
        static O objectType(T (O::*)(arg...) noexcept);
        template<typename T, typename O, typename... arg>
        static O objectType(T (O::*)(arg...) const noexcept);
#endif

        using this_object = decltype(objectType(*static_cast<Type_t*>(nullptr)));
    };

    template<typename first_type, typename second_type = first_type>
    struct exist_operator
    {
        // function to determine existing operator

        template<typename T, typename = decltype(*static_cast<T*>(nullptr) + *static_cast<second_type*>(nullptr))>
        static std::true_type hasSumOperator(T *);
        template<typename T>
        static std::false_type hasSumOperator(...);
        static constexpr bool sumOperator = decltype(hasSumOperator<first_type>(nullptr))();

        template<typename T, typename = decltype(*static_cast<T*>(nullptr) ++)>
        static std::true_type hasPostIncOperator(T *);
        template<typename T>
        static std::false_type hasPostIncOperator(...);
        static constexpr bool postIncOperator = decltype(hasPostIncOperator<first_type>(nullptr))();

        template<typename T, typename = decltype(++ *static_cast<T*>(nullptr))>
        static std::true_type hasPreIncOperator(T *);
        template<typename T>
        static std::false_type hasPreIncOperator(...);
        static constexpr bool preIncOperator = decltype(hasPreIncOperator<first_type>(nullptr))();

        template<typename T, typename = decltype(*static_cast<T*>(nullptr) --)>
        static std::true_type hasPostDecOperator(T *);
        template<typename T>
        static std::false_type hasPostDecOperator(...);
        static constexpr bool postDecOperator = decltype(hasPostDecOperator<first_type>(nullptr))();

        template<typename T, typename = decltype(-- *static_cast<T*>(nullptr))>
        static std::true_type hasPreDecOperator(T *);
        template<typename T>
        static std::false_type hasPreDecOperator(...);
        static constexpr bool preDecOperator = decltype(hasPreDecOperator<first_type>(nullptr))();

        template<typename T, typename = decltype(~ *static_cast<T*>(nullptr))>
        static std::true_type hasNotBitwiseOperator(T *);
        template<typename T>
        static std::false_type hasNotBitwiseOperator(...);
        static constexpr bool notBitwiseOperator = decltype(hasNotBitwiseOperator<first_type>(nullptr))();

        template<typename T, typename = decltype(*static_cast<T*>(nullptr) - *static_cast<second_type*>(nullptr))>
        static std::true_type hasSubstractOperator(T *);
        template<typename T>
        static std::false_type hasSubstractOperator(...);
        static constexpr bool substractOperator = decltype(hasSubstractOperator<first_type>(nullptr))();

        template<typename T, typename = decltype(*static_cast<T*>(nullptr) * *static_cast<second_type*>(nullptr))>
        static std::true_type hasMultiplicationOperator(T *);
        template<typename T>
        static std::false_type hasMultiplicationOperator(...);
        static constexpr bool multiplicationOperator = decltype(hasMultiplicationOperator<first_type>(nullptr))();

        template<typename T, typename = decltype(*static_cast<T*>(nullptr) / *static_cast<second_type*>(nullptr))>
        static std::true_type hasDivisionOperator(T *);
        template<typename T>
        static std::false_type hasDivisionOperator(...);
        static constexpr bool divisionOperator = decltype(hasDivisionOperator<first_type>(nullptr))();

        template<typename T, typename = decltype(*static_cast<T*>(nullptr) % *static_cast<second_type*>(nullptr))>
        static std::true_type hasModuloOperator(T *);
        template<typename T>
        static std::false_type hasModuloOperator(...);
        static constexpr bool moduloOperator = decltype(hasModuloOperator<first_type>(nullptr))();

        template<typename T, typename = decltype(*static_cast<T*>(nullptr) & *static_cast<second_type*>(nullptr))>
        static std::true_type hasAndBitwiseOperator(T *);
        template<typename T>
        static std::false_type hasAndBitwiseOperator(...);
        static constexpr bool andBitwiseOperator = decltype(hasAndBitwiseOperator<first_type>(nullptr))();

        template<typename T, typename = decltype(*static_cast<T*>(nullptr) | *static_cast<second_type*>(nullptr))>
        static std::true_type hasOrBitwiseOperator(T *);
        template<typename T>
        static std::false_type hasOrBitwiseOperator(...);
        static constexpr bool orBitwiseOperator = decltype(hasOrBitwiseOperator<first_type>(nullptr))();

        template<typename T, typename = decltype(*static_cast<T*>(nullptr) ^ *static_cast<second_type*>(nullptr))>
        static std::true_type hasXOrBitwiseOperator(T *);
        template<typename T>
        static std::false_type hasXOrBitwiseOperator(...);
        static constexpr bool xorBitwiseOperator = decltype(hasXOrBitwiseOperator<first_type>(nullptr))();

        template<typename T, typename = decltype(*static_cast<T*>(nullptr) && *static_cast<second_type*>(nullptr))>
        static std::true_type hasAndLogicOperator(T *);
        template<typename T>
        static std::false_type hasAndLogicOperator(...);
        static constexpr bool andLogicOperator = decltype(hasAndLogicOperator<first_type>(nullptr))();

        template<typename T, typename = decltype(*static_cast<T*>(nullptr) || *static_cast<second_type*>(nullptr))>
        static std::true_type hasOrLogicOperator(T *);
        template<typename T>
        static std::false_type hasComaOperator(...);
        static constexpr bool orLogicOperator = decltype(hasOrLogicOperator<first_type>(nullptr))(nullptr);

        template<typename T, typename = decltype(*static_cast<T*>(nullptr) , *static_cast<second_type*>(nullptr))>
        static std::true_type hasComaOperator(T *);
        template<typename T>
        static std::false_type hasOrLogicOperator(...);
        static constexpr bool comaOperator = decltype(hasComaOperator<first_type>(nullptr))();
    };

    template<typename type, template<typename...> class TypeContenor = std::tuple>
    struct trait_function
    {
    private:

        // tool to get return type and argument without make special class

        template<typename T, typename O, typename... arg>
        static TypeContenor<arg...> argTypes(T (*)(arg...));
        template<typename T, typename O, typename... arg>
        static TypeContenor<arg...> argTypes(T (O::*)(arg...));
        template<typename T, typename O, typename... arg>
        static TypeContenor<arg...> argTypes(T (O::*)(arg...) const);

        template<typename T, typename O, typename... arg>
        static T resultTypes(T (*)(arg...));
        template<typename T, typename O, typename... arg>
        static T resultTypes(T (O::*)(arg...));
        template<typename T, typename O, typename... arg>
        static T resultTypes(T (O::*)(arg...) const);
#if __cplusplus >= 201703L
        template<typename T, typename O, typename... arg>
        static std::tuple<arg...> argTypes(T (*)(arg...) noexcept);
        template<typename T, typename O, typename... arg>
        static std::tuple<arg...> argTypes(T (O::*)(arg...) noexcept);
        template<typename T, typename O, typename... arg>
        static std::tuple<arg...> argTypes(T (O::*)(arg...) const noexcept);

        template<typename T, typename O, typename... arg>
        static T resultTypes(T (*)(arg...) noexcept);
        template<typename T, typename O, typename... arg>
        static T resultTypes(T (O::*)(arg...) noexcept);
        template<typename T, typename O, typename... arg>
        static T resultTypes(T (O::*)(arg...) const noexcept);
#endif
    public:
        using result_type = decltype(resultTypes(*static_cast<type *>(nullptr)));
        using args_type = decltype(argTypes(*static_cast<type *>(nullptr)));
    };
}


#endif // TRAIT_TYPE_H
