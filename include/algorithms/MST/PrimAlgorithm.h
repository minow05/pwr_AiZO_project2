#ifndef PWR_AIZO_PROJECT2_PRIMALGORITHM_H
#define PWR_AIZO_PROJECT2_PRIMALGORITHM_H

#include "MstAlgorithmBase.h"

class PrimAlgorithm : public MstAlgorithmBase {
public:
    PrimAlgorithm(Graph *graph);
private:
    void algorithmImp() override;
    bool checkCycle(int vertex) override;
};
#endif //PWR_AIZO_PROJECT2_PRIMALGORITHM_H
