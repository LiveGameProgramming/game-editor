#pragma once

#include "base/vec3.hpp"
#include "geometry.hpp"

#include "primitives/triangle.hpp"

namespace editor
{
    struct vertex
    {
        engine::base::vec3 position;
        engine::base::vec3 extra;
    };

    using geometry = engine::geometry<vertex, engine::primitives::triangle>;
}