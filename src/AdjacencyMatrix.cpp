#include "../include/graph/AdjacencyMatrix.h"

AdjacencyMatrix::AdjacencyMatrix(int vertices) : vertices(vertices) {
    buildMatrix(vertices);
}

AdjacencyMatrix::AdjacencyMatrix(AdjacencyMatrix &adjMatrix) {
    this -> vertices = adjMatrix.vertices;
    this -> matrix = adjMatrix.matrix;
}

void AdjacencyMatrix::buildMatrix(int size) {
    matrix = std::vector<std::vector<int>>(size, std::vector<int>(size, 0));
}

void AdjacencyMatrix::setVertices(int size) {
    this->vertices = size;
    buildMatrix(size);
}

bool AdjacencyMatrix::connect(int vertex1, int vertex2) {
    if (vertex1 >= vertices || vertex2 >= vertices){
        return false;
    }
    if (matrix[vertex1][vertex2] == 1 && matrix[vertex2][vertex1] == 1){
        return false;
    } else {
        matrix[vertex1][vertex2] = 1;
        matrix[vertex2][vertex1] = 1;
        return true;
    }
}

bool AdjacencyMatrix::disconnect(int vertex1, int vertex2) {
    if (vertex1 >= vertices || vertex2 >= vertices){
        return false;
    }
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

AdjacencyMatrix& AdjacencyMatrix::operator= (const AdjacencyMatrix &adjMatrix) {
    if (this == &adjMatrix){
        return *this;
    }
    this -> vertices = adjMatrix.vertices;
    this -> matrix = adjMatrix.matrix;
    return *this;
}


