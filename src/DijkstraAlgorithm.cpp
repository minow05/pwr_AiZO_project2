#include "../include/algorithms/path/DijkstraAlgorithm.h"
#include "queue"

void DijkstraAlgorithm::algorithmImp(int startingVertex, int endVertex) {
    std::vector<int> distance(graph->getNumberOfVertices(), INT_MAX);
    distance[startingVertex] = 0;
    std::vector<std::vector<std::pair<int, int>>> paths(graph->getNumberOfVertices());
    std::priority_queue<std::tuple<int, int, int>, std::vector<std::tuple<int, int, int>>, std::greater<>> pq; //weight, vertex
    for (auto vertex : graph->getNeighbours(startingVertex)){
        pq.emplace(vertex.second, startingVertex, vertex.first);
    }
    while (!pq.empty()){
        auto [w, v1, v2] = pq.top();
        pq.pop();
        if(distance[v2] > distance[v1] + w){
            distance[v2] = distance[v1] + w;
//            pq.emplace(distance[v2], v1, v2);
            for (auto [vertex, weight] : graph->getNeighbours(v2)){
                if (vertex != v1){
                    pq.emplace(weight, v2, vertex);
                }
            }
            paths[v2].emplace_back(v1, w);
        }
    }
    pathWeight = distance[endVertex];
    int currentVertex = endVertex;
    while (currentVertex != startingVertex){
        int temp = paths[currentVertex].back().first;
        path.emplace_back(currentVertex, paths[currentVertex].back().first, paths[currentVertex].back().second);
        paths[currentVertex].pop_back();
        currentVertex = temp;
    }
}

DijkstraAlgorithm::DijkstraAlgorithm(Graph *graph) {
    assignGraph(graph);
}
