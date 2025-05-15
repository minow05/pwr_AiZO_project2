#include <algorithm>
#include <iostream>
#include "../include/algorithms/MST/PrimAlgorithm.h"

void PrimAlgorithm::algorithmImp() {
    int vertices = graph->getNumberOfVertices();
//    int startVertex = std::rand() % vertices;
    int startVertex = 0;
    mst.emplace_back(startVertex,NOCONNECTION);
    while (1) {
        //TODO: V-1 times for each element in MST, get neighbours which are not in MST,
        // get lowest weight connection, check if (!cycle) return add that element to MST.
        std::vector<std::pair<int, int>> neighbours;
        for (auto element : mst) {
            neighbours.insert(neighbours.end(), graph->getNeighbours(element.first).begin(), graph->getNeighbours(element.first).end());
            for (auto &neighbour : neighbours){
                if (neighbour == element){
                    std::remove(neighbours.begin(), neighbours.end(),neighbour);
                }
            }
        }
        bool found = false;
        int counter = 0;
        while (!found){
            std::sort(neighbours.begin(), neighbours.end(), [](const std::pair<int, int>& a, const std::pair<int, int>& b) {return a.second < b.second;});
            if (!checkCycle(neighbours[counter].first)){
                mst.emplace_back(neighbours[counter]);
                found = true;
            }
            counter++;
            if (counter >= neighbours.size()){
                found = true;
            }
        }
        if (mst.size() >= vertices){
            break;
        }
    }
}

bool PrimAlgorithm::checkCycle(int vertex) {
    for (auto neighbour : graph->getNeighbours(vertex)) {
        if (std::find_if(mst.begin(), mst.end(),[neighbour](const std::pair<int, int>& pair) {return pair.first == neighbour.first;}) != mst.end()){
            return true;
        }
    }
    return false;
}

PrimAlgorithm::PrimAlgorithm(Graph *graph){
    this->graph = graph;
}
