#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

bool isShorter(const string &s1, const string &s2)
{
    return s1.size() < s2.size();
}

bool GT4(const string &s)
{
    return s.size() >= 4;
}

string make_plural(size_t ctr, const string &word, const string &ending)
{
    return (ctr == 1) ? word : word+ending;
}

int main(int argc, char **argv)
{
    if (argc < 2) {
        cerr << "No input file!" << endl;
        return EXIT_FAILURE;
    }

    ifstream inFile;
    inFile.open(argv[1]);
    if (!inFile) {
        cerr << "Can not open input file!" << endl;
        return EXIT_FAILURE;
    }

    vector<string> words;
    string word;
    while (inFile >> word)
        words.push_back(word);
    
    sort(words.begin(), words.end());

    words.erase(unique(words.begin(), words.end()), words.end());

    stable_sort(words.begin(), words.end(), isShorter);

    vector<string>::size_type wc = count_if(words.begin(), words.end(), GT4);
    cout << wc << " " << make_plural(wc, "word", "s") << " 4 char or longer" << endl;

    cout << "unique words: " << endl;
    for (vector<string>::iterator iter = words.begin(); iter != words.end(); ++iter)
        cout << *iter << " ";
    cout << endl;

    return 0;
}
