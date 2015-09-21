#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s("Hiya");

    for (string::iterator iter = s.begin(); iter != s.end(); ++iter) 
        if (*iter >= 'a' && *iter <= 'z')
            *iter -= 32;

    for (string::iterator iter = s.begin(); iter != s.end(); ++iter)
        cout << *iter << endl;
     
    return 0;
}
