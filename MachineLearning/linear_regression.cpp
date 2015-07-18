//
//  linear_regression.cpp
//  MachineLearning
//
//  Created by Joseph Canero on 7/18/15.
//  Copyright (c) 2015 Joseph Canero. All rights reserved.
//

#include "linear_regression.h"
#include "utilities.cpp"

using namespace std;

LinearRegression::LinearRegression(double learningRate, double tZero, double tOne) {
    _learningRate = learningRate;
    _thetaZero = tZero;
    _thetaOne = tOne;
}

vector<LinearDataSet> LinearRegression::getDataSet() {
    return _dataset;
}

void LinearRegression::setDataSet(vector<LinearDataSet> dataset) {
    _dataset = dataset;
}

void LinearRegression::setDataSetFromFile(string filename) {
    fstream dataFile(filename);
    string line;
    
    _dataset.clear();
    while (getline(dataFile, line)) {
        vector<string> tokens = splitByToken(line, ',');
        _dataset.push_back(LinearDataSet(stod(tokens[0]), stod(tokens[1])));
    }
}

double LinearRegression::hypothesis(double x) {
    return (_thetaZero + _thetaOne * x);
}

void LinearRegression::gradientDescent() {
    
}