cmake_minimum_required(VERSION 3.30.5)
project(pwr_AiZO_project2)

set(CMAKE_CXX_STANDARD 20)

add_executable(pwr_AiZO_project2 src/main.cpp
        include/graph/AdjacencyMatrix.h
        include/graph/AdjacencyList.h
        src/AdjacencyList.cpp
        src/AdjacencyMatrix.cpp
        include/algorithms/MST/MstAlgorithmBase.h
        include/algorithms/path/PathAlgorithmBase.h
        include/algorithms/MST/PrimAlgorithm.h
        include/algorithms/MST/KruskalAlgorithm.h
        include/algorithms/path/DijkstraAlgorithm.h
        include/algorithms/path/FordBellmanAlgorithm.h
        src/MstAlgorithmBase.cpp
        include/graph/Graph.h
        src/KruskalAlgorithm.cpp
        src/PrimAlgorithm.cpp
        src/PathAlgorithmBase.cpp
        src/DijkstraAlgorithm.cpp
        src/FordBellmanAlgorithm.cpp

)

include(FetchContent)

FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(tests
        tests/test_AdjacencyMatrix.cpp
        tests/test_AdjacencyList.cpp
        src/AdjacencyMatrix.cpp
        src/AdjacencyList.cpp
        src/MstAlgorithmBase.cpp
        src/KruskalAlgorithm.cpp
        src/PathAlgorithmBase.cpp
        src/DijkstraAlgorithm.cpp
        src/FordBellmanAlgorithm.cpp
)

target_include_directories(tests PRIVATE include)

target_link_libraries(tests PRIVATE GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(tests)