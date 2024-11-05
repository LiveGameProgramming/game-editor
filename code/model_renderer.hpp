#pragma once

#include "opengl/renderer.hpp"
#include "opengl/vertex_array.hpp"

#include "mat4.hpp"
#include "rgb.hpp"

namespace editor
{
    class ModelRenderer final : public engine::opengl::Renderer
    {
    public:
        void draw(const engine::opengl::VertexArray* vertex_array, const engine::mat4& model, const engine::rgb& color, int32_t faces) const;
    };
}