#include <iostream>

using namespace std;

int fac_help(int x)
{
    static int result = 1;
    result *= x;
    return result;
}

int main()
{
    int lmt;
    cin >> lmt;
    for (int i = 1; i <= lmt; ++i)
        cout << i << "! = " <<  fac_help(i) << endl;
    
    return 0;
}
