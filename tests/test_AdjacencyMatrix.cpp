#include <gtest/gtest.h>
#include "../include/graph/AdjacencyMatrix.h"
#define SIZE 5
TEST(AdjacencyMatrix, constructorFill) {
    EXPECT_ANY_THROW(AdjacencyMatrix matrix(SIZE, true, -1));
    EXPECT_ANY_THROW(AdjacencyMatrix matrix(SIZE, false, 101));
}
TEST(AdjacencyMatrix, constructorDirected){
    AdjacencyMatrix list(SIZE, true, 100);
    EXPECT_TRUE(list.isDirected());
    AdjacencyMatrix list2(SIZE, false, 100);
    EXPECT_FALSE(list2.isDirected());
}
TEST(AdjacencyMatrix, connectAlreadyConnected){
    AdjacencyMatrix matrix(SIZE, true, 0);
    EXPECT_TRUE(matrix.connect(2, 1, 10));
    EXPECT_FALSE(matrix.connect(2, 1, 0));
}
TEST(AdjacencyMatrix, connectOutOfBounds){
    AdjacencyMatrix matrix(SIZE, true, 0);
    EXPECT_ANY_THROW(matrix.connect(SIZE, SIZE + 1, 0));
    EXPECT_ANY_THROW(matrix.connect(SIZE - SIZE, SIZE - SIZE - 1, 0));
}
TEST(AdjacencyMatrix, disconnectAlreadyDisconnected){
    AdjacencyMatrix matrix(SIZE, true, 0);
    EXPECT_FALSE(matrix.disconnect(2, 0));
    EXPECT_TRUE(matrix.connect(2, 0, 1));
    EXPECT_TRUE(matrix.disconnect(2, 0));
    EXPECT_FALSE(matrix.disconnect(2, 0));
}
TEST(AdjacencyMatrix, disconnectOutOfBounds){
    AdjacencyMatrix matrix(SIZE, true, 0);
    EXPECT_ANY_THROW(matrix.disconnect(SIZE, SIZE + 1));
    EXPECT_ANY_THROW(matrix.disconnect(SIZE - SIZE, SIZE - SIZE - 1));
}
TEST(AdjacencyMatrix, copyConstructor){
    AdjacencyMatrix matrix(SIZE, true, 75);
    AdjacencyMatrix matrix2(matrix);
    EXPECT_EQ(matrix.print(), matrix.print());
}
TEST(AdjacencyMatrix, equalOperator){
    AdjacencyMatrix matrix(SIZE, true, 75);
    AdjacencyMatrix matrix2 = matrix;
    EXPECT_EQ(matrix.print(), matrix2.print());
}