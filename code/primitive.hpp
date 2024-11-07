#pragma once

#include "vertex.hpp"
#include "geometry.hpp"

#include "primitives/triangle.hpp"

namespace editor
{
    using geometry = engine::geometry<vertex, engine::primitives::triangle>;

    struct primitive final : geometry
    {
        void create_vertex(const engine::vec3& position);

        void generate_faces(uint32_t segments, uint32_t rings, uint32_t offset = 0);
    };
}