cmake_minimum_required(VERSION 3.20)
project(clox C)

set(CMAKE_C_STANDARD 11)
set(SOURCE_FILES main.c debug.c debug.h memory.c memory.h chunk.c chunk.h value.c value.h vm.c vm.h)

add_executable(clox ${SOURCE_FILES})

if (MSVC)
    target_compile_options(clox PRIVATE /W4 /WX)
else ()
    target_compile_options(clox PRIVATE -Wall -Wextra -pedantic -Wshadow -Wdouble-promotion -Wundef -Wconversion)
endif ()
