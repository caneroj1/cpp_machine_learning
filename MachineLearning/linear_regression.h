//
//  linear_regression.h
//  MachineLearning
//
//  Created by Joseph Canero on 7/18/15.
//  Copyright (c) 2015 Joseph Canero. All rights reserved.
//

#ifndef __MachineLearning__linear_regression__
#define __MachineLearning__linear_regression__

#include "linear_dataset.cpp"
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

class LinearRegression {
private:
    double _thetaZero, _thetaOne, _learningRate;
    std::vector<LinearDataSet> _dataset;
    
    double hypothesis(double x);
    void gradientDescent();
    
public:
    LinearRegression(double learningRate, double tOne = 0, double tTwo = 0);
    void learn();
    void setDataSetFromFile(std::string);
    void predict(LinearDataSet);
    void setDataSet(std::vector<LinearDataSet>);
    std::vector<LinearDataSet> getDataSet();
};

#endif /* defined(__MachineLearning__linear_regression__) */
