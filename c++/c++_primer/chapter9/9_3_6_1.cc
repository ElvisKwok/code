#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int a[] = {6, 1, 2, 3, 4, 5};
    vector<int> ivec(a, a+6);

    if (ivec.empty())
        cout << "No element!" << endl;
    else {
        cout << "Subscript: " << ivec[0] << endl;
        cout << "front(): " << ivec.front() << endl;
        cout << "begin(): " << *ivec.begin() << endl;
    }
    
    return 0;
}
