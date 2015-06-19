#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s1 = "hello";
    for(string::size_type ix = 0; ix != s1.size(); ++ix)
        cout << s1[ix] << endl;
    return 0;
}
