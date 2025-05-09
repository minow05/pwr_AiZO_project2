cmake_minimum_required(VERSION 3.31)
project(pwr_AiZO_project2)

set(CMAKE_CXX_STANDARD 20)

add_executable(pwr_AiZO_project2 src/main.cpp
        include/graph/AdjacencyMatrix.h
        include/graph/AdjacencyList.h
        src/AdjacencyList.cpp
        src/AdjacencyMatrix.cpp
        include/graph/GraphBuilder.h
        include/algorithms/MST/MstAlgorithmBase.h
        include/algorithms/path/PathAlgorithmBase.h
        include/algorithms/MST/PrimAlgorithm.h
        include/algorithms/MST/KruskalAlgorithm.h
        include/algorithms/path/DijkstraAlgorithm.h
        include/algorithms/path/FordBellmanAlgorithm.h

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
)

target_include_directories(tests PRIVATE include)

target_link_libraries(tests PRIVATE GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(tests)