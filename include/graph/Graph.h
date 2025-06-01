#ifndef PWR_AIZO_PROJECT2_GRAPH_H
#define PWR_AIZO_PROJECT2_GRAPH_H

#include <string>
#include <vector>

#define MINIMUM_WEIGHT 1
#define NO_CONNECTION 0

class Graph {
public:
    virtual bool connect(int vertex1, int vertex2, int weight) = 0;
    virtual bool disconnect(int vertex1, int vertex2) = 0;
    virtual std::string print() = 0;
    virtual bool isDirected() const = 0;
    virtual int getNumberOfVertices() = 0;
    virtual std::vector<std::pair<int, int>> getNeighbours(int vertex) = 0;
};

#endif //PWR_AIZO_PROJECT2_GRAPH_H
