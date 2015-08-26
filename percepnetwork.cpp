#include "percepnetwork.h"
#include "testset.h"
#include "set.h"
#include <iostream>
#include <ctime>



namespace vhland002{

void PercepNetwork::createSet(){
    Set set1(1,-1,1,-1,1);
    Set set2(1,1,1,1,1);
    Set set3(1,1,1,-1,-1);
    Set set4(1,-1,-1,1,-1);

    testSet.addSet(set1);
    testSet.addSet(set2);
    testSet.addSet(set3);
    testSet.addSet(set4);
}

}//namespace


