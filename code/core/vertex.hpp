#pragma once

#include "vec3.hpp"
#include "geometry.hpp"

#include "primitives/triangle.hpp"

namespace editor
{
    struct vertex
    {
        engine::vec3 position;
        engine::vec3 extra;
    };

    using geometry = engine::geometry<vertex, engine::primitives::triangle>;
}