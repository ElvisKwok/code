#include <iostream>
#include <string>
#include <vector>
#include <cstring>
using namespace std;

int main() 
{
    string s;
    vector<string> svec;
    cout << "enter some string:(ctrl+D to end) ";
    while (cin >> s)
        svec.push_back(s);

    char **parr = new char*[svec.size()];
    size_t ix = 0;
    for (vector<string>::iterator iter = svec.begin(); iter != svec.end(); iter++, ix++) {
        char *p = new char[(*iter).size()+1];
        strcpy(p, (*iter).c_str());
        parr[ix] = p;
    }

    cout << "Content of vector: " << endl;
    for (vector<string>::iterator iter2 = svec.begin(); iter2 != svec.end(); iter2++, ix++)
        cout << *iter2 << endl;

    cout << "Content of char arrays: " << endl;
    for (ix = 0; ix != svec.size(); ix++)
        cout << parr[ix] << endl;

    for (ix = 0; ix != svec.size(); ix++)
        delete [] parr[ix]; 

    delete [] parr;

    return 0;
}
