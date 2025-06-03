
#ifndef PWR_AIZO_PROJECT2_FORDBELLMANALGORITHM_H
#define PWR_AIZO_PROJECT2_FORDBELLMANALGORITHM_H

#include "PathAlgorithmBase.h"

class FordBellmanAlgorithm : public PathAlgorithmBase {
public:
    explicit FordBellmanAlgorithm(Graph* graph);
private:
    void algorithmImp(int startingVertex, int endVertex) override;
    void negativeCycle();
};
#endif //PWR_AIZO_PROJECT2_FORDBELLMANALGORITHM_H
