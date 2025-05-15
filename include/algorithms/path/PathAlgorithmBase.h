
#ifndef PWR_AIZO_PROJECT2_PATHALGORITHMBASE_H
#define PWR_AIZO_PROJECT2_PATHALGORITHMBASE_H

#include "../../graph/Graph.h"
#include <chrono>

class PathAlgorithmBase {
public:
    bool assignGraph(Graph* graph);
    void run();
    std::string getResult();
protected:
    std::chrono::microseconds currentTime;
    Graph* graph = nullptr;
    std::vector<int> path;
};

#endif //PWR_AIZO_PROJECT2_PATHALGORITHMBASE_H
