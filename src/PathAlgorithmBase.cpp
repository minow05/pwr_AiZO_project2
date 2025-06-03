#include "../include/algorithms/path/PathAlgorithmBase.h"

bool PathAlgorithmBase::assignGraph(Graph *graph) {
    this->graph = graph;
    this->initializeMst();
    return true;
}

void PathAlgorithmBase::run(int startingVertex, int endVertex) {
    if (endVertex >= graph->getNumberOfVertices() || startingVertex < 0){
        throw std::invalid_argument("Vertices out of bounds");
    }
    if (!graph->isDirected()){
        throw std::invalid_argument("Graph not directed. Unable to generate Longest Path");
    }
    if (graph == nullptr){
        throw std::invalid_argument("Graph not assigned");
    }
    auto start = std::chrono::high_resolution_clock::now();
    this->algorithmImp(startingVertex, endVertex);
    auto stop = std::chrono::high_resolution_clock::now();
    currentTime = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
}

std::string PathAlgorithmBase::getResult() {
    std::ostringstream output;
    output << "Graph: " << graph->getNumberOfVertices() <<  " vertices\n";
    output << "Time: " << currentTime.count() << " us\n";
//    for (auto element : path) {
//        output << "Vertex1: " << get<0>(element) << " Vertex2: " << get<1>(element) << " Weight: " << get<2>(element) << '\n';
//    }
//    output << "Total weight: " << pathWeight << '\n';
    return output.str();
}

void PathAlgorithmBase::initializeMst() {
    this->path = std::vector<std::tuple<int, int, int>>();
}
