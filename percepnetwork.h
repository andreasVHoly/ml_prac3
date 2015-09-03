#ifndef PERCEPNETWORK_H
#define PERCEPNETWORK_H

#include "testset.h"
#include "perceptron.h"
#include "set.h"

namespace vhland002{
class PercepNetwork
{
public:

    //methods
    void createSet();
    void runAlgorithm(float learningRate, bool thresh);
    float getRandomValue();



    //variables
    bool debug = false;
    TestSet testSet = TestSet(4);
    int noOfSets;




};
}//vhland002
#endif // PERCEPNETWORK_H

