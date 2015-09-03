#include <iostream>
#include "perceptron.h"
#include "testset.h"
#include "percepnetwork.h"


int main()
{

    using namespace std;
    using namespace vhland002;
    cout << "Program started..." << endl;
    cout << "Run program with activation function (a) or threshold function (t)?\n>";
    char input;
    cin >>  input;


    //we make a new network
    PercepNetwork network;
    //we create the set we will be using
    //taken from the assignment brief
    network.createSet();
    if (input == 'a'){
        network.runAlgorithm(0.1,false);
    }
    else if (input == 't'){
        network.runAlgorithm(0.1,true);
    }
    else{
        cout << "Invalid input please try again." << endl;
    }



    cout << "Program ended normally..." << endl;
    return 0;
}

