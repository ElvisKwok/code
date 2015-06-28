#include <iostream>
#include <vector>

using namespace std;

void print(vector<int>::const_iterator beg, vector<int>::const_iterator end)
{
    while (beg != end){
        cout << *beg++;
        if (beg != end)
            cout << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> ivec(10, 2);
    vector<int>::const_iterator beg = ivec.begin();
    vector<int>::const_iterator end = ivec.end();
    print(beg, end);
    
    return 0;
}
