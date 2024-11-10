#pragma once

#include "vertex.hpp"
#include "geometry.hpp"

#include "primitive/triangle.hpp"

namespace editor
{
    using geometry = engine::geometry<vertex, engine::primitive::triangle>;

    struct primitive final : geometry
    {
        void add_vertex(const engine::vec3& position);
        void add_face  (const engine::primitive::triangle& triangle);

        void generate_faces(uint32_t segments, uint32_t rings, uint32_t offset = 0);
    };
}