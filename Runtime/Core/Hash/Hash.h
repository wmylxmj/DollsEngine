#pragma once

#include <cstddef>
#include <functional>

namespace DollsEngine
{
    namespace HashDetail
    {
        inline void HashCombine(size_t& seed, size_t value)
        {
            seed ^= value + 0x9e3779b97f4a7c15ULL + (seed << 6) + (seed >> 2);
        }

        template<typename T>
        void HashCombine(size_t& seed, const T& value)
        {
            HashCombine(seed, static_cast<size_t>(std::hash<T>{}(value)));
        }

        template<typename... Args>
        size_t HashCombineAll(const Args&... args)
        {
            size_t seed = 0;
            (HashCombine(seed, args), ...);
            return seed;
        }
    }

    template<typename T>
    struct Hash
    {
        size_t operator()(const T& data) const
        {
            return std::hash<T>{}(data);
        }
    };
}
