#include <iostream>

using namespace std;

template <typename T>
T abs(T val)
{
    return val > 0 ? val : -val;
}

int main()
{
    cout << abs(-2) << endl;
    cout << abs(3.97) << endl;
     
    return 0;
}
