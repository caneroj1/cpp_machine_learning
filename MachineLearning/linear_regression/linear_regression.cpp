//
//  linear_regression.cpp
//  MachineLearning
//
//  Created by Joseph Canero on 7/18/15.
//  Copyright (c) 2015 Joseph Canero. All rights reserved.
//

#include "linear_regression.h"
#include "../utilities/utilities.cpp"

using namespace std;

LinearRegression::LinearRegression(double learningRate, double tZero, double tOne, double delta) {
    _learningRate = learningRate;
    _thetaZero = tZero;
    _thetaOne = tOne;
    _delta = delta;
}

vector<LinearDataSet> LinearRegression::getDataSet() {
    return _dataset;
}

void LinearRegression::setDataSet(vector<LinearDataSet> dataset) {
    _thetaOne = _thetaZero = 0;
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
    double prevZero, prevOne, sumZero, sumOne;

    cout << "Starting Gradient Descent" << endl;
    do {
        sumZero = 0, sumOne = 0;
        
        for (LinearDataSet data : _dataset) {
            sumZero += (hypothesis(data.x()) - data.y());
            sumOne +=  (hypothesis(data.x()) - data.y()) * data.x();
        }
        sumZero /= _dataset.size();
        sumOne /= _dataset.size();
        
        prevZero = _thetaZero;
        prevOne = _thetaOne;
        _thetaZero -= _learningRate * sumZero;
        _thetaOne -= _learningRate * sumOne;
    } while (abs(prevZero - _thetaZero) > _delta && abs(prevOne - _thetaOne) > _delta);
    cout << "Finished Gradient Descent" << endl << "Theta Zero = " << _thetaZero << ", Theta One = " << _thetaOne << endl;
}

void LinearRegression::predict(LinearDataSet *set) {
    set->y(hypothesis(set->x()));
}

void LinearRegression::learn() {
    gradientDescent();
}







