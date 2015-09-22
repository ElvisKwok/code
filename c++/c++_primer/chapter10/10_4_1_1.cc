#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main()
{
    vector<int> ivec;
    for (vector<int>::size_type i = 0; i != 10; ++i) {
        ivec.push_back(i);
        ivec.push_back(i);
    }

    set<int> iset(ivec.begin(), ivec.end());
    cout << "ivec size: " << ivec.size() << endl;
    cout << "iset size: " << iset.size() << endl;
     
    return 0;
}
