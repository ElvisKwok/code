#include <iostream>
#include <string>
using namespace std;

int violentSearch(const string &s, const string &sub)
{
    string::size_type i = 0, j = 0;
    while ((i < s.size()) && (j < sub.size())) {
        if (s[i] == sub[j]) {
            ++i;
            ++j;
        }
        else {
            i = i - j + 1;
            j = 0;
        }
        //cout << "(" << i << "," << j << ")" << endl;
    }
    if (j == sub.size())
        return i - j;
    else
        return -1;
}

int main()
{
    string s("hello"), sub("llc");
    cout << violentSearch(s, sub) << endl;
    cout << violentSearch("hello", "llo") << endl;
    return 0;
}
