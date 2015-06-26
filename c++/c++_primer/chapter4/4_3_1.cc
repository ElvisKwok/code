#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    const char ca[] = {'C', '+', '+'};
    cout << strlen(ca) << endl;

    const char *cp = ca;
    while (*cp) {
        cout << *cp << endl;
        ++cp;
    }
    
    return 0;
}
