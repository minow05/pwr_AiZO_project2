#include <iostream>
#include "../include/graph/AdjacencyMatrix.h"
int main(){
    AdjacencyMatrix matrix(5);
    matrix.connect(0, 0);
    matrix.connect(0, 1);
    matrix.connect(3,4);
    matrix.connect(1, 2);
    matrix.connect(2, 3);
    matrix.connect(4, 0);
    std::cout << matrix.print();
}