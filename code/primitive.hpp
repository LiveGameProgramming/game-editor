#pragma once

#include "vertex.hpp"
#include "geometry.hpp"

#include "primitives/triangle.hpp"

namespace editor
{
    using geometry = engine::geometry<vertex, engine::primitives::triangle>;

    struct primitive final : geometry
    {
        void add_vertex(const engine::vec3& position);
        void add_triangle(uint32_t a, uint32_t b, uint32_t c);

        void generate_faces(uint32_t segments, uint32_t rings, uint32_t offset = 0);
    };
}