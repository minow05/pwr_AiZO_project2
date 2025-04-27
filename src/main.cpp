#include <iostream>
#include "../include/graph/AdjacencyMatrix.h"
#include "../include/graph/AdjacencyList.h"
int main(){
//    AdjacencyMatrix matrix(5);
//    matrix.connect(0, 0);
//    matrix.connect(0, 1);
//    matrix.connect(3,4);
//    matrix.connect(1, 2);
//    matrix.connect(2, 3);
//    matrix.connect(4, 0);
//    std::cout << matrix.print();
    AdjacencyList gowno(5);
    gowno.connect(0, 1);
    gowno.connect(1, 2);
    gowno.connect(2, 3);
    gowno.connect(3, 4);
    gowno.connect(4, 0);
    std::cout << gowno.print() << "\n";
    std::cout << gowno.disconnect(0, 1);
    std::cout << gowno.print();
}