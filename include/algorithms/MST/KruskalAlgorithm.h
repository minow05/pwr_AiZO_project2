
#ifndef PWR_AIZO_PROJECT2_KRUSKALALGORITHM_H
#define PWR_AIZO_PROJECT2_KRUSKALALGORITHM_H

#include "MstAlgorithmBase.h"

class KruskalAlgorithm : public MstAlgorithmBase{
public:
    explicit KruskalAlgorithm(Graph *graph);
private:
    std::vector<int> color;
    void algorithmImp(int startingVertex) override;
    bool checkCycle(int sourceVertex, int targetVertex);
    int find(int v);
    void unionSets(int a, int b);
};
#endif //PWR_AIZO_PROJECT2_KRUSKALALGORITHM_H
