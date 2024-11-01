#include "primitives.hpp"
#include "math/functions.hpp"

namespace editor
{
    geometry Primitives::create_plane(const float x, const float z)
    {
        const float hx = x / 2.0f;
        const float hz = z / 2.0f;

        return
        {
            {
                { { -hx, 0.0f,  hz }, engine::vec3::up() },
                { {  hx, 0.0f,  hz }, engine::vec3::up() },
                { {  hx, 0.0f, -hz }, engine::vec3::up() },
                { { -hx, 0.0f, -hz }, engine::vec3::up() },
            },
            {
                { 0, 1, 2 }, //  first triangle
                { 2, 3, 0 }  // second triangle
            }
        };
    }

    geometry Primitives::create_box(const float x, const float y, const float z)
    {
        const float hx = x / 2.0f;
        const float hy = y / 2.0f;
        const float hz = z / 2.0f;

        return
        {
            {
                { { -hx, -hy,  hz }, engine::vec3::front() },
                { {  hx, -hy,  hz }, engine::vec3::front() },
                { {  hx,  hy,  hz }, engine::vec3::front() },
                { { -hx,  hy,  hz }, engine::vec3::front() },

                { { -hx, -hy, -hz }, engine::vec3::back() },
                { { -hx,  hy, -hz }, engine::vec3::back() },
                { {  hx,  hy, -hz }, engine::vec3::back() },
                { {  hx, -hy, -hz }, engine::vec3::back() },

                { { -hx,  hy,  hz }, engine::vec3::left() },
                { { -hx,  hy, -hz }, engine::vec3::left() },
                { { -hx, -hy, -hz }, engine::vec3::left() },
                { { -hx, -hy,  hz }, engine::vec3::left() },

                { {  hx,  hy,  hz }, engine::vec3::right() },
                { {  hx, -hy,  hz }, engine::vec3::right() },
                { {  hx, -hy, -hz }, engine::vec3::right() },
                { {  hx,  hy, -hz }, engine::vec3::right() },

                { { -hx,  hy, -hz }, engine::vec3::up() },
                { { -hx,  hy,  hz }, engine::vec3::up() },
                { {  hx,  hy,  hz }, engine::vec3::up() },
                { {  hx,  hy, -hz }, engine::vec3::up() },

                { { -hx, -hy, -hz }, engine::vec3::down() },
                { {  hx, -hy, -hz }, engine::vec3::down() },
                { {  hx, -hy,  hz }, engine::vec3::down() },
                { { -hx, -hy,  hz }, engine::vec3::down() },
            },
            {
                {  0,  1,  2 }, {  2,  3,  0 }, // front face
                {  4,  5,  6 }, {  6,  7,  4 }, //  back face
                {  8,  9, 10 }, { 10, 11,  8 }, //  left face
                { 12, 13, 14 }, { 14, 15, 12 }, // right face
                { 16, 17, 18 }, { 18, 19, 16 }, //    up face
                { 20, 21, 22 }, { 22, 23, 20 }  //  down face
            }
        };
    }

    geometry Primitives::create_sphere(const uint32_t segments, const float radius)
    {
        geometry sphere;

        const float hr    = radius / 2.0f;
        const float stack = engine::math::pi() / static_cast<float>(segments);
        const float slice = engine::math::pi() / static_cast<float>(segments) * 2.0f;

        for (uint32_t i = 0; i <= segments; ++i)
        {
            const float phi = stack * static_cast<float>(i);

            const float sin_phi = hr * engine::math::sin(phi);
            const float cos_phi = hr * engine::math::cos(phi);

            for (uint32_t j = 0; j <= segments; ++j)
            {
                const float theta = static_cast<float>(j) * slice;

                const engine::vec3 position
                {
                    sin_phi * engine::math::cos(theta), cos_phi,
                    sin_phi * engine::math::sin(theta),
                };

                sphere.vertices.emplace_back(position, position.normalized());
            }
        }

        for (uint32_t i = 0; i < segments; ++i)
        {
            for (uint32_t j = 0; j <  segments; ++j)
            {
                const uint32_t next = segments + 1;

                const uint32_t top_left     = i * next + j;
                const uint32_t top_right    = top_left + 1;
                const uint32_t bottom_left  = (i + 1) * next + j;
                const uint32_t bottom_right = bottom_left + 1;

                sphere.faces.emplace_back(top_left, bottom_left, top_right);
                sphere.faces.emplace_back(top_right, bottom_left, bottom_right);
            }
        }

        return sphere;
    }
}