#pragma once

namespace meta {
    template<typename Type_t>
    struct get_const_baseType
    {
        typedef const Type_t type;
    };

    template<typename Type_t>
    struct get_const_baseType<const Type_t>
    {
        typedef typename get_const_baseType<Type_t>::type type;
    };

    template<typename Type_t>
    struct get_const_baseType<Type_t *>
    {
        typedef typename get_const_baseType<Type_t>::type * type;
    };

    template<typename Type_t>
    struct get_const_baseType<Type_t &&>
    {
        typedef typename get_const_baseType<Type_t>::type && type;
    };

    template<typename Type_t>
    struct get_const_baseType<Type_t &>
    {
        typedef typename get_const_baseType<Type_t>::type & type;
    };

    template<typename Type_t>
    struct get_const_baseType<volatile Type_t>
    {
        typedef typename get_const_baseType<Type_t>::type type;
    };

    template<typename Type_t>
    struct get_baseType
    {
        typedef Type_t type;
    };

    template<typename Type_t>
    struct get_baseType<const Type_t>
    {
        typedef typename get_baseType<Type_t>::type type;
    };

    template<typename Type_t>
    struct get_baseType<Type_t *>
    {
        typedef typename get_baseType<Type_t>::type * type;
    };

    template<typename Type_t>
    struct get_baseType<Type_t &&>
    {
        typedef typename get_baseType<Type_t>::type && type;
    };

    template<typename Type_t>
    struct get_baseType<Type_t &>
    {
        typedef typename get_baseType<Type_t>::type & type;
    };

    template<typename Type_t>
    struct get_baseType<volatile Type_t>
    {
        typedef typename get_baseType<Type_t>::type type;
    };

    /// is const

    template<typename Type_t>
    struct data_is_const
    {
        enum{
            value = false,
            wall = true
        };
    };

    template<typename Type_t>
    struct data_is_const<const Type_t>
    {
        enum{
            value = (true && data_is_const<Type_t>::wall) || data_is_const<Type_t>::value,
            wall = true && data_is_const<Type_t>::wall
        };
    };

    template<typename Type_t>
    struct data_is_const<Type_t *>
    {
        enum{
            value = data_is_const<Type_t>::value,
            wall = false
        };
    };

    template<typename Type_t>
    struct data_is_const<Type_t &&>
    {
        enum{
            value = data_is_const<Type_t>::value,
            wall = false
        };
    };

    template<typename Type_t>
    struct data_is_const<Type_t &>
    {
        enum{
            value = data_is_const<Type_t>::value,
            wall = false
        };
    };

    template<typename Type_t>
    struct data_is_const<volatile Type_t>
    {
        enum{
            value = data_is_const<Type_t>::value,
            wall = false
        };
    };

    template<typename Type_t>
    struct data_is_const<volatile const Type_t>
    {
        enum{
            value = data_is_const<const Type_t>::value,
            wall = false
        };
    };
}
