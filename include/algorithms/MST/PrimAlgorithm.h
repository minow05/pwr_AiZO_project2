#ifndef PWR_AIZO_PROJECT2_PRIMALGORITHM_H
#define PWR_AIZO_PROJECT2_PRIMALGORITHM_H

#include "MstAlgorithmBase.h"

class PrimAlgorithm : public MstAlgorithmBase {
public:
    explicit PrimAlgorithm(Graph *graph);
private:
    void algorithmImp(int startingVertex) override;
};
#endif //PWR_AIZO_PROJECT2_PRIMALGORITHM_H
