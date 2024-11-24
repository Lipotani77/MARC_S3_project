cmake_minimum_required(VERSION 3.27)
project(untitled1 C)

set(CMAKE_C_STANDARD 11)

add_executable(untitled1 src/main.c
        src/loc.c
        include/loc.h
        src/moves.c
        include/moves.h
        src/map.c
        include/map.h
        src/queue.c
        include/queue.h
        src/stack.c
        include/stack.h
        src/node.c
        include/node.h
        src/tree.c
        include/tree.h
        include/path.h
        src/path.c
        include/draw.h
        src/draw.c
        src/complexity.c
        include/complexity.h
)
