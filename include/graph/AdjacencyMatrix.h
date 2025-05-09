//
// Created by minow on 25-Apr-25.
//

#ifndef PWR_AIZO_PROJECT2_ADJACENCYMATRIX_H
#define PWR_AIZO_PROJECT2_ADJACENCYMATRIX_H

#include <vector>
#include <string>
#include <sstream>

class AdjacencyMatrix{
    // weighted + directed graph
public:

    explicit AdjacencyMatrix(int vertices, bool directed, float fill);
    AdjacencyMatrix(AdjacencyMatrix& adjMatrix);
    AdjacencyMatrix& operator= (const AdjacencyMatrix& adjMatrix);
    void setVertices(int size);
    void build(float fill);

    void convert();
    bool directed = false;

    std::string print();
private:
    bool connect(int vertex1, int vertex2, int weight);
    bool disconnect(int vertex1, int vertex2);
    int vertices;
    std::vector<std::vector<int>> matrix;
    void buildMatrix(int size);
};

#endif //PWR_AIZO_PROJECT2_ADJACENCYMATRIX_H
