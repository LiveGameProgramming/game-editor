#pragma once

#include "vertex.hpp"

namespace editor::base
{
    class Primitives
    {
    public:
        static geometry create_plane(float x = 1.0f, float z = 1.0f);
    };
}