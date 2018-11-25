cmake_minimum_required(VERSION 3.12)
project(Project1)

set(CMAKE_CXX_STANDARD 17)

add_executable(Project1
        src/main.cpp
        src/ATSP.h
        src/BB.cpp
        src/BB.h
        src/BF.cpp
        src/BF.h
        src/DP.cpp
        src/DP.h
        include/Array.cpp
        include/Array.h
        include/Graph.cpp
        include/Graph.h
        include/Node.cpp
        include/Node.h
        include/Timer.cpp
        include/Timer.h
        include/IndexOutOfBoundsException.h
        include/FileNotFoundException.h
        include/FileHandler.cpp
        include/FileHandler.h)