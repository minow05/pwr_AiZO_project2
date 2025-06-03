#include <chrono>
#include <iostream>
#include "../include/algorithms/MST/MstAlgorithmBase.h"

void MstAlgorithmBase::initializeMst() {
    mst = std::list<std::tuple<int, int, int>>(graph->getNumberOfVertices());
}

void MstAlgorithmBase::run(int startingVertex) {
    if (graph->isDirected()){
        throw std::invalid_argument("Graph directed. Unable to generate MST");
    }
    if (graph == nullptr){
        throw std::invalid_argument("Graph not assigned");
    }
    auto start = std::chrono::high_resolution_clock::now();
    this->algorithmImp(startingVertex);
    auto stop = std::chrono::high_resolution_clock::now();
    currentTime = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
}

bool MstAlgorithmBase::assignGraph(Graph *graph) {
    this->graph = graph;
    this->initializeMst();
    return true;
}

std::string MstAlgorithmBase::getResult() {
    std::ostringstream output;
    output << "Graph: " << graph->getNumberOfVertices() <<  " vertices\n";
    output << "Time: " << currentTime.count() << " us\n";
//    int totalWeight = 0;
//    for (auto element : mst) {
//        output << "Vertex1: " << get<0>(element) << " Vertex2: " << get<1>(element) << " Weight: " << get<2>(element) << '\n';
//        totalWeight += get<2>(element);
//    }
//    output << "Total weight: " << totalWeight << '\n';
    return output.str();
}

