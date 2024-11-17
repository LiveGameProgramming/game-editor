#pragma once

#include "core/base/geometry.hpp"
#include "core/vertex/debug.hpp"

namespace editor::tools
{
    struct primitive final : ::core::base::geometry<core::vertex::debug, engine::core::primitive::triangle>
    {
        void add_vertex(const math::vec3& position);
        void   add_face(const engine::core::primitive::triangle& triangle);

        void generate_faces(uint32_t segments, uint32_t rings, uint32_t offset = 0);
    };
}