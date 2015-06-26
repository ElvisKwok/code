#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> ivec;
    int ival;
    cout << "Enter some num:(Ctrl+D to end) ";
    while (cin >> ival)
        ivec.push_back(ival);
    
    int *p = new int[ivec.size()];

    int *tp = p;
    for (vector<int>::iterator iter = ivec.begin(); iter != ivec.end(); ++iter, ++tp)
        *tp = *iter;

    delete [] p;

    return 0;
}
