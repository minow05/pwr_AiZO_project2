cmake_minimum_required(VERSION 3.31)
project(pwr_AiZO_project2)

set(CMAKE_CXX_STANDARD 20)

add_executable(pwr_AiZO_project2 src/main.cpp
        include/graph/AdjacencyMatrix.h
        include/graph/AdjacencyList.h
        src/AdjacencyList.cpp
        src/AdjacencyMatrix.cpp)
