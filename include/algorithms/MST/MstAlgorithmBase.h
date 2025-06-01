
#ifndef PWR_AIZO_PROJECT2_MSTALGORITHMBASE_H
#define PWR_AIZO_PROJECT2_MSTALGORITHMBASE_H

#include <utility>
#include <list>
#include <chrono>
#include "../../graph/Graph.h"

class MstAlgorithmBase{
public:
    bool assignGraph(Graph* graph);
    void run(int startingVertex);
    std::string getResult();
protected:
    std::chrono::microseconds currentTime;
    std::list<std::tuple<int, int, int>> mst; //mst = {vertex1, vertex2, weight}
    Graph* graph = nullptr;
    virtual void algorithmImp(int startingVertex) = 0;
    void initializeMst();
};

#endif //PWR_AIZO_PROJECT2_MSTALGORITHMBASE_H
