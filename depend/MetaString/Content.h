#ifndef CONTENT_H
#define CONTENT_H
#pragma once

#include <unistd.h>

namespace meta
{
    template<typename type_t, type_t... str>
    struct Content
    {
        typedef type_t (array_type)[sizeof... (str)+1];

        constexpr Content() noexcept;

        static constexpr const array_type &get();

        constexpr operator const type_t *() const;

        template<type_t... arg2>
        constexpr Content<type_t, str..., arg2...> operator +(Content<type_t, arg2...>);

        static constexpr size_t Size = sizeof... (str);
        static constexpr array_type s_data = {str..., type_t(0)};
    };
}

#endif // CONTENT_H
