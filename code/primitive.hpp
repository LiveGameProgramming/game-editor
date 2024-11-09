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
        void add_face  (const engine::primitives::triangle& triangle);

        void generate_faces(uint32_t segments, uint32_t rings, uint32_t offset = 0);
    };
}