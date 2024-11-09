#=======================================================================================================================
add_library(game_editor)
#=======================================================================================================================
target_include_directories(game_editor PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
#=======================================================================================================================
target_link_libraries(game_editor PRIVATE module_core module_math module_graphics)
       target_sources(game_editor PRIVATE primitive.cpp primitives.cpp model_renderer.cpp)
#=======================================================================================================================