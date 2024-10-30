#=======================================================================================================================
target_include_directories(${PROJECT_NAME} PRIVATE PUBLIC ..)
target_link_libraries(${PROJECT_NAME}      PRIVATE core_module math_module)
target_sources(${PROJECT_NAME}             PRIVATE primitives.cpp)
#=======================================================================================================================