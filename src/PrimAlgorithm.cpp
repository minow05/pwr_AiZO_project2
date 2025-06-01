#include <algorithm>
#include <queue>
#include <iostream>
#include "../include/algorithms/MST/PrimAlgorithm.h"

void PrimAlgorithm::algorithmImp(int startingVertex) {
    int vertices = graph->getNumberOfVertices();
    std::vector<bool> visited(vertices, false);
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> pq;
    pq.emplace(INT_MAX, startingVertex); //weight 1st cuz prioqueue
    visited[startingVertex] = true;

    int previousVertex = startingVertex;

    for (const auto& element : graph->getNeighbours(startingVertex)) {
        pq.emplace(element.second, element.first);
    }
    while (!pq.empty()){
        auto node = pq.top();
        pq.pop();
        if (visited[node.second]){
            continue;
        }
        mst.emplace_back(previousVertex, node.second, node.first);
        previousVertex = node.second;
        visited[node.second] = true;
        for (const auto& neighbour : graph->getNeighbours(node.second)) {
            if (!visited[neighbour.first]) pq.emplace(neighbour.second, neighbour.first);
        }
    }
}

PrimAlgorithm::PrimAlgorithm(Graph *graph){
    assignGraph(graph);
}
