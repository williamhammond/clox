cmake_minimum_required(VERSION 3.20)
project(clox C)

set(CMAKE_C_STANDARD 11)

set(SOURCE_DIR ./src/)
file(GLOB_RECURSE SOURCE_FILES ${SOURCE_DIR}/*.c)
file(GLOB_RECURSE HEADER_FILES ${SOURCE_DIR}/*.h)

add_executable(clox ${HEADER_FILES} ${SOURCE_FILES})

if (MSVC)
    target_compile_options(clox PRIVATE /W4 /WX)
else ()
    target_compile_options(clox PRIVATE -Wall -Wextra -Werror -Wno-unused-parameter -O0 -DDEBUG -g)
endif ()
