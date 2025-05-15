
#ifndef PWR_AIZO_PROJECT2_MSTALGORITHMBASE_H
#define PWR_AIZO_PROJECT2_MSTALGORITHMBASE_H

#include <utility>
#include <list>
#include <chrono>
#include "../../graph/Graph.h"

class MstAlgorithmBase{
public:
    bool assignGraph(Graph* graph);
    void run();
    std::string getResult();
protected:
    std::chrono::microseconds currentTime;
    std::list<std::pair<int, int>> mst; //mst = {vertex, weight}
    Graph* graph = nullptr;
    virtual void algorithmImp() = 0;
    void initializeMst();
    virtual bool checkCycle(int vertex) = 0;
};

#endif //PWR_AIZO_PROJECT2_MSTALGORITHMBASE_H
