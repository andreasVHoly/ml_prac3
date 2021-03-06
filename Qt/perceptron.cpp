#include "perceptron.h"
#include <iostream>

namespace vhland002{

using namespace std;


//NOTE: cout statements are there for debugging, commented out for now

float Perceptron::recalculateWeight1(){
    weight1 += (learningRate * input1 * (target - output));
    return weight1;
}

float Perceptron::recalculateWeight2(){
    weight2 += (learningRate * input2 * (target - output));
    return weight2;
}

float Perceptron::recalculateWeight3(){
    weight3 += (learningRate * input3 * (target - output));
    return weight3;
}

float Perceptron::recalculateWeight4(){
    weight4 += (learningRate * input4 * (target - output));
    return weight4;
}

float Perceptron::getResult(){
    result = weight0 + weight1*input1 + weight2*input2 + weight3*input3 + weight4*input4;
    return result;

}


void Perceptron::setWeights(float weight0, float weight1, float weight2, float weight3, float weight4){
    this->weight0 = weight0;
    this->weight1 = weight1;
    this->weight2 = weight2;
    this->weight3 = weight3;
    this->weight4 = weight4;

}

void Perceptron::setInputs(float input1, float input2, float input3, float input4){
    this->input1 = input1;
    this->input2 = input2;
    this->input3 = input3;
    this->input4 = input4;
}


void Perceptron::setTarget(float target){
    this->target = target;
}

void Perceptron::setOutput(float value){
    this->output = value;
}


}
