#pragma once

#include "vertex.hpp"

namespace editor
{
    class Primitives
    {
    public:
        static geometry create_plane(float x = 1.0f, float z = 1.0f);
        static geometry create_box(float   x = 1.0f, float y = 1.0f, float z = 1.0f);

        static geometry create_sphere(uint32_t  segments = 32, uint32_t rings = 16, float radius = 1.0f);
        static geometry create_capsule(uint32_t segments = 32, uint32_t rings = 16, float radius = 1.0f, float height = 1.0f);

    private:
        static void create_faces(geometry& geometry, uint32_t segments, uint32_t rings, uint32_t offset = 0);
    };
}