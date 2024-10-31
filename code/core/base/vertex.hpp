#pragma once

#include "base/vec3.hpp"
#include "base/geometry.hpp"

#include "primitives/triangle.hpp"

namespace editor::base
{
    struct vertex
    {
        engine::base::vec3 position;
        engine::base::vec3 extra;
    };

    using geometry = engine::base::geometry<vertex, engine::primitives::triangle>;
}