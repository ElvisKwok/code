#include <iostream>
using namespace std;

void PrintOut(int n)
{
    if (n >= 10)
        PrintOut(n/10);
    cout << n%10;
}

int main()
{
    PrintOut(76234);
    return 0;
}
