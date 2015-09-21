#include <iostream>
#include <utility>
#include <vector>
#include <string>
using namespace std;

int main()
{
    pair<string, int> sipr;
    string str;
    int ival;
    vector< pair<string, int> > pvec;
    cout << "enter str, int" << endl;
    while (cin >> str >> ival) {
        sipr = make_pair(str, ival);
        pvec.push_back(sipr);
    }
     
    return 0;
}
