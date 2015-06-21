#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> ivec;
    for (int i = 0; i < 10; ++i)
        ivec.push_back(42);
    for (vector<int>::iterator iter = ivec.begin(); iter != ivec.end(); ++iter) {
        *iter *= 2;
        cout << *iter << '\t';
    }
    cout << endl;

    return 0;
}
