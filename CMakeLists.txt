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

add_executable(Raytracer ${SOURCES})

add_custom_command(
    TARGET Raytracer POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E make_directory $<TARGET_FILE_DIR:Raytracer>/objects
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_SOURCE_DIR}/objects $<TARGET_FILE_DIR:Raytracer>/objects
)

if (WIN32)
    message("Compiling on Windows")
elseif (UNIX)
    message("Compiling on Unix-based OS")
endif()
