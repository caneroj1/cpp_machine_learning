//
//  linear_dataset.cpp
//  MachineLearning
//
//  Created by Joseph Canero on 7/18/15.
//  Copyright (c) 2015 Joseph Canero. All rights reserved.
//

#include <array>

class LinearDataSet {
private:
    double _x, _y;
    
public:
    LinearDataSet(double x, double y) { _x = x; _y = y; }
    
    double x() { return _x; }
    double y() { return _y; }
    void x(double x) { _x = x; }
    void y(double y) { _y = y; }
    
    std::array<double, 2> pair() {
        std::array<double, 2> pair = { _x, _y };
        return pair;
    }
};