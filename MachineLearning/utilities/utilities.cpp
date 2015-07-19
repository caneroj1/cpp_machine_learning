//
//  utilities.cpp
//  MachineLearning
//
//  Created by Joseph Canero on 7/18/15.
//  Copyright (c) 2015 Joseph Canero. All rights reserved.
//

#include <sstream>
#include <iostream>
#include <vector>

using namespace std;

vector<string> splitByToken(string input, char token) {
    stringstream stream(input);
    vector<string> tokens;
    string splitToken;
    
    while (getline(stream, splitToken, token))
        tokens.push_back(splitToken);
    
    return tokens;
}

vector<string> splitByPhrase(string input, string phrase) {
    string splitToken, inputCopy(input);
    vector<string> tokens;
    
    size_t position = inputCopy.find_first_of(phrase);
    while (position != string::npos) {
        tokens.push_back(inputCopy.substr(0, position));
        inputCopy.replace(0, position + phrase.length(), "");
    }
    tokens.push_back(inputCopy);
    
    return tokens;
}