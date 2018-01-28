//
//  Method5.cpp
//  
//
//  Created by Arnav Patel on 1/27/18.
//

#include <stdio.h>
#include <iostream>
#include <map>
#include <vector>
#include <string>

std:: string replaceLetters (std:: string underscored_word, std:: vector<char> indices, char letter) {
    for (auto number:indices) {
            underscored_word[number] = letter;
        }
    return underscored_word;
}


