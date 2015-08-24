#include <iostream>
#include <vector>

using namespace std;

bool find_me(vector<int>::iterator begin, vector<int>::iterator end, int n)
{
    while (begin != end) {
        if (*begin == n)
            return true;
        ++begin;
    }
    return false;
}

int main()
{
    int i;
    bool b1, b2;
    vector<int> ivec;
    cout << "Enter some int number: ";
    while (cin >> i)
        ivec.push_back(i);
    b1 = find_me(ivec.begin(), ivec.begin()+3, 3); 
    b2 = find_me(ivec.begin(), ivec.begin()+4, 3);
    cout << b1 << b2 << endl;
    
    return 0;
}
