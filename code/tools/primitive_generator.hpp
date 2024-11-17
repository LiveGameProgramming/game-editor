#pragma once

#include "primitive.hpp"

namespace tools
{
    class PrimitiveGenerator
    {
    public:
        static core::base::geometry<core::vertex::debug, core::primitive::triangle> create_plane(float x = 1.0f, float z = 1.0f);
        static core::base::geometry<core::vertex::debug, core::primitive::triangle>   create_box(float x = 1.0f, float y = 1.0f, float z = 1.0f);

        static primitive create_sphere (uint32_t segments = 32, uint32_t rings = 16, float radius = 1.0f);
        static primitive create_capsule(uint32_t segments = 32, uint32_t rings = 16, float radius = 1.0f, float height = 1.0f);
    };
}