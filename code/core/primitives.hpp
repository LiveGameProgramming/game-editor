#pragma once

#include "vertex.hpp"

namespace editor
{
    class Primitives
    {
    public:
        static geometry create_plane(float x = 1.0f, float z = 1.0f);
        static geometry create_box(float   x = 1.0f, float y = 1.0f, float z = 1.0f);
    };
}