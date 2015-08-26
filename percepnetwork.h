#ifndef PERCEPNETWORK_H
#define PERCEPNETWORK_H

#include "testset.h"
#include "perceptron.h"
#include "set.h"

namespace vhland002{
class PercepNetwork
{
public:


    void createSet();

    TestSet testSet = TestSet(4);


    bool debug = false;


};
}//vhland002
#endif // PERCEPNETWORK_H

