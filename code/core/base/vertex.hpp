#pragma once

#include "base/vec3.hpp"
#include "base/geometry.hpp"

namespace editor::base
{
    struct vertex
    {
        engine::base::vec3 position;
        engine::base::vec3 extra;
    };

    using geometry = engine::base::geometry<vertex>;
}