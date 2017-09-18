#ifndef FUNCTIONMEMBER_HPP
#define FUNCTIONMEMBER_HPP

/*!
 * \class FunctionMember_check
 * \brief check if the members is a part of D class
 *
 * \struct FunctionMember
 * \brief generate an array of Members
 */

#include "arrayOf.h"
#include "FunctionMemberInfoInstance.h"

template<typename D, typename... T>
class FunctionMember_check
{
    template<typename func, func f>
    static trait_FunctionMemberInfoInstance<func, f> convert(FunctionMemberInfoInstance<func,f> &&);
    template<typename func, func f>
    static trait_FunctionMemberInfoInstance<func, f> convert(FunctionMemberInfoInstance<func,f> &);

    template<typename T1>
    using trait = decltype(convert(T1()));

    using arguments_type = std::tuple<T...>;
    using argumentsSet_type = MakeSet<arguments_type>;

    static_assert(b_and(std::is_same<D, typename trait<T>::this_object_t>::value...), "Member T must be a part of D");
    static_assert(std::is_same<arguments_type, argumentsSet_type>(), "T already add int functionMember array");
};

template<typename T>
struct FunctionMember : array_of_functionmemberinfo<>
{};

#define B_DECLARE_FUNCTION_MEMBER_OBJECT_HPP(Target, ...) \
    template<> \
    struct FunctionMember<Target> : FunctionMember_check<Target, __VA_ARGS__> \
    { \
        static const std::array<FunctionMemberInfo_t, meta::arg_size<__VA_ARGS__>::count> &value; \
        using types = std::tuple<__VA_ARGS__>;\
    }

#define B_EXPORT_DECLARE_FUNCTION_MEMBER_OBJECT_HPP(E, Target, ...) \
    template<> \
    struct E FunctionMember<Target> : FunctionMember_check<Target, __VA_ARGS__> \
    { \
        static const std::array<FunctionMemberInfo_t, meta::arg_size<__VA_ARGS__>::count> &value; \
        using types = std::tuple<__VA_ARGS__>;\
    }

 #define B_DECLARE_FUNCTION_MEMBER_OBJECT_CPP(Target, ...) \
    const std::array<FunctionMemberInfo_t, meta::arg_size<__VA_ARGS__>::count> &FunctionMember<Target>::value = array_of_functionmemberinfo<__VA_ARGS__>::value

#endif // FUNCTIONMEMBER_HPP
