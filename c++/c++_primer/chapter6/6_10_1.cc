#include <iostream>
#include <string>

using namespace std;

int main()
{
    string currWord, preWord;
    cout << "enter some words:" << endl;
    while (cin >> currWord) {
        if (currWord == preWord)
            break;
        else
            preWord = currWord;
    }
    if ((currWord == preWord) && !currWord.empty()) 
        cout << "repeated word: " << currWord << endl;
    else
        cout << "no word repeated!" << endl;

    
    return 0;
}
