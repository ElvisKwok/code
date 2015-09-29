#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class EQ_cls {
public:
    EQ_cls(int val=0): spval(val) { }
    bool operator() (const int &ival)
    {
        return ival == spval;
    }
private:
    int spval;
};

int main()
{
    vector<int> ivec;

    for (int i = 0; i < 10; i++)
        ivec.push_back(i*2);
    
    int replacedVal, newVal;
    cout << "enter a value that will be replaced: " << endl;
    cin >> replacedVal;
    cout << "enter a new value: " << endl;
    cin >> newVal;

    replace_if(ivec.begin(), ivec.end(), EQ_cls(replacedVal), newVal);

    cout << "new sequence: " << endl;
    for (vector<int>::iterator iter = ivec.begin(); iter != ivec.end(); ++iter)
        cout << *iter << " ";
     
    return 0;
}
