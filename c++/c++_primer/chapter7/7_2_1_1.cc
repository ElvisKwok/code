#include <iostream>

using namespace std;

void swap_pointer(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void swap_ref(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int main()
{
    int a = 1, b = 2;
    cout << "before: " << a << '\t' << b << endl;
    swap_pointer(&a, &b);
    cout << "swaped by pointer: " << a << "\t" << b << endl;
    swap_ref(a, b);
    cout << "swaped again, by reference: " << a << "\t" << b << endl;

    return 0;
}
