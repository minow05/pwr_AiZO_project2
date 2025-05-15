#ifndef PWR_AIZO_PROJECT2_ADJACENCYLIST_H
#define PWR_AIZO_PROJECT2_ADJACENCYLIST_H

#include <string>
#include <sstream>
#include <list>
#include <vector>
#include "Graph.h"

class AdjacencyList : public Graph {
public:
    AdjacencyList(int size, bool directed, float fill);
    AdjacencyList(AdjacencyList& adjList);
    AdjacencyList& operator= (const AdjacencyList& adjacencyList);
    bool connect(int vertex1, int vertex2, int weight) override;
    bool disconnect(int vertex1, int vertex2) override;
    int getNumberOfVertices() override;
    std::vector<std::pair<int, int>> getNeighbours(int vertex) override;
    bool isDirected() const override;
    std::string print() override;
private:
    bool directed = false;
    int vertices;
    std::vector<std::list<std::pair<int, int>>> list; //list is better for deletions and insertions (I won't need those)
    void buildList(int size);
    void build(float fill);
    void convert();
};
#endif //PWR_AIZO_PROJECT2_ADJACENCYLIST_H
