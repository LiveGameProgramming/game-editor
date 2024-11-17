#include "primitive_generator.hpp"

#include "math/functions.hpp"
#include "math/constants.hpp"

namespace tools
{
    debug::geometry PrimitiveGenerator::create_plane(float x, float z)
    {
        x /= 2.0f; z /= 2.0f;

        return
        {
            {
                { { -x, 0.0f,  z }, math::vec3::up() },
                { {  x, 0.0f,  z }, math::vec3::up() },
                { {  x, 0.0f, -z }, math::vec3::up() },
                { { -x, 0.0f, -z }, math::vec3::up() }
            },
            {
                { 0, 1, 2 },
                { 2, 3, 0 }
            }
        };
    }

    debug::geometry PrimitiveGenerator::create_box(float x, float y, float z)
    {
        x /= 2.0f; y /= 2.0f; z /= 2.0f;

        return
        {
            {
                { { -x, -y,  z }, math::vec3::front() },
                { {  x, -y,  z }, math::vec3::front() },
                { {  x,  y,  z }, math::vec3::front() },
                { { -x,  y,  z }, math::vec3::front() },

                { { -x, -y, -z }, math::vec3::back() },
                { { -x,  y, -z }, math::vec3::back() },
                { {  x,  y, -z }, math::vec3::back() },
                { {  x, -y, -z }, math::vec3::back() },

                { { -x,  y,  z }, math::vec3::left() },
                { { -x,  y, -z }, math::vec3::left() },
                { { -x, -y, -z }, math::vec3::left() },
                { { -x, -y,  z }, math::vec3::left() },

                { {  x,  y,  z }, math::vec3::right() },
                { {  x, -y,  z }, math::vec3::right() },
                { {  x, -y, -z }, math::vec3::right() },
                { {  x,  y, -z }, math::vec3::right() },

                { { -x,  y, -z }, math::vec3::up() },
                { { -x,  y,  z }, math::vec3::up() },
                { {  x,  y,  z }, math::vec3::up() },
                { {  x,  y, -z }, math::vec3::up() },

                { { -x, -y, -z }, math::vec3::down() },
                { {  x, -y, -z }, math::vec3::down() },
                { {  x, -y,  z }, math::vec3::down() },
                { { -x, -y,  z }, math::vec3::down() }
            },
            {
                {  0,  1,  2 }, {  2,  3,  0 },
                {  4,  5,  6 }, {  6,  7,  4 },
                {  8,  9, 10 }, { 10, 11,  8 },
                { 12, 13, 14 }, { 14, 15, 12 },
                { 16, 17, 18 }, { 18, 19, 16 },
                { 20, 21, 22 }, { 22, 23, 20 }
            }
        };
    }

    primitive_geometry PrimitiveGenerator::create_sphere(const uint32_t segments, const uint32_t rings, float radius)
    {
        primitive_geometry sphere;

        #pragma region Constants

        const auto   phi_step = math::pi / static_cast<float>(rings); radius /= 2.0f;
        const auto theta_step = math::pi / static_cast<float>(segments)       * 2.0f;

        #pragma endregion

        for (uint32_t i = 0; i <= rings; ++i)
        {
            const auto     phi = phi_step * static_cast<float>(i);
            const auto sin_phi =   radius * math::sin(phi);
            const auto cos_phi =   radius * math::cos(phi);

            for (uint32_t j = 0; j <= segments; ++j)
            {
                const auto theta = theta_step * static_cast<float>(j);

                sphere.add_vertex({ sin_phi * math::cos(theta), cos_phi, sin_phi * math::sin(theta) });
            }
        }

        sphere.generate_faces(segments, rings);
        return sphere;
    }

    primitive_geometry PrimitiveGenerator::create_capsule(const uint32_t segments, uint32_t rings, float radius, const float height)
    {
        primitive_geometry capsule;

        #pragma region Constants

        radius /= 2.0f; rings /= 2;
        const auto half_height = height / 2.0f;

        const auto phi_step    = math::pi / static_cast<float>(rings)    / 2.0f;
        const auto theta_step  = math::pi / static_cast<float>(segments) * 2.0f;

        #pragma endregion

        #pragma region Upper  Section

        for (uint32_t i = 0; i <= rings; ++i)
        {
            const auto     phi = phi_step * static_cast<float>(i);
            const auto sin_phi =   radius * math::sin(phi);
            const auto cos_phi =   radius * math::cos(phi);

            for (uint32_t j = 0; j <= segments; ++j)
            {
                const auto theta = theta_step * static_cast<float>(j);

                capsule.add_vertex({ sin_phi  * math::cos(theta), cos_phi + half_height, sin_phi * math::sin(theta) });
            }
        }

        #pragma endregion
        #pragma region Middle Section

        for (uint32_t i = 0; i <= rings; ++i)
        {
            const auto offset = half_height - height * static_cast<float>(i) / static_cast<float>(rings);

            for (uint32_t j = 0; j <= segments; ++j)
            {
                const auto theta = theta_step * static_cast<float>(j);

                capsule.add_vertex({  radius  * math::cos(theta), offset, radius * math::sin(theta) });
            }
        }

        #pragma endregion
        #pragma region Bottom Section

        for (uint32_t i = 0; i <= rings; ++i)
        {
            const auto     phi = phi_step * static_cast<float>(i);
            const auto sin_phi =   radius * math::sin(phi);
            const auto cos_phi =   radius * math::cos(phi);

            for (uint32_t j = 0; j <= segments; ++j)
            {
                const auto theta = theta_step * static_cast<float>(j);

                capsule.add_vertex({ sin_phi  * math::sin(theta), -half_height - cos_phi, sin_phi * math::cos(theta) });
            }
        }

        #pragma endregion

        const auto offset = (segments + 1) * (rings + 1);

        capsule.generate_faces(segments, rings);
        capsule.generate_faces(segments, rings, offset);
        capsule.generate_faces(segments, rings, offset * 2);

        return capsule;
    }
}