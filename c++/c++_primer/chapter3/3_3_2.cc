#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> ivec;
    int tmp;
    bool sing = false;
    cout << "input some int number: ";
    while (cin >> tmp)
        ivec.push_back(tmp);
    if (ivec.empty()) {
        cout << "Nothing inputed!" << endl;
        return -1;
    }
    if (ivec.size() % 2 != 0)
        sing = true;

    cout << "adding two adjcent num..." << endl;
    vector<int>::size_type ix; 
    for (ix = 0; ix < ivec.size()-1; ix += 2 ) 
        cout << ivec[ix] + ivec[ix+1] << endl;
    if (sing)
        cout << "The rest num is: " << ivec[ivec.size()-1] << endl;
        
    cout << "adding two num from head and tail pair..." << endl;
    vector<int>::size_type begin, end;
    for (begin = 0, end = ivec.size()-1; begin < end; begin++, end--)
        cout << ivec[begin] + ivec[end] << endl;
    if (sing)
        cout << "The rest num is: " << ivec[begin] << endl;
    
    return 0;
}
