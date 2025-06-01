#include <gtest/gtest.h>
#include "../include/graph/AdjacencyList.h"
#define SIZE 5

TEST(AdjacencyList, constructorFill) {
    EXPECT_ANY_THROW(AdjacencyList list(SIZE, true, -1));
    EXPECT_ANY_THROW(AdjacencyList list (SIZE, false, 101));
}
TEST(AdjacencyList, constructorDirected){
    AdjacencyList list(SIZE, true, 100);
    EXPECT_TRUE(list.isDirected());
    AdjacencyList list2(SIZE, false, 100);
    EXPECT_FALSE(list2.isDirected());
}
TEST(AdjacencyList, connectAlreadyConnected){
    AdjacencyList list(SIZE, true, 0);
    EXPECT_TRUE(list.connect(2, 1, 10));
    EXPECT_FALSE(list.connect(2, 1, 0));
}
TEST(AdjacencyList, connectOutOfBounds){
    AdjacencyList list(SIZE, true, 0);
    EXPECT_ANY_THROW(list.connect(SIZE, SIZE + 1, 0));
    EXPECT_ANY_THROW(list.connect(SIZE - SIZE, SIZE - SIZE - 1, 0));
}
TEST(AdjacencyList, disconnectAlreadyDisconnected){
    AdjacencyList list(SIZE, true, 0);
    EXPECT_FALSE(list.disconnect(2, 0));
    EXPECT_TRUE(list.connect(2, 0, 1));
    EXPECT_TRUE(list.disconnect(2, 0));
    EXPECT_FALSE(list.disconnect(2, 0));
}
TEST(AdjacencyList, disconnectOutOfBounds){
    AdjacencyList list(SIZE, true, 0);
    EXPECT_ANY_THROW(list.disconnect(SIZE, SIZE + 1));
    EXPECT_ANY_THROW(list.disconnect(SIZE - SIZE, SIZE - SIZE - 1));
}
TEST(AdjacencyList, copyConstructor){
    AdjacencyList list(SIZE, true, 75);
    AdjacencyList list2(list);
    EXPECT_EQ(list.print(), list2.print());
}
TEST(AdjacencyList, equalOperator){
    AdjacencyList list(SIZE, true, 75);
    AdjacencyList list2 = list;
    EXPECT_EQ(list.print(), list2.print());
}
