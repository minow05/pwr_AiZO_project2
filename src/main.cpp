#include <iostream>
#include "../include/algorithms/path/DijkstraAlgorithm.h"
#include "../include/graph/AdjacencyMatrix.h"
#include "../include/graph/AdjacencyList.h"
#include "../include/algorithms/MST/PrimAlgorithm.h"
#include "../include/algorithms/MST/KruskalAlgorithm.h"

int main(){
    AdjacencyMatrix matrix(5, true, 100);
    auto *graph = &matrix;
//    PrimAlgorithm prim(graph);
//    KruskalAlgorithm kruskal(graph);
//    kruskal.run(0);
//    std::cout << kruskal.getResult();
//    prim.run(0);
//    std::cout << prim.getResult();
//    std::cout << matrix.print();
    DijkstraAlgorithm dijkstra(graph);
    dijkstra.run(0, 99);
    std::cout << dijkstra.getResult();

}