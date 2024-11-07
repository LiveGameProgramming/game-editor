#include "primitive.hpp"

namespace editor
{
    void primitive::create_vertex(const engine::vec3& position)
    {
        vertices.emplace_back(position, position.normalized());
    }

    void primitive::generate_faces(const uint32_t segments, const uint32_t rings, const uint32_t offset)
    {
        for (uint32_t i = 0; i < rings; ++i)
        {
            for (uint32_t j = 0; j <  segments; ++j)
            {
                const uint32_t next = segments + 1;

                const uint32_t top_left     = offset   + i * next + j;
                const uint32_t top_right    = top_left + 1;

                const uint32_t bottom_left  = offset + (i + 1) * next + j;
                const uint32_t bottom_right = bottom_left + 1;

                faces.emplace_back(top_left,  top_right,    bottom_left);
                faces.emplace_back(top_right, bottom_right, bottom_left);
            }
        }
    }
}