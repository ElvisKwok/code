#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class GT_cls {
public:
    GT_cls(int val=0): bound(val) { }
    bool operator() (const int &ival)
    {
        return ival > bound;
    }
private:
    int bound;
};

int main()
{
    vector<int> ivec;

    for (int i = 0; i < 10; i++)
        ivec.push_back(i*2);
    
    int spval;
    cout << "enter a specified value: " << endl;
    cin >> spval;

    vector<int>::iterator iter;
    iter = find_if(ivec.begin(), ivec.end(), GT_cls(spval));

    if (iter != ivec.end())
        cout << "the first element that is larger than "
             << spval << " : "
             << *iter << endl;
    else
        cout << "no element that is larger than "
             << spval << endl;
     
    return 0;
}
