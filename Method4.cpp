//
//  Method 4: Checks if Letter is in Word.cpp
//  
//
//  Created by Arnav Patel on 1/27/18.
//

#include <stdio.h>
#include <iostream>
#include <map>
#include <vector>
#include <string>
//#include <algorithm>
//#include <math.h>

std::vector<char> isLetterinWord (std::string word, char letter) {
    std:: vector <char> indices;
    for (int i=0; i<word.length();i++) {
        if(letter==word.at(i)) {
            indices.push_back(i);
        }
    }
    return indices;
}

