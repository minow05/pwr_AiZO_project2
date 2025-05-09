#ifndef PWR_AIZO_PROJECT2_ADJACENCYLIST_H
#define PWR_AIZO_PROJECT2_ADJACENCYLIST_H

#include <string>
#include <sstream>
#include <list>
#include <vector>

class AdjacencyList {
public:
    explicit AdjacencyList(int size);
    AdjacencyList(AdjacencyList& adjList);
    AdjacencyList& operator= (AdjacencyList& adjacencyList);
    bool connect(int vertex1, int vertex2);
    bool disconnect(int vertex1, int vertex2);
    void setVertices(int size);
    std::string print();
private:
    int vertices;
    std::vector<std::list<int>> list; //list is better for deletions and insertions (I won't need those)
    void buildList(int size);

};
#endif //PWR_AIZO_PROJECT2_ADJACENCYLIST_H
