#include <gtest/gtest.h>
#include "../include/graph/AdjacencyList.h"
#define SIZE 5

TEST(AdjacencyList, connect){
    AdjacencyList list(SIZE);
    EXPECT_TRUE(list.connect(0, 1));
    EXPECT_FALSE(list.connect(0, 1));
}

TEST(AdjacencyList, disconnet){
    AdjacencyList list(SIZE);
    EXPECT_FALSE(list.disconnect(0, 1));
    list.connect(0, 1);
    EXPECT_TRUE(list.disconnect(0, 1));
}

TEST(AdjacencyList, listOutOfBounds){
    AdjacencyList list(SIZE);
    EXPECT_NO_FATAL_FAILURE(list.connect(5, 6));
}

TEST(AdjacencyList, listResize){ //expect removed connections
    AdjacencyList list(SIZE);
    list.connect(0, 1);
    EXPECT_NO_FATAL_FAILURE(list = AdjacencyList(SIZE + 1));
    EXPECT_TRUE(list.connect(0, 1));
        list = AdjacencyList(SIZE);
    list.connect(0, 1);
    EXPECT_NO_FATAL_FAILURE(list = AdjacencyList(SIZE - 1));
    EXPECT_TRUE(list.connect(0, 1));
}

TEST(AdjacencyList, setVertices){
    AdjacencyList list(SIZE);
    list.setVertices(10);
    EXPECT_TRUE(list.connect(0, 9));
}

TEST(AdjacencyList, print){
    AdjacencyList list(SIZE - 2); //3x3 MATRIX
    list.connect(0, 1);
    list.connect(1, 2);
    EXPECT_EQ(list.print(), "0: 1 \n1: 0 2 \n2: 1 \n"); //cursed test
}
