#include "assessment.h"

using std::string;
using std::vector;

void updateMask(string& mask, const char ch, const string& word);
bool isCorrectChar(char ch, const string& mask);
bool isWholeWord(const string& mask);


void updateMask(string& mask, const char ch, const string& word)
{
    // TODO Step 2: given a character ch, update the mask to show the character ch that is in the word
    //  eg . if ch = 'a' and word = "apple", then mask = "a____"
}

int countMistakes(const string& word, HangmanGuesser& hmGuesser)
{
    // TODO Step 3: Implement this function, which returns the number of mistakes
    //  tried to solve the word by the given HangmanGuesser.
    return -1;
}

void getMistakeByWordList(vector<MistakeByWord>& mistakeList, vector<string>& unsolvableList, const vector<string>& testWords, HangmanGuesser& hmGuesser)
{
    // TODO Step 4: given a list of words, return a list of mistakes by word,
    // where each mistake is a struct containing the word and the number of mistakes that guesser has made on that word
    // you can use the updateMask function to update the mask and isCorrectChar to check if a character is correct
    // you can use countMistakes to count the number of mistakes

}

bool isCorrectChar(char ch, const string& mask)
{
    return isCharInWord(ch, mask);
}

bool isWholeWord(const string& mask)
{
    return !isCharInWord(MASK_CHAR, mask);
}