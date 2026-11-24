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

    template<typename T>
    inline void HashCombine(size_t& seed, const T& value)
    {
        seed ^= std::hash<T>{}(value) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
    }
}
