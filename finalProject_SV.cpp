#include <iostream> 
#include <vector> 
#include <math.h> 

class HangMan; 
class WordBank; 

class HangMan 
{
    std::vector<std::string> body = {"head", "torso", "right arm", "left arm", "right leg", "left leg"}; 
    public: 
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
    public: 
	std::string pickWord(); 
}; 

//HangMan methods 
bool HangMan::removeBodyPart() 
{
    if (!(this -> body).empty()) 
    {
	this -> body.pop_back(); 
	return true; 
    }
    else 
    {
	std::cout << "Invalid. You lost!\n"; 
	return false; 
    }
} 

//WordBank methods 
std::string WordBank::pickWord() 
{
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
	std::cout << "test statement one\n"; 
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
