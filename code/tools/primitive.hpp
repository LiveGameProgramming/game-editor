#pragma once

#include "core/vertex/debug.hpp"

namespace tools
{
    using geometry = core::base::geometry<core::vertex::debug, core::primitive::triangle>;

    struct primitive final : geometry
    {
        void add_vertex(const math::vec3& position);
        void   add_face(const core::primitive::triangle& triangle);

        void generate_faces(uint32_t segments, uint32_t rings, uint32_t offset = 0);
    };
}