#include "percepnetwork.h"
#include "testset.h"
#include "set.h"
#include <iostream>
#include <ctime>



namespace vhland002{



void PercepNetwork::runAlgorithm(float learningRate){
    using namespace std;
    int results[4] = {0,0,0,0};

    Perceptron perceptron(learningRate);

    //assign random values to teh weights
    //float weight0 = getRandomValue();
//    float weight1 = getRandomValue();
//    float weight2 = getRandomValue();
//    float weight3 = getRandomValue();
//    float weight4 = getRandomValue();

    float weight0 = -1;
    float weight1 = 0;
    float weight2 = 0;
    float weight3 = 0;
    float weight4 = 0;

    int iteration = 1;
    while(true /*&& iteration < 10*/){
        //loop through all the sets
        cout << endl << "*Iteration " << iteration << endl << endl;
        for (int i = 0; i < noOfSets; i++){
            //assign the previous output
            perceptron.setOutput(results[i]);
            cout << "result set to " << results[i] << endl;
            //assign the correct target
            perceptron.setTarget(testSet.sets[i].output);
            cout << "target set to " << testSet.sets[i].output << endl;
            //assign the inputs
            perceptron.setInputs(testSet.sets[i].input1,testSet.sets[i].input2,testSet.sets[i].input3,testSet.sets[i].input4);
            cout << "inputs set to " << testSet.sets[i].input1 << " , " << testSet.sets[i].input2 << " , " << testSet.sets[i].input3 << " , " << testSet.sets[i].input4 << endl;
            //assign the weights
            perceptron.setWeights(weight0,weight1,weight2,weight3,weight4);
            cout << "weights set to " << weight0 << " , " << weight1 << " , " << weight2 << " , " << weight3 << " , " << weight4 << endl;
            //recaulculate the weights with the weighting rule
            weight1 = perceptron.recalculateWeight1();
            weight2 = perceptron.recalculateWeight2();
            weight3 = perceptron.recalculateWeight3();
            weight4 = perceptron.recalculateWeight4();

            //we check what result we got

            if (perceptron.getResult() > 0){
                results[i] = 1;
            }
            else{
                results[i] = -1;
            }


        }
        //check if the target is learnt
        int error = noOfSets;
        for (int j = 0; j < noOfSets; j++){
            if (testSet.sets[j].output == results[j]){
                //decrease counter if we have a test set right
                error--;
            }
        }
        iteration++;
        //break out of the while loop if we have all sets correct
        if (error == 0){
            cout << "Algorithm took " << iteration << " iterations." << endl;
            break;
        }

    }
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


