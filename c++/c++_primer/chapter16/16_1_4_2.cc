#include <iostream>
#include <vector>
#include <string>
using namespace std;

template <typename Parm>
void print(const Parm& c)
{
    typename Parm::size_type index = 0;
    while (index != c.size()) {
        cout << c[index] << " ";
        ++index;
    }
    cout << endl;
}

int main()
{
    int ia[] = {1, 2, 3, 4, 4};
    string sa[] = {"hello", "world", "this"};
    vector<int> ivec(ia, ia+5);
    vector<string> svec(sa, sa+3);
    print(ivec);
    print(svec);
     
    return 0;
}
