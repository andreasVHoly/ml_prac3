#include "percepnetwork.h"
#include "testset.h"
#include "set.h"
#include <iostream>
#include <ctime>



namespace vhland002{



void PercepNetwork::runAlgorithm(float learningRate, bool threshold){
    using namespace std;
    int results[4] = {0,0,0,0};

    Perceptron perceptron(learningRate);

    if (threshold){
        cout << "\nRunning algorithm with threshold function..." << endl << endl;
    }
    else{
        cout << "\nRunning algorithm with activation function..." << endl << endl;
    }

//    float weight0 = -1;
//    float weight1 = -1;
//    float weight2 = -1;
//    float weight3 = -1;
//    float weight4 = -1;
    float weight0 = 0;
    float weight1 = 0;
    float weight2 = 0;
    float weight3 = 0;
    float weight4 = 0;

    int iteration = 1;
    while(true){
        //loop through all the sets
        cout << endl << noOfSets << "***Iteration " << iteration << endl << endl;
        for (int i = 0; i < noOfSets; i++){
            //assign the previous output
            perceptron.setOutput(results[i]);
            //assign the correct target
            perceptron.setTarget(testSet.sets[i].output);
            //assign the inputs
            perceptron.setInputs(testSet.sets[i].input1,testSet.sets[i].input2,testSet.sets[i].input3,testSet.sets[i].input4);       
            //assign the weights

            //recaulculate the weights with the weighting rule
            weight1 = perceptron.recalculateWeight1();
            weight2 = perceptron.recalculateWeight2();
            weight3 = perceptron.recalculateWeight3();
            weight4 = perceptron.recalculateWeight4();

            cout << "w1: " << weight1 << endl;
            cout << "w2: " << weight2 << endl;
            cout << "w3: " << weight3 << endl;
            cout << "w4: " << weight4 << endl;
            perceptron.setWeights(weight0,weight1,weight2,weight3,weight4);
            //we check what result we got

            if (perceptron.getResult() > 0){
                results[i] = perceptron.getResult();
                //results[i] = 1;
            }
            //using the threshold function
            else if(threshold){
                //results[i] = 0;
                results[i] = perceptron.getResult();
            }
            //using the activation function
            else{
                //results[i] = -1;
                results[i] = perceptron.getResult();
            }


        }
        //check if the target is learnt
        int error = noOfSets;
        cout << "Algorithm Results:\nx1\tx2\tx3\tx4\n";
        for (int j = 0; j < noOfSets; j++){
            cout << results[j] << "\t";
            //if we are using the activation function or if we are using the threshold function (0 means a negative (-1) result)
            if (testSet.sets[j].output == results[j] || (threshold && testSet.sets[j].output == -1 && results[j] == 0)){
                //decrease counter if we have a test set right
                error--;
            }
        }
        cout << "\nTarget Results:\nx1\tx2\tx3\tx4\n";
        for (int k = 0; k < noOfSets; k++){
            cout << testSet.sets[k].output << "\t";
        }
        cout << endl;

        //break out of the while loop if we have all sets correct
        if (error == 0){
            cout << "\nAlgorithm took " << iteration << " iterations." << endl;
            break;
        }
        iteration++;

    }
    cout << endl;
}





float PercepNetwork::getRandomValue(){
    srand(time(0));
    double value = rand() % 1000;//random number
    float weight = value/1000.0f;
    return weight;
}





void PercepNetwork::createSet(){
    Set set1(1,-1,1,-1,1);
    Set set2(1,1,1,1,1);
    Set set3(1,1,1,-1,-1);
    Set set4(1,-1,-1,1,-1);

    noOfSets = 4;


    testSet.addSet(set1);
    testSet.addSet(set2);
    testSet.addSet(set3);
    testSet.addSet(set4);


}

}//namespace


