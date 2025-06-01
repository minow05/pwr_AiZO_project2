#include "../include/algorithms/MST/KruskalAlgorithm.h"
#include <queue>
#include <iostream>

void KruskalAlgorithm::algorithmImp(int startingVertex) {
    //TODO: make a way to convert graph to a priority queue of edges, then take lowest edge check
    // if (!cycle) add to MST. Repeat V-1 times.

    std::priority_queue<std::tuple<int, int, int>, std::vector<std::tuple<int, int, int>>, std::greater<>> pq; // weight, ver1, ver2
    int vertices = graph->getNumberOfVertices();
    color = std::vector<int>(vertices);
    for (int i = 0; i < vertices; i++){
        color[i] = i;
    }
    for (int i = 0; i < vertices; i++){
        for (auto& vertex : graph->getNeighbours(i)){
            if (i < vertex.first){
                pq.emplace(vertex.second, i, vertex.first);
            }
        }
    }

    while (!pq.empty()){
        auto [w, v, u] = pq.top(); //weight, vertex1, vertex2
        pq.pop();
        if (!checkCycle(v, u)){
            if (find(v) != find(u)) {
                mst.emplace_back(v, u, w);
                unionSets(v, u);
            }
        }
    }
}

int KruskalAlgorithm::find(int v) {
    if (color[v] != v)
        color[v] = find(color[v]);
    return color[v];
}

void KruskalAlgorithm::unionSets(int a, int b) {
    a = find(a);
    b = find(b);
    if (a != b)
        color[b] = a;
}

bool KruskalAlgorithm::checkCycle(int sourceVertex, int targetVertex) {
    if (color[sourceVertex] == color[targetVertex]){
        return true;
    } else {
        return false;
    }
}

KruskalAlgorithm::KruskalAlgorithm(Graph *graph) {
    assignGraph(graph);
}
