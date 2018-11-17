cmake_minimum_required(VERSION 3.12)
project(Project1)

set(CMAKE_CXX_STANDARD 17)

add_executable(Project1
        src/main.cpp
        include/Array.cpp
        include/Array.h
        include/IndexOutOfBoundsException.h
        src/ATSP.cpp
        src/ATSP.h
        include/Graph.cpp
        include/Graph.h
        include/Node.cpp
        include/Node.h
        include/Timer.cpp
        include/Timer.h)
        include/FileNotFoundException.h)