#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    string word;
    vector<string> text;
    while (cin >> word)
        text.push_back(word);

    cout << "first element of the vector: " << text[0] << endl;
    cout << "vector size: " << text.size() << endl;

    return 0;
}
