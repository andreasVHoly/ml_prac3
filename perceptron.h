#ifndef PERCEPTRON_H
#define PERCEPTRON_H


#include <cstdlib>
namespace vhland002{


class Perceptron
{
public:
    //CONSTRUCTOR//
    Perceptron(float learningRate)
        :learningRate(learningRate){}

    //METHODS//

    float getResult();
    void setInputs(int input1, int input2, int input3, int input4);
    void setWeights(float weight0, float weight1, float weight2, float weight3, float weight4);

    float recalculateWeight1();
    float recalculateWeight2();
    float recalculateWeight3();
    float recalculateWeight4();

    void setTarget(int target);


    //VARS//
    float weight0, weight1, weight2, weight3, weight4, learningRate, result;
    int target, input1, input2, input3, input4, output;

};



}//vhland002
#endif // PERCEPTRON_H

