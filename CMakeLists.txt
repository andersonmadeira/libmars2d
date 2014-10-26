project(Mars2DGameEngine)
cmake_minimum_required(VERSION 2.8)

# Point to our own cmake modules
list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/CMakeModules)

# Find SDL2
#find_package(SDL2 REQUIRED)

# define var - source files
set( mars2d_SRC_FILES
    src/Mars2D.cpp
)

# define var - header files
set( mars2d_HPP_FILES
    src/Mars2D.hpp
    src/Pointer.hpp
)

# Add global definitions
add_definitions("-Wall")
#include_directories(${SDL2_INCLUDE_DIR})

# Register the shared library passing also the source files
add_library(mars2d SHARED ${mars2d_SRC_FILES})
# Link dependencies
#target_link_libraries(mars2d ${SDL2_LIBRARIES})

install(TARGETS mars2d DESTINATION lib)
install(FILES ${mars2d_HPP_FILES} DESTINATION include/Mars2D)
