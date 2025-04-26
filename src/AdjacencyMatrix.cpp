#include <iostream>
#include <sstream>
#include "../include/graph/AdjacencyMatrix.h"

AdjacencyMatrix::AdjacencyMatrix(int vertices) : vertices(vertices) {
    buildMatrix(vertices);
}

void AdjacencyMatrix::buildMatrix(int vertices) {
    matrix = std::vector<std::vector<int>>(vertices, std::vector<int>(vertices, 0));
}

void AdjacencyMatrix::setVertices(int size) {
    this->vertices = size;
    buildMatrix(size);
}

bool AdjacencyMatrix::connect(int vertex1, int vertex2) {
    if (matrix[vertex1][vertex2] == 1 && matrix[vertex2][vertex1] == 1){
        return false;
    } else {
        matrix[vertex1][vertex2] = 1;
        matrix[vertex2][vertex1] = 1;
        return true;
    }
}

bool AdjacencyMatrix::disconnect(int vertex1, int vertex2) {
    if (matrix[vertex1][vertex2] == 0 && matrix[vertex2][vertex1] == 0){
        return false;
    } else {
        matrix[vertex1][vertex2] = 0;
        matrix[vertex2][vertex1] = 0;
        return true;
    }
}

std::string AdjacencyMatrix::print() {
    std::ostringstream output;
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            output << matrix[i][j] << " ";
        }
        output << "\n";
    }
    return output.str();
}
