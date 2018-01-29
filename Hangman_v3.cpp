
//
//  Final Project-v2.cpp
//
//
//  Created and editted by Arnav Patel and Summer Vo 1/28/18.
//
#include <stdio.h>
#include <iostream>
#include <vector>
#include <math.h>
#include <stdlib.h>
#include <time.h>

class HangMan;
class WordBank;

class HangMan
{
public:
    std::vector<std::string> body = {"head", "torso", "right arm", "left arm", "right leg",
        "left leg"};
    bool removeBodyPart();
};

class WordBank
{
    std::vector<std::string> word = {"aardvark", "apricot", "balloon", "beluga", "certified", "crepe",
        "detoxify", "dribble", "elevate", "escalator", "feather", "forever", "godzilla", "gorilla",
        "hollow", "hound", "intricate", "invisible", "jaguar", "jackalope", "ketchup", "krypton",
        "lobster", "lucky", "microanalyst", "mockingbird", "nebulous", "nutcracker", "octopus",
        "ozone", "pendulum", "practical", "quadrilateral", "query", "ratatouille", "reabsorb",
        "simple", "syllabus", "taciturn", "traumatic", "umbrella", "unique", "vacation", "vigorous",
        "winner", "wonderful", "xerox", "xylography", "zealotry", "zucchini"};
    std::vector<char> lettersGuessed;
public:
    std::string pickWord();
};

//HangMan methods
bool HangMan::removeBodyPart()
{
    if (!(this -> body).empty())
    {
        this -> body.pop_back();
    }
    if (this -> body.empty())
    {
        std::cout << "You lost!\n";
        return false;
    }
    return true;
}

//WordBank methods
std::string WordBank::pickWord()
{
    srand(time(NULL));
    int r = rand() % 52;
    return this -> word.at(r);
}

//Method 2: Checks if the input is a alphabetic letter
//Parameters: a character that was guessed
//Returns true if the character is an alphabetic letter
bool isLetter(char c)
{
    if (isalpha(c))
    {
        return true;
    }
    else
    {
        std::cout << "Please input a letter.\n";
        return false;
    }
    
}

//Method 3: Checks if the letter has been guessed
//Parameters: a vector containing letters guessed and the character representing the current guess
//Returns true if the letter had already been guessed
bool wasGuessed(std::vector<char> v, char c)
{
    bool b = false;
    for (char a : v)
    {
        if (a == c)
        {
            b = true;
        }
    }
    if (b)
    {
        std::cout << "This letter was already guessed. Please try again\n";
    }
    return b;
}

//Method4: Checks if Letter is in Word
std::vector<int> isLetterinWord (std::string word, char letter) {
    std:: vector <int> indices;
    for (int i=0; i<word.length();i++) {
        if(letter==word.at(i)) {
            indices.push_back(i);
        }
    }
    return indices;
}
//Method5: Replace underscores with letter
std:: string replaceLetters (std:: string underscored_word, std:: vector<int> indices, char letter) {
    for (auto number:indices) {
        underscored_word[number] = letter;
    }
    return underscored_word;
}

int main()
{
    HangMan hm;
    WordBank wb;
    std::string word = wb.pickWord();
    std::string dword;
    for (int i = 0; i < word.length(); i++)
    {
        dword += "-";
    }
    //Variables
    char guess; //The character the user guesses
    std::vector<char> guessedL;
    
    //Instructions printed out to the user:
    std::cout << "Welcome to Hangman!\nHere are the rules of the game: \n";
    std::cout << "***The aim of the game is to guess a random word correctly\n";
    std::cout << "***However, you have a limited number of incorrect guesses allowed\n";
    std::cout << "***The program will print out the word replaced with dashes; each dash represents a character\n";
    std::cout << "***Guess one letter at a time when prompted and the program\n";
    std::cout << "***will let you know and will also print out what letters have already been guessed.\n";
    std::cout << "***Please enjoy!!!\n";
    
    while(hm.body.size() != 0 && !(word==dword))
    {
        std::cout<<"Here is your current guessed word: "<<dword<<std:: endl;
        std::cout<<"This are the letters you have guessed"<<std:: endl;
        for (int i = 0; i<guessedL.size(); i++) {
            std::cout<<guessedL.at(i)<< " ";
        }
        std::cout<< std:: endl;
        std::cout<< "Body parts left:"<<std:: endl;
        for (int i = 0; i<hm.body.size(); i++) {
            std::cout<<hm.body.at(i)<< " ";
        }
        std::cout<<std::endl;
        std::cout << "Enter your guess: \n";
        std::cin >> guess;
        if (isLetter(guess) && !wasGuessed(guessedL, guess))
        {
            std:: vector <int> indices;
            indices = isLetterinWord(word,guess);
            if (indices.size() == 0) {
                bool a = hm.removeBodyPart();
                guessedL.push_back(guess);
            }
            else {
                dword = replaceLetters(dword, indices, guess);
                guessedL.push_back(guess);
            }
        }
    }
    if (word==dword) {
        std:: cout<<"Yay! You won!"<<std:: endl;
    }
    else {
        std::cout<<"This is the word: "<<word<<std:: endl;
    }
}