#include "model_renderer.hpp"

#include "primitives/triangle.hpp"

#include "opengl/commands.hpp"
#include "opengl/macros.hpp"

namespace editor
{
    void ModelRenderer::draw(const engine::opengl::VertexArray* vertex_array, const engine::mat4& model, const engine::rgb& color, const int32_t faces) const
    {
        _shader->push(model);
        _buffer->sub_data(engine::buffers::data::create(&color));

        assert(vertex_array);
        vertex_array->bind();

        engine::opengl::Commands::draw_indexed(engine::opengl::triangles, engine::primitives::triangle::elements * faces);
    }
}