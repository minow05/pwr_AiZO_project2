#include <iostream>
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
            edges.emplace_back(i, v, w);
        }
    }
    for (int i = 0; i < graph->getNumberOfVertices(); i++){
        for (auto [v1, v2 , w] : edges){
            if (distance[v2] > distance[v1] + w){

                if (i == graph->getNumberOfVertices() - 1){
                    negativeCycle();
                    break;
                }
                distance[v2] = distance[v1] + w;
                if (distance[v1] != INT_MAX){
                    paths[v2].clear();
                    paths[v2].emplace_back(v1, w);
                }
            }
        }
    }
    pathWeight = distance[endVertex];
    int currentVertex = endVertex;

    while (currentVertex != startingVertex){
        if (paths[currentVertex].empty()) {
            path.clear();
            pathWeight = INT_MAX;
            break;
        }
        auto [prev, weight] = paths[currentVertex].back();
        path.emplace_back(currentVertex, prev, weight);
        currentVertex = prev;
    }
}

void FordBellmanAlgorithm::negativeCycle(){
    this->path = std::vector<std::tuple<int,int,int>> {{INT_MAX, INT_MAX, INT_MAX}};
}
