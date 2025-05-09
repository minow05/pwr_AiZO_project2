#include "../include/graph/AdjacencyList.h"
#include <algorithm>

AdjacencyList::AdjacencyList(int size) : vertices(size) {
    buildList(size);
}

std::string AdjacencyList::print() {
    std::ostringstream output;
    int i = 0;
    for (const auto& item : list) {
        output << i << ": ";
        for (auto i : item) {
            output << i << " ";
        }
        output << "\n";
        i++;
    }
    return output.str();
}

AdjacencyList::AdjacencyList(AdjacencyList &adjList) {
    this -> list = adjList.list;
    this -> vertices = adjList.vertices;

}

bool AdjacencyList::connect(int vertex1, int vertex2) {
    if (vertex1 >= vertices || vertex2 >= vertices){
        return false;
    } else {
        if (std::find(list[vertex1].begin(), list[vertex1].end(), vertex2) == list[vertex1].end()){
            list[vertex1].push_back(vertex2);
            list[vertex1].sort();
            return true;
        }
        return false;
    }
}

bool AdjacencyList::disconnect(int vertex1, int vertex2) {
    if (vertex1 >= vertices || vertex2 >= vertices){
        return false;
    } else {
        if (std::find(list[vertex1].begin(), list[vertex1].end(), vertex2) != list[vertex1].end()){
            list[vertex1].remove(vertex2);
            list[vertex1].sort();
            return true;
        } else {
            return false;
        }
    }
}

void AdjacencyList::buildList(int size) {
    this->list = std::vector<std::list<int>>(size, std::list<int>());
}

void AdjacencyList::setVertices(int size) {
    this->vertices = size;
    buildList(size);
}

AdjacencyList &AdjacencyList::operator=(AdjacencyList &adjacencyList) {
    if (this == &adjacencyList){
        return *this;
    }
    this -> list = adjacencyList.list;
    this -> vertices = adjacencyList.vertices;
    return *this;
}
