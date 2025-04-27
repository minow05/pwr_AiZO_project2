#include <gtest/gtest.h>
#include "../include/graph/AdjacencyMatrix.h"
#define SIZE 5

TEST(AdjacencyMatrix, connect){
    AdjacencyMatrix matrix(SIZE);
    EXPECT_TRUE(matrix.connect(0, 1));
    EXPECT_FALSE(matrix.connect(0, 1));
}

TEST(AdjacencyMatrix, disconnet){
    AdjacencyMatrix matrix(SIZE);
    EXPECT_FALSE(matrix.disconnect(0, 1));
    matrix.connect(0, 1);
    EXPECT_TRUE(matrix.disconnect(0, 1));
}

TEST(AdjacencyMatrix, matrixOutOfBounds){
    AdjacencyMatrix matrix(SIZE);
    EXPECT_NO_FATAL_FAILURE(matrix.connect(5, 6));
}

TEST(AdjacencyMatrix, martixConnectionsAfterResize){ //expect removed connections
    AdjacencyMatrix matrix(SIZE);
    matrix.connect(0, 1);
    EXPECT_NO_FATAL_FAILURE(matrix.setVertices(SIZE + 1));
    EXPECT_TRUE(matrix.connect(0, 1));
    matrix = AdjacencyMatrix(SIZE);
    matrix.connect(0, 1);
    EXPECT_NO_FATAL_FAILURE(matrix.setVertices(SIZE - 1));
    EXPECT_TRUE(matrix.connect(0, 1));
}

TEST(AdjacencyMatrix, setVertices){
    AdjacencyMatrix matrix(SIZE);
    matrix.setVertices(10);
    EXPECT_TRUE(matrix.connect(0,9));
}

TEST(AdjacencyMatrix, print){
    AdjacencyMatrix matrix(SIZE - 2); //3x3 MATRIX
    EXPECT_EQ(matrix.print(), "0 0 0 \n0 0 0 \n0 0 0 \n"); //cursed test
}
