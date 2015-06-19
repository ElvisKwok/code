#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s1, s2;
    cin >> s1 >> s2;

    if (s1 == s2)
        cout << "equal" << endl;
    else if (s1 < s2)
        cout << s2 << " bigger" << endl;
    else
        cout << s1 << " bigger" << endl;
    

    if (s1.size() == s2.size())
        cout << "size equal" << endl;
    else if (s1.size() < s2.size())
        cout << s2 << " size bigger" << endl;
    else
        cout << s1 << " size bigger" << endl;

    return 0;
}
