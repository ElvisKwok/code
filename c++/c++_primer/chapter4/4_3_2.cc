#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main()
{
    string s1, s2;
    cout << "enter 2 string: ";
    cin >> s1 >> s2;

    if (s1 > s2)
        cout << s1 << " bigger" << endl;
    else if(s1 < s2)
        cout << s2 << " bigger" << endl;
    else 
        cout << "equal" << endl;

    //char *cs1 = "string1", *cs2 = "string2";
    const int str_size = 80;
    char *cs1, *cs2;
   
    // 为两个字符串分配内存
    cs1 = new char[str_size];
    cs2 = new char[str_size];
    if (cs1 == NULL || cs2 == NULL) {
        cout << "No enough memory!" << endl;
        return -1;
    }

    cout << "enter 2 string: ";
    cin >> cs1 >> cs2;

    int result;
    result = strcmp(cs1, cs2);
    if (result > 0)
        cout << cs1 << " bigger" << endl;
    else if(result < 0)
        cout << cs2 << " bigger" << endl;
    else 
        cout << "equal" << endl;
    
    // 释放字符串所占用的内存
    delete [] cs1;
    delete [] cs2;
    
    return 0;
}
