cmake_minimum_required(VERSION 3.30)
project(chip8 C)

set(CMAKE_C_STANDARD 11)

add_subdirectory(lib/simple-console-engine)
add_executable(chip8 src/main.c
        src/chip8.h
        src/chip8.c
        src/instructions.h
        src/io.c
        src/io.h
        src/instructions.c
)
target_link_libraries(chip8 PRIVATE console_engine)
