
#ifndef PWR_AIZO_PROJECT2_PATHALGORITHMBASE_H
#define PWR_AIZO_PROJECT2_PATHALGORITHMBASE_H

#include "../../graph/Graph.h"
#include <chrono>

class PathAlgorithmBase {
public:
    bool assignGraph(Graph* graph);
    void run(int startingVertex, int endVertex);
    std::string getResult();
protected:
    std::chrono::microseconds currentTime;
    Graph* graph = nullptr;
    std::vector<std::tuple<int, int, int>> path;
    int pathWeight = 0;
    virtual void algorithmImp(int startingVertex, int endVertex) = 0;
    void initializeMst();
};

#endif //PWR_AIZO_PROJECT2_PATHALGORITHMBASE_H
