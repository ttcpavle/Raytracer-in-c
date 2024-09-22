cmake_minimum_required(VERSION 3.10)

project(Raytracer VERSION 1.0)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED True)

include_directories(includes)

# source files
set(SOURCES
    src/main.c
    src/camera.c
    src/color.c
    src/object.c
    src/render.c
    src/transformations.c
    src/vector.c
)

set(HEADER_FILES
    includes/config.h
    includes/camera.h
    includes/color.h
    includes/object.h
    includes/render.h
    includes/transformations.h
    includes/vector.h
)

# objects and renders path macro
add_compile_definitions(OBJECTS="${CMAKE_CURRENT_SOURCE_DIR}/objects")
add_compile_definitions(RENDERS="${CMAKE_CURRENT_SOURCE_DIR}/renders")

add_executable(Raytracer ${SOURCES} ${HEADER_FILES})

if (WIN32)
    message("Compiling on Windows")
    add_compile_definitions(WINDOWS)
    if (MSVC)
        message("Compiling with Microsoft Visual Studio")
        add_compile_definitions(VISUAL_STUDIO)
    endif()
elseif (UNIX)
    message("Compiling on Unix-based OS")
    target_link_libraries(Raytracer m)
    add_compile_definitions(UNIXOS)
elseif (APPLE)
    message("Compiling on macOS")
    add_compile_definitions(MACOS)
endif()