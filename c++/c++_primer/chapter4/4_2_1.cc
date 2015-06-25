#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s("hello world!");
    string *sp = &s;

    cout << *sp << endl;

    const size_t arr_sz = 5;
    int int_arr[arr_sz] = {0, 1, 2, 3, 4};
    for (int *pbegin = int_arr, *pend = int_arr + arr_sz;
            pbegin != pend; ++pbegin) 
        cout << *pbegin << ' ';

    return 0;
}
