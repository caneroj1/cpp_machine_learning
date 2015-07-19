//
//  main.cpp
//  MachineLearning
//
//  Created by Joseph Canero on 7/18/15.
//  Copyright (c) 2015 Joseph Canero. All rights reserved.
//

#include <iostream>
#include "linear_regression.h"

using namespace std;

int main(int argc, const char * argv[]) {
    LinearRegression lr(0.05);
    
    lr.setDataSetFromFile("./datasets/training_set_one.txt");
    vector<LinearDataSet> ds = lr.getDataSet();
    lr.learn();
    
    for (LinearDataSet set : ds)
        cout << "x: " << set.x() << ", y: " << set.y() << endl;
    
    LinearDataSet news(1.23, 0);
    LinearDataSet news2(2.1, 0);
    LinearDataSet news3(0.4, 0);
    LinearDataSet news4(1.86, 0);
    
    cout << "Predicting on x = " << news.x() << "... y = ";
    lr.predict(&news);
    cout << news.y() << endl;
    
    cout << "Predicting on x = " << news2.x() << "... y = ";
    lr.predict(&news2);
    cout << news2.y() << endl;
    
    cout << "Predicting on x = " << news3.x() << "... y = ";
    lr.predict(&news3);
    cout << news3.y() << endl;
    
    cout << "Predicting on x = " << news4.x() << "... y = ";
    lr.predict(&news4);
    cout << news4.y() << endl;
    
    return 0;
}
