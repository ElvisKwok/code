#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s1 = "hello", s2(s1), s3(4, 'c'), s4("fuck");
    cout << s1 << s2 << s3 << s4 << endl;
    return 0;
}
