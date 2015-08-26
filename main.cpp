#include <iostream>
#include "perceptron.h"
#include "testset.h"
#include "percepnetwork.h"


int main()
{

    using namespace std;
    using namespace vhland002;
    cout << "Program started..." << endl;


    //we make a new network
    PercepNetwork network;
    //we create the set we will be using
    //taken from the assignment brief
    network.createSet();


    cout << "Program ended normally..." << endl;
    return 0;
}

