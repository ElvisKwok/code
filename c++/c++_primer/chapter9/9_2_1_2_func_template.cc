#include <iostream>
#include <vector>

using namespace std;

template<typename T1, typename T2>
T1 find_me_iter(T1 begin, T1 end, T2 n)
{
    while (begin != end) {
        if (*begin == n)
            return begin;
        ++begin;
    }
    return begin;
}

int main()
{
    int i;
    vector<int> ivec;
    vector<int>::iterator b1, b2;
    cout << "Enter some int number: ";
    while (cin >> i)
        ivec.push_back(i);
    b1 = find_me_iter(ivec.begin(), ivec.begin()+2, 3); 
    b2 = find_me_iter(ivec.begin(), ivec.begin()+4, 3);
    cout << *b1 << *b2 << endl;
    
    return 0;
}
