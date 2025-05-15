
#ifndef PWR_AIZO_PROJECT2_KRUSKALALGORITHM_H
#define PWR_AIZO_PROJECT2_KRUSKALALGORITHM_H

#include "MstAlgorithmBase.h"

class KruskalAlgorithm : public MstAlgorithmBase{
private:
    void algorithmImp() override;
    bool checkCycle(int vertex) override;
};
#endif //PWR_AIZO_PROJECT2_KRUSKALALGORITHM_H
