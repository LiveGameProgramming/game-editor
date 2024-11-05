#include "model.hpp"

#include "primitives/triangle.hpp"

#include "opengl/commands.hpp"
#include "opengl/macros.hpp"

namespace editor::renderers
{
    void Model::draw(const engine::opengl::VertexArray* vertex_array, const engine::mat4& model, const engine::rgb& color, const int32_t faces) const
    {
        _shader->push(0, model);
        _buffer->sub_data(engine::buffers::data::create(&color));

        assert(vertex_array);
        vertex_array->bind();

        engine::opengl::Commands::draw_indexed(engine::opengl::triangles, faces * engine::primitives::triangle::elements);
    }
}