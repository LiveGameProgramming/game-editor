#=======================================================================================================================
add_library(editor)
#=======================================================================================================================
add_subdirectory(tools)
#=======================================================================================================================
target_include_directories(editor PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
 target_precompile_headers(editor PUBLIC headers.hpp)
     target_link_libraries(editor PUBLIC core math graphics)
            target_sources(editor PUBLIC primitive.cpp primitives.cpp)
#=======================================================================================================================