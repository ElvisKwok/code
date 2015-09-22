#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main()
{
    vector<int> ivec;
    int ival;
    cout << "enter some int: " << endl;
    while (cin >> ival)
        ivec.push_back(ival);
    cin.clear();

    cout << accumulate(ivec.begin(), ivec.end(), 10) << endl;
     
    return 0;
}
