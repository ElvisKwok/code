#include <iostream>
#include <string>
using namespace std;

int main()
{
    string st("This is a string\n");
    cout << "The size of " << st << "is " << st.size() << endl;
    if (!st.empty()) 
        cout << "not empty" << endl;
    return 0;
}
