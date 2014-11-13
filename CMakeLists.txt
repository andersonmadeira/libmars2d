project(MarsGameEngine)
cmake_minimum_required(VERSION 2.8)

# Point to our own cmake modules
list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/CMakeModules)

# Find SDL2
include(FindPkgConfig)
PKG_SEARCH_MODULE(SDL2 REQUIRED sdl2)

# define var - source files
set( MarsGE_SRC_FILES
    src/Application.cpp
    src/Window.cpp
    src/Math/Point.cpp
    src/Math/Vector.cpp
)

# define var - header files
set( MarsGE_HPP_FILES
    src/MarsGE.hpp
    src/Math.hpp
    src/Exception.hpp
    src/Pointer.hpp
    src/Application.hpp
    src/Window.hpp
)

set( MarsGE_Math_HPP_FILES
    src/Math/Utility.hpp
    src/Math/Point.hpp
    src/Math/Vector.hpp
)

set(CMAKE_BUILD_TYPE Release)

# Add global definitions
add_definitions("-Wall")
include_directories(${SDL2_INCLUDE_DIR})

# Register the shared library passing also the source files
add_library(MarsGE SHARED ${MarsGE_SRC_FILES})
# Link dependencies
target_link_libraries(MarsGE ${SDL2_LIBRARIES})

install(TARGETS MarsGE DESTINATION lib)
install(FILES ${MarsGE_HPP_FILES} DESTINATION include/MarsGE)
install(FILES ${MarsGE_Math_HPP_FILES} DESTINATION include/MarsGE/Math)
