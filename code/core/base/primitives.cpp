#include "primitives.hpp"

namespace editor::base
{
    geometry Primitives::create_plane(const float x, const float z)
    {
        using namespace engine::base;

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
                0, 1, 2, // first
                2, 3, 0  // second
            }
        };
    }
}