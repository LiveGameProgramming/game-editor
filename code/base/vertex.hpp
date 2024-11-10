#pragma once

#include "vec3.hpp"

namespace editor::base
{
    struct vertex
    {
        engine::vec3 position;
        engine::vec3 extra; // normal | color
    };
}