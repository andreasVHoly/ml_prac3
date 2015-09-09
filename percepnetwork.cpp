#include "percepnetwork.h"
#include "testset.h"
#include "set.h"
#include <iostream>
#include <ctime>
#include <math.h>



namespace vhland002{



void PercepNetwork::runAlgorithm(float learningRate, bool threshold){
    using namespace std;
    float results[4] = {0.0f,0.0f,0.0f,0.0f};
    string fileName;
    Perceptron perceptron(learningRate);
    ofstream outFile;

    if (threshold){
        cout << "\nRunning algorithm with threshold function..." << endl << endl;
        fileName = "threshold.txt";
    }
    else{
        cout << "\nRunning algorithm with activation function..." << endl << endl;
        fileName = "linear.txt";
    }
    outFile.open(fileName.c_str());

    //weight init
    float weight0 = 0;
    float weight1 = 0;
    float weight2 = 0;
    float weight3 = 0;
    float weight4 = 0;

    int iteration = 1;
    while(true){
        //loop through all the sets
        cout << endl << "***Iteration " << iteration << endl << endl;
        for (int i = 0; i < noOfSets; i++){
            //assign the previous output
            perceptron.setOutput(results[i]);
            //assign the correct target
            perceptron.setTarget(testSet.sets[i].output);
            //assign the inputs
            perceptron.setInputs(testSet.sets[i].input1,testSet.sets[i].input2,testSet.sets[i].input3,testSet.sets[i].input4);       
            //assign the weights
            perceptron.setWeights(weight0,weight1,weight2,weight3,weight4);//315/6
            //we check what result we got

            //if we are using the threshold function
            if(threshold){
                if (perceptron.getResult() > 0){
                    results[i] = 1;
                }
                //using the threshold function
                else {
                    results[i] = -1;
                }
            }
            else{
                //we round the value off at 6 decimal places
                results[i] = roundf(perceptron.getResult()*1000000)/1000000;
            }
            //if the result is not right we recalculate the weights
            if (results[i] != testSet.sets[i].output){
                weight1 = perceptron.recalculateWeight1();
                weight2 = perceptron.recalculateWeight2();
                weight3 = perceptron.recalculateWeight3();
                weight4 = perceptron.recalculateWeight4();
            }


        }
        //check if the target is learnt
        int error = noOfSets;
        cout << "Algorithm Results:\nx1\tx2\tx3\tx4\n";

        for (int j = 0; j < noOfSets; j++){
            cout << results[j] << "\t";
            //if we are using the activation function or if we are using the threshold function (0 means a negative (-1) result)
            if (testSet.sets[j].output == results[j]){
                //decrease counter if we have a test set right
                //cout << "decreased" << endl;
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


