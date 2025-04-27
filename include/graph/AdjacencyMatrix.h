//
// Created by minow on 25-Apr-25.
//

#ifndef PWR_AIZO_PROJECT2_ADJACENCYMATRIX_H
#define PWR_AIZO_PROJECT2_ADJACENCYMATRIX_H

#include <vector>
#include <string>
#include <sstream>

class AdjacencyMatrix{
public:
    explicit AdjacencyMatrix(int vertices);
    AdjacencyMatrix(AdjacencyMatrix& adjMatrix);
    AdjacencyMatrix& operator= (const AdjacencyMatrix& adjMatrix);
    bool connect(int vertex1, int vertex2);
    bool disconnect(int vertex1, int vertex2);
    void setVertices(int size);
    std::string print();
private:
    int vertices;
    std::vector<std::vector<int>> matrix;
    void buildMatrix(int size);
};

#endif //PWR_AIZO_PROJECT2_ADJACENCYMATRIX_H
