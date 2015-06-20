#include <iostream>
#include <string>
#include <cctype>
#include <vector>
using namespace std;

int main()
{
    vector<string> svec;
    string word;
    while (cin >> word)
        svec.push_back(word);
    if (svec.empty()) {
        cout << "Nothing inputed!";
        return -1;
    }

    vector<string>::size_type cnt, ix;
    for (ix = 0; ix != svec.size(); ix++) {
        for(string::size_type ix_word = 0; ix_word < svec[ix].size(); ix_word++)
            svec[ix][ix_word] = toupper(svec[ix][ix_word]);
        cout << svec[ix] << '\t';
        cnt++;
        if (cnt % 8 == 0)
            cout << endl;
    }

    return 0;
}
