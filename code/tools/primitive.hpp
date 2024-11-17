#pragma once

#include "debug/geometry.hpp"

namespace tools
{
    struct primitive final : debug::geometry
    {
        void add_vertex(const math::vec3& position);
        void   add_face(const core::primitive::triangle& triangle);

        void generate_faces(uint32_t segments, uint32_t rings, uint32_t offset = 0);
    };
}