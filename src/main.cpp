#include <iostream>
#include "../include/algorithms/MST/PrimAlgorithm.h"
#include "../include/graph/AdjacencyMatrix.h"
#include "../include/graph/AdjacencyList.h"
#include "../include/algorithms/MST/MstAlgorithmBase.h"

int main(){
    AdjacencyMatrix matrix(5, true, 50);
    auto *graph = &matrix;
    PrimAlgorithm prim(graph);
    prim.run();
    std::cout << prim.getResult();
    std::cout << matrix.print();
}