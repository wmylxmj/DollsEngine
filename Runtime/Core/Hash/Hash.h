#pragma once

#include <cstddef>
#include <functional>

namespace DollsEngine
{

    template<typename T>
    struct Hash
    {
        size_t operator()(const T& data) const
        {
            return std::hash<T>{}(data);
        }
    };
}
