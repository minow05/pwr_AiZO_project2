#ifndef PWR_AIZO_PROJECT2_ADJACENCYMATRIX_H
#define PWR_AIZO_PROJECT2_ADJACENCYMATRIX_H

#include <vector>
#include <string>
#include <sstream>
#include "Graph.h"

class AdjacencyMatrix : public Graph{
    // weighted + directed graph
public:
    explicit AdjacencyMatrix(int vertices, bool directed, float fill);
    AdjacencyMatrix(AdjacencyMatrix& adjMatrix);
    AdjacencyMatrix& operator= (const AdjacencyMatrix& adjMatrix);
    bool isDirected() const override;
    std::string print() override;
    int getNumberOfVertices() override;
    std::vector<std::pair<int, int>> getNeighbours(int vertex) override;
    bool connect(int vertex1, int vertex2, int weight) override;
    bool disconnect(int vertex1, int vertex2) override;
private:
    bool directed = false;
    int vertices;
    std::vector<std::vector<int>> matrix;
    void buildMatrix(int size);
    void build(float fill);
    void convert();
};

#endif //PWR_AIZO_PROJECT2_ADJACENCYMATRIX_H
