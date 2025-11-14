#pragma once

//
//
//

#include "GeoObj.h"

#include <vector>

class Picture
{

private:
    std::vector<GeoObj> elems;

public:
    template <typename T, typename... Types>
        requires(is_geoobj<T>)
    void insert(Types &&...args)
    {
        elems.push_back(T(std::forward<Types>(args)...)); // or emplace_back ??
    }

    // Picture(const Picture&) = delete;
    // Picture& operator=(const Picture&) = delete;

    void draw() const
    {
        for (const auto elem : elems)
        {
            std::visit([](const auto &obj)
                       { obj.draw(); }, elem);
        }
    }
};

//