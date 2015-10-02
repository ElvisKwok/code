#include <iostream>
#include <vector>
#include <string>
using namespace std;

template <typename InIt, typename T>
InIt findElem(InIt first, InIt last, const T& val)
{
    while(first != last) {
        if (*first == val)
            return first;
        else
            ++first;
    }
    return last;
}

int main()
{
    int ia[] = {1, 2, 3, 4, 4};
    string sa[] = {"hello", "world", "this"};
    vector<int> ivec(ia, ia+5);
    vector<string> svec(sa, sa+3);

    vector<int>::iterator iit = findElem(ivec.begin(), ivec.end(), 3);
    if (iit != ivec.end())
        cout << "found this element: " << *iit << endl;
    
    vector<string>::iterator sit = findElem(svec.begin(), svec.end(), "world");
    if (sit != svec.end())
        cout << "found this element: " << *sit << endl;

    return 0;
}
