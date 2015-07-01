#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> ivec1, ivec2;
    int ival;
    cout << "enter nums of ivec1:(32767 to end) ";
    cin >> ival;
    while (ival != 32767) {
        ivec1.push_back(ival);
        cin >> ival;
    }
    cout << "enter nums of ivec2:(32767 to end) ";
    cin >> ival;
    while (ival != 32767) {
        ivec2.push_back(ival);
        cin >> ival;
    }

    vector<int>::size_type size1, size2;
    size1 = ivec1.size();
    size2 = ivec2.size();
    bool result = true;
    for (vector<int>::size_type ix = 0; ix != (size1 < size2 ? size1: size2); ++ix) {
        if (ivec1[ix] != ivec2[ix]) {
            result = false;
            break;
        }
    }

    if (result) {
        if (size1 < size2) 
            cout << "ivec1 is prefix of ivec2" << endl;
        else if (size1 == size2)
            cout << "2 vectors are equal" << endl;
        else
            cout << "ivec2 is prefix of ivec1" << endl;
    }
    else 
        cout << "No prefix find" << endl;
    
    return 0;
}
