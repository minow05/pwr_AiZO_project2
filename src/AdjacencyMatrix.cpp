#include <random>
#include "../include/graph/AdjacencyMatrix.h"
#define NOCONNECTION -1
AdjacencyMatrix::AdjacencyMatrix(int vertices, bool directed, float fill) : vertices(vertices), directed(directed) {
    if (fill < 0.0 || fill > 100.0){
        throw std::invalid_argument("Fill must be between 0.0 and 100.0");
    }
    buildMatrix(vertices);
    build(fill);
    if (directed){
        convert();
    }
}

AdjacencyMatrix::AdjacencyMatrix(AdjacencyMatrix &adjMatrix) {
    this -> vertices = adjMatrix.vertices;
    this -> matrix = adjMatrix.matrix;
}

void AdjacencyMatrix::buildMatrix(int size) {
    matrix = std::vector<std::vector<int>>(size, std::vector<int>(size, NOCONNECTION));
}

void AdjacencyMatrix::setVertices(int size) {
    this->vertices = size;
    buildMatrix(size);
}

bool AdjacencyMatrix::connect(int vertex1, int vertex2, int weight) {
    if (vertex1 >= vertices || vertex2 >= vertices){
        return false;
    }
    if (matrix[vertex1][vertex2] > NOCONNECTION){
        return false;
    } else {
        matrix[vertex1][vertex2] = weight;
        return true;
    }
}

bool AdjacencyMatrix::disconnect(int vertex1, int vertex2) {
    if (vertex1 >= vertices || vertex2 >= vertices){
        return false;
    }
    if (matrix[vertex1][vertex2] == NOCONNECTION){
        return false;
    } else {
        matrix[vertex1][vertex2] = NOCONNECTION;
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

void AdjacencyMatrix::convert() {
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            if (matrix[i][j] > 1){
                int weight = matrix[i][j];
                this->connect(i, j, weight);
            }
        }
    }
}

void AdjacencyMatrix::build(float fill) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, vertices - 1);
    int counter = 0;
    for (int i = 1; i < vertices; i++) {
        this->connect(i - 1, i, dist(gen));
        counter++;
    }
    float connectionsToFill = vertices * (vertices - 1) * fill / 100.0;
    int toConnect = std::ceil(connectionsToFill) - counter;
    if (toConnect > 0){
        for (int i = 0; i < toConnect; i++) {
            int vertex1 = dist(gen);
            int vertex2 = dist(gen);
            if (vertex1 == vertex2){
                i--;
                continue;
            }
            this->connect(vertex1, vertex2, dist(gen));
        }
    }
}


