#include "../include/algorithms/path/FordBellmanAlgorithm.h"

FordBellmanAlgorithm::FordBellmanAlgorithm(Graph *graph) {
    assignGraph(graph);
}

void FordBellmanAlgorithm::algorithmImp(int startingVertex, int endVertex) {
    std::vector<int> distance(graph->getNumberOfVertices(), INT_MAX);
    distance[startingVertex] = 0;
    std::vector<std::vector<std::pair<int, int>>> paths(graph->getNumberOfVertices());
    std::vector<std::tuple<int, int, int>> edges;
    for (int i = 0; i < graph->getNumberOfVertices(); i++){
        for (auto& [v, w] : graph->getNeighbours(i)){
            if (i > v){
                edges.emplace_back(i, v, w);
            }
        }
    }
    for (int i = 0; i < graph->getNumberOfVertices(); i++){

    }
}
