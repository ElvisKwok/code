#include <iostream>
#include <list>
#include <string>
using namespace std;

int main()
{
    list<string> slst;
    string str;

    cout << "Enter some strings: " << endl;
    //while (cin >> str)
    while (getline(cin, str))
        slst.push_back(str);
    for (list<string>::iterator iter = slst.begin(); iter != slst.end(); ++iter)
        cout << *iter << endl;
    
    return 0;
}
