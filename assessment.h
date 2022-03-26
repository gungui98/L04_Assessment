#ifndef GUARD_assessment
#define GUARD_assessment

#include <string>
#include <vector>

#include "util.h"
#include "hangman_guesser.h"

const char MASK_CHAR = '-';

struct MistakeByWord {
    int count;
    std::string word;
    bool operator<(const MistakeByWord& m) const
    {
        if (count != m.count) return count < m.count;
        else return word < m.word;
    }
};

void getMistakeByWordList(std::vector<MistakeByWord>& mistakeList, std::vector<std::string>& unsolvableList, 
                        const std::vector<std::string> & testWords, HangmanGuesser& hmGuesser);
int countMistakes(const std::string& word, HangmanGuesser& hmGuesser);
void updateMask(std::string& mask, const char ch, const std::string& word);
#endif