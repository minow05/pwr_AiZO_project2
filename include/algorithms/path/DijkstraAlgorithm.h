
#ifndef PWR_AIZO_PROJECT2_DIJKSTRAALGORITHM_H
#define PWR_AIZO_PROJECT2_DIJKSTRAALGORITHM_H

#include "PathAlgorithmBase.h"

class DijkstraAlgorithm : public PathAlgorithmBase {
public:
    explicit DijkstraAlgorithm(Graph* graph);
private:
    void algorithmImp(int startingVertex, int endVertex) override;
};
#endif //PWR_AIZO_PROJECT2_DIJKSTRAALGORITHM_H
