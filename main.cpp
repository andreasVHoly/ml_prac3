#include <iostream>
#include "perceptron.h"
#include "testset.h"
#include "percepnetwork.h"


int main()
{

    using namespace std;
    using namespace vhland002;
    cout << "Program started..." << endl;

    PercepNetwork network;
    network.createSet();


    cout << "Program ended normally..." << endl;
    return 0;
}

