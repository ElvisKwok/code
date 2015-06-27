#include <iostream>

using namespace std;

int main()
{
    int x[10];
    int *p = x;

    cout << sizeof(x)/sizeof(*x) << endl;
    cout << sizeof(p)/sizeof(*p) << endl;
    
    cout << "bool\t\t" << sizeof(bool) << endl;
    cout << "char\t\t" << sizeof(char) << endl;
    cout << "signed char\t" << sizeof(signed char) << endl;
    cout << "unsigned char\t" << sizeof(unsigned char) << endl;
    cout << "wchar_t\t\t" << sizeof(wchar_t) << endl;
    cout << "short\t\t" << sizeof(short) << endl;
    cout << "signed short\t" << sizeof(signed short) << endl;
    cout << "unsigned short\t" << sizeof(unsigned short) << endl;
    cout << "int\t\t"<< sizeof(int) << endl;
    cout << "signed int\t" << sizeof(signed int) << endl;
    cout << "unsigned int\t" << sizeof(unsigned int) << endl;
    cout << "long\t\t" << sizeof(long) << endl;
    cout << "signed long\t" << sizeof(signed long) << endl;
    cout << "unsigned long\t" << sizeof(unsigned long) << endl;
    cout << "float\t\t" << sizeof(float) << endl;
    cout << "double\t\t" << sizeof(double) << endl;
    cout << "long double\t" << sizeof(long double) << endl;


    return 0;
}
