#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s1 = "hello";
    string s2 = s1 + ", ";
    string s3 = "hello" + ", ";
    string s4 = s1 + ", " + "world!";
    string s5 = "hello" + ", " + s1;
    return 0;
}
