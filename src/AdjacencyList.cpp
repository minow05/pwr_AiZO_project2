#include "../include/graph/AdjacencyList.h"
#include <algorithm>
#include <random>
#include <iostream>


AdjacencyList::AdjacencyList(int size, bool directed, float fill) : vertices(size), directed(directed) {
    if (fill < 0.0 || fill > 100.0){
        throw std::invalid_argument("Fill must be between 0.0 and 100.0");
    }
    buildList(size);
    build(fill);
    if (!directed){
        convert();
    }
}

std::string AdjacencyList::print() {
    std::ostringstream output;
    int i = 0;
    for (const auto& item : list) {
        output << i << ": ";
        for (auto i : item) {
            output << i.first << ":" << i.second << ", ";
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

bool AdjacencyList::connect(int vertex1, int vertex2, int weight) {
    if (vertex1 >= vertices || vertex2 >= vertices || vertex1 < 0 || vertex2 < 0){
        throw std::invalid_argument("Vertex out of range");
    } else {
        if (std::find_if(list[vertex1].begin(), list[vertex1].end(),[vertex2](const std::pair<int, int>& pair) {return pair.first == vertex2;}) == list[vertex1].end()){
            list[vertex1].emplace_back(vertex2, weight);
            list[vertex1].sort();
            return true;
        }
        return false;
    }
}

bool AdjacencyList::disconnect(int vertex1, int vertex2) {
    if (vertex1 >= vertices || vertex2 >= vertices || vertex1 < 0 || vertex2 < 0){
        throw std::invalid_argument("Vertex out of range");
    } else {
        if (std::find_if(list[vertex1].begin(), list[vertex1].end(),[vertex2](const std::pair<int, int>& pair) {return pair.first == vertex2;}) != list[vertex1].end()){
            list[vertex1].remove_if([vertex2](const std::pair<int, int>& pair) {return pair.first == vertex2;});
            list[vertex1].sort();
            return true;
        }
        return false;
    }
}

void AdjacencyList::buildList(int size) {
    this->list = std::vector<std::list<std::pair<int, int>>>(size, std::list<std::pair<int, int>>());
}

AdjacencyList &AdjacencyList::operator=(const AdjacencyList &adjacencyList) {
    if (this == &adjacencyList){
        return *this;
    }
    this -> list = adjacencyList.list;
    this -> vertices = adjacencyList.vertices;
    return *this;
}

void AdjacencyList::build(float fill) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(MINIMUM_WEIGHT, vertices - 1);
    int counter = 0;
    for (int i = 1; i < vertices; i++){
        this->connect(i - 1, i, dist(gen));
        counter++;
    }
    float connectionsToFill = std::floor(static_cast<float>(vertices) * static_cast<float>(vertices - 1) * fill / 100.0);
    int toConnect = static_cast<int>(connectionsToFill) - counter;
    for (int i = 0; i < toConnect; i++){
        int vertex1 = dist(gen);
        int vertex2 = dist(gen);
        if (vertex1 == vertex2){
            i--;
            continue;
        }
        if(!this->connect(vertex1, vertex2, dist(gen))){
            i--;
            continue;
        }
    }
}

void AdjacencyList::convert() {
    for(int i = 0; i < vertices; i++){
        for(auto vertex : list[i]){
            this->disconnect(vertex.first, i);
            this->connect(vertex.first, i, vertex.second);
        }
    }
}

bool AdjacencyList::isDirected() const {
    return directed;
}

int AdjacencyList::getNumberOfVertices() {
    return this->vertices;
}

std::vector<std::pair<int, int>> AdjacencyList::getNeighbours(int vertex) {
    if (vertex >= vertices || vertex < 0){
        throw std::invalid_argument("Vertex out of range");
    }

    std::vector<std::pair<int, int>> output;
    for (auto &vertexPair : list[vertex]){
        output.push_back(vertexPair);
    }
    return output;
}
