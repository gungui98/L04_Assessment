#include "assessment.h"

using std::string;
using std::vector;

void updateMask(string& mask, const char ch, const string& word);
bool isCorrectChar(char ch, const string& mask);
bool isWholeWord(const string& mask);

void getMistakeByWordList(vector<MistakeByWord>& mistakeList, vector<string>& unsolvableList, const vector<string>& testWords, HangmanGuesser& hmGuesser)
{
    mistakeList.clear();
    unsolvableList.clear();
    for (int i = 0; i < testWords.size(); ++i) {
        int cnt = countMistakes(testWords[i], hmGuesser);
        if (cnt != -1) {
            // http://stackoverflow.com/questions/11516657/c-structure-initialization
            //C1: mistakeList.push_back((MistakeByWord) {cnt, testWords[i]});
            //C2: MistakeByWord m; m.count = cnt; m.word = testWords[i]; mistakeList.push_back(m);
            //C3:
            MistakeByWord m = {cnt, testWords[i]}; 
            mistakeList.push_back(m);
        } else {
            unsolvableList.push_back(testWords[i]);
        }
    }
}

int countMistakes(const string& word, HangmanGuesser& hmGuesser)
{
    int MAX_GUESS = 'z' - 'a' + 1;

    int cnt = 0;
    hmGuesser.newGame(word.size(), MASK_CHAR);
    string mask = string(word.size(), MASK_CHAR);

    for (int i = 0; i < MAX_GUESS; ++i) {
        char nextChar = hmGuesser.getChar(mask);
        if (nextChar == 0) {
            return -1;
        }

        updateMask(mask, nextChar, word);

        if (isCorrectChar(nextChar, mask)) {
            if (isWholeWord(mask)) {
                return cnt;
            }
        } else {
            cnt += 1;
        }
    }
    return -1;

}

void updateMask(string& mask, const char ch, const string& word)
{
    int len = word.length();
    for (int i = 0; i < len; ++i) {
        if (word[i] == ch) {
            mask[i] = ch;
        }
    }
}

bool isCorrectChar(char ch, const string& mask)
{
    return isCharInWord(ch, mask);
}

bool isWholeWord(const string& mask)
{
    return !isCharInWord(MASK_CHAR, mask);
}
