#include "primitives.hpp"

namespace editor::base
{
    using namespace engine::base;

    geometry Primitives::create_plane(const float x, const float z)
    {
        const float hx = x / 2.0f;
        const float hz = z / 2.0f;

        return
        {
            {
                { { -hx, 0.0f,  hz }, vec3::up() },
                { {  hx, 0.0f,  hz }, vec3::up() },
                { {  hx, 0.0f, -hz }, vec3::up() },
                { { -hx, 0.0f, -hz }, vec3::up() },
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
                { { -hx, -hy,  hz }, vec3::front() },
                { {  hx, -hy,  hz }, vec3::front() },
                { {  hx,  hy,  hz }, vec3::front() },
                { { -hx,  hy,  hz }, vec3::front() },

                { { -hx, -hy, -hz }, vec3::back() },
                { { -hx,  hy, -hz }, vec3::back() },
                { {  hx,  hy, -hz }, vec3::back() },
                { {  hx, -hy, -hz }, vec3::back() },

                { { -hx,  hy,  hz }, vec3::left() },
                { { -hx,  hy, -hz }, vec3::left() },
                { { -hx, -hy, -hz }, vec3::left() },
                { { -hx, -hy,  hz }, vec3::left() },

                { {  hx,  hy,  hz }, vec3::right() },
                { {  hx, -hy,  hz }, vec3::right() },
                { {  hx, -hy, -hz }, vec3::right() },
                { {  hx,  hy, -hz }, vec3::right() },

                { { -hx,  hy, -hz }, vec3::up() },
                { { -hx,  hy,  hz }, vec3::up() },
                { {  hx,  hy,  hz }, vec3::up() },
                { {  hx,  hy, -hz }, vec3::up() },

                { { -hx, -hy, -hz }, vec3::down() },
                { {  hx, -hy, -hz }, vec3::down() },
                { {  hx, -hy,  hz }, vec3::down() },
                { { -hx, -hy,  hz }, vec3::down() },
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
}