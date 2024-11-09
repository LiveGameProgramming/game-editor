#include "primitives.hpp"
#include "functions.hpp"

namespace editor
{
    geometry Primitives::create_plane(const float x, const float z)
    {
        const float half_x = x / 2.0f;
        const float half_z = z / 2.0f;

        return
        {
            {
                { { -half_x, 0.0f,  half_z }, engine::vec3::up() },
                { {  half_x, 0.0f,  half_z }, engine::vec3::up() },
                { {  half_x, 0.0f, -half_z }, engine::vec3::up() },
                { { -half_x, 0.0f, -half_z }, engine::vec3::up() }
            },
            {
                { 0, 1, 2 }, //  first triangle
                { 2, 3, 0 }  // second triangle
            }
        };
    }

    geometry Primitives::create_box(const float x, const float y, const float z)
    {
        const float half_x = x / 2.0f;
        const float half_y = y / 2.0f;
        const float half_z = z / 2.0f;

        return
        {
            {
                { { -half_x, -half_y,  half_z }, engine::vec3::front() },
                { {  half_x, -half_y,  half_z }, engine::vec3::front() },
                { {  half_x,  half_y,  half_z }, engine::vec3::front() },
                { { -half_x,  half_y,  half_z }, engine::vec3::front() },

                { { -half_x, -half_y, -half_z }, engine::vec3::back() },
                { { -half_x,  half_y, -half_z }, engine::vec3::back() },
                { {  half_x,  half_y, -half_z }, engine::vec3::back() },
                { {  half_x, -half_y, -half_z }, engine::vec3::back() },

                { { -half_x,  half_y,  half_z }, engine::vec3::left() },
                { { -half_x,  half_y, -half_z }, engine::vec3::left() },
                { { -half_x, -half_y, -half_z }, engine::vec3::left() },
                { { -half_x, -half_y,  half_z }, engine::vec3::left() },

                { {  half_x,  half_y,  half_z }, engine::vec3::right() },
                { {  half_x, -half_y,  half_z }, engine::vec3::right() },
                { {  half_x, -half_y, -half_z }, engine::vec3::right() },
                { {  half_x,  half_y, -half_z }, engine::vec3::right() },

                { { -half_x,  half_y, -half_z }, engine::vec3::up() },
                { { -half_x,  half_y,  half_z }, engine::vec3::up() },
                { {  half_x,  half_y,  half_z }, engine::vec3::up() },
                { {  half_x,  half_y, -half_z }, engine::vec3::up() },

                { { -half_x, -half_y, -half_z }, engine::vec3::down() },
                { {  half_x, -half_y, -half_z }, engine::vec3::down() },
                { {  half_x, -half_y,  half_z }, engine::vec3::down() },
                { { -half_x, -half_y,  half_z }, engine::vec3::down() }
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

    primitive Primitives::create_sphere(const uint32_t segments, const uint32_t rings, const float radius)
    {
        primitive sphere;

        #pragma region Constants

        const auto    phi_step = engine::pi() / static_cast<float>(rings);
        const auto  theta_step = engine::pi() / static_cast<float>(segments) * 2.0f;
        const auto half_radius = radius       / 2.0f;

        #pragma endregion

        for (uint32_t i = 0; i <= rings; ++i)
        {
            const auto     phi = phi_step    * static_cast<float>(i);
            const auto sin_phi = half_radius * engine::sin(phi);
            const auto cos_phi = half_radius * engine::cos(phi);

            for (uint32_t j = 0; j <= segments; ++j)
            {
                const auto theta = theta_step * static_cast<float>(j);

                sphere.add_vertex({ sin_phi * engine::cos(theta), cos_phi, sin_phi * engine::sin(theta) });
            }
        }

        sphere.generate_faces(segments, rings);

        return sphere;
    }

    primitive Primitives::create_capsule(const uint32_t segments, const uint32_t rings, const float radius, const float height)
    {
        primitive capsule;

        #pragma region Constants

        const auto half_rings  = rings  / 2;
        const auto half_height = height / 2.0f;
        const auto half_radius = radius / 2.0f;

        const auto phi_step   = engine::pi() / static_cast<float>(half_rings) / 2.0f;
        const auto theta_step = engine::pi() / static_cast<float>(segments)   * 2.0f;

        #pragma endregion

        #pragma region Upper  Section

        for (uint32_t i = 0; i <= half_rings; ++i)
        {
            const auto     phi = phi_step    * static_cast<float>(i);
            const auto sin_phi = half_radius * engine::sin(phi);
            const auto cos_phi = half_radius * engine::cos(phi);

            for (uint32_t j = 0; j <= segments; ++j)
            {
                const auto theta = theta_step * static_cast<float>(j);

                capsule.add_vertex({ sin_phi  * engine::cos(theta), cos_phi + half_height, sin_phi * engine::sin(theta) });
            }
        }

        #pragma endregion
        #pragma region Middle Section

        for (uint32_t i = 0; i <= half_rings; ++i)
        {
            const auto offset = half_height - height * static_cast<float>(i) / static_cast<float>(half_rings);

            for (uint32_t j = 0; j <= segments; ++j)
            {
                const auto theta = theta_step * static_cast<float>(j);

                capsule.add_vertex({ half_radius * engine::cos(theta), offset, half_radius * engine::sin(theta) });
            }
        }

        #pragma endregion
        #pragma region Bottom Section

        for (uint32_t i = 0; i <= half_rings; ++i)
        {
            const auto     phi = phi_step    * static_cast<float>(i);
            const auto sin_phi = half_radius * engine::sin(phi);
            const auto cos_phi = half_radius * engine::cos(phi);

            for (uint32_t j = 0; j <= segments; ++j)
            {
                const auto theta = theta_step * static_cast<float>(j);

                capsule.add_vertex({ sin_phi  * engine::sin(theta), -half_height - cos_phi, sin_phi * engine::cos(theta) });
            }
        }

        #pragma endregion

        const auto offset = (segments + 1) * (half_rings + 1);

        capsule.generate_faces(segments, half_rings);
        capsule.generate_faces(segments, half_rings, offset);
        capsule.generate_faces(segments, half_rings, offset * 2);

        return capsule;
    }
}