#include <iostream>
#include "../include/graph/AdjacencyMatrix.h"
#include "../include/graph/AdjacencyList.h"
int main(){
    AdjacencyMatrix matrix(5, true, 100);
    std::cout << matrix.print();


}