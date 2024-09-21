cmake_minimum_required(VERSION 3.10)

project(Raytracer VERSION 1.0)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED True)

include_directories(includes)

set(SOURCES
    src/main.c
    src/camera.c
    src/color.c
    src/object.c
    src/render.c
    src/transformations.c
    src/vector.c
)

add_compile_definitions(OBJECTS="${CMAKE_CURRENT_SOURCE_DIR}/objects")
add_compile_definitions(RENDERS="${CMAKE_CURRENT_SOURCE_DIR}/renders")

add_executable(Raytracer ${SOURCES})


if (WIN32)
    message("Compiling on Windows")
    add_compile_definitions(VISUAL_STUDIO)
elseif (UNIX)
    message("Compiling on Unix-based OS")
endif()
