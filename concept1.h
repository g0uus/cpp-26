#pragma once

#include <numeric>
#include <vector>
#include <concepts>

template <typename T>
    requires std::integral<T> || std::floating_point<T>
constexpr double Average(std::vector<T> const &vec)
{
    const double sum = std::accumulate(vec.begin(), vec.end(), 0.0);
    return sum / vec.size();
}

// concept1.h
