#=======================================================================================================================
add_library(${PROJECT_NAME})
#=======================================================================================================================
add_subdirectory(tools)
#=======================================================================================================================
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
 target_precompile_headers(${PROJECT_NAME} PUBLIC headers.hpp)
     target_link_libraries(${PROJECT_NAME} PUBLIC core math graphics)
            target_sources(${PROJECT_NAME} PUBLIC primitive.cpp primitives.cpp model_renderer.cpp)
#=======================================================================================================================