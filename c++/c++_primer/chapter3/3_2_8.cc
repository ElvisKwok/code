#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main()
{
    string s, result_str;
    bool has_punct = false;
    char ch;
    cout << "enter a string: ";
    getline(cin, s);
    for (string::size_type i = 0; i < s.size(); i++) {
        ch = s[i];
        if (ispunct(ch))
            has_punct = true;
        else
            result_str += ch;
    }

    if (has_punct) 
        cout << result_str << endl;
    else {
        cout << "no punctation found!" << endl;
        return -1;
    }

    return 0;
}
