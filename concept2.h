#pragma once

#include <string>
#include <concepts>

template <typename T>
class myContainer
{
    using value_type = T;

private:
    value_type value;

public:
    myContainer(const T &&val) : value(val) {}

    //const T &get() const { return value; }

    const std::string_view get() const
        requires std::same_as<T, std::string> || std::same_as<T, std::string_view>
    {
        return value;
    }

    int get() const
        requires std::same_as<T, int>
    {
        return value;
    }

    double get() const
        requires std::same_as<T, double> || std::same_as<T, float>
    {
        return value;
    }
};