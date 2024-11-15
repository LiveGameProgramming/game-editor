#=======================================================================================================================
target_precompile_headers(editor PRIVATE headers.hpp)
           target_sources(editor PRIVATE shader_converter.cpp primitive_generator.cpp primitive.cpp)
#=======================================================================================================================