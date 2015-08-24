#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int ival;
    vector<int> ivec;
    while (cin >> ival)
        ivec.push_back(ival);
    cin.clear();
    for (vector<int>::iterator iter = ivec.begin(); iter != ivec.end(); ++iter)
        cout << *iter << " ";
    cout << endl;

    cout << "now: " << endl;
    while (cin >> ival)
        ivec.push_back(ival);
    for (vector<int>::iterator iter = ivec.begin(); iter != ivec.end(); ++iter)
        cout << *iter << " ";
    cout << endl;

    return 0;
}
