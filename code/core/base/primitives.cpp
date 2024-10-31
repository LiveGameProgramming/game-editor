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
                { { }, { } }
            },
            {
                { }
            }
        };
    }
}
