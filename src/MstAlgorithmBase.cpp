#include <chrono>
#include <iostream>
#include "../include/algorithms/MST/MstAlgorithmBase.h"

void MstAlgorithmBase::initializeMst() {
    mst = std::list<std::pair<int, int>>();
}

void MstAlgorithmBase::run() {
    auto start = std::chrono::high_resolution_clock::now();
    this->algorithmImp();
    auto stop = std::chrono::high_resolution_clock::now();
    currentTime = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
}

bool MstAlgorithmBase::assignGraph(Graph *graph) {
    this->initializeMst();
    this->graph = graph;
    return true;
}

std::string MstAlgorithmBase::getResult() {
    std::ostringstream output;
    output << "Time: " << currentTime.count() << " us\n";
    for (auto element : mst) {
        output << "mst.first: " << element.first << " mst.second: " << element.second << '\n';
    }
    return output.str();
}

