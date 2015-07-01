#include <iostream>
#include <string>

using namespace std;

int main()
{
    string currWord, preWord, maxWord;
    int currCnt = 0, maxCnt = 1;
    cout << "enter some words: ";
    while (cin >> currWord) {
        if (currWord == preWord)
            ++currCnt;
        else {
            if (currCnt > maxCnt) {
                maxCnt = currCnt;
                maxWord = preWord;
            }
            currCnt = 1;
        }
        preWord = currWord;
    }
    if (maxCnt != 1)
        cout << maxWord << ": " << maxCnt << endl;
    else
        cout << "no word repeated" << endl;
    
    return 0;
}
