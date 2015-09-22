#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> ivec;
    int ival, searchValue=1;
    cout << "enter some int: " << endl;
    while (cin >> ival)
        ivec.push_back(ival);
    cin.clear();

    //cout << "enter an int to search: " << endl;
    //cin >> searchValue;

    cout << count(ivec.begin(), ivec.end(), searchValue)
         << " element(s) in the vector have value "
         << searchValue << endl;
     
    return 0;
}
