#include <iostream>
#include <vector>
#include <list>
using namespace std;

int main()
{
    int ia[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89};
    list<int> ilst(ia, ia+12);
    vector<int> ivec(ia, ia+12);

    for (list<int>::iterator liter = ilst.begin(); liter != ilst.end(); ++liter) {
        if (*liter % 2 != 0) {
            ilst.erase(liter);
            --liter;     // 迭代器回退，指向被删元素的前一元素
        }
    }

    for (vector<int>::iterator viter = ivec.begin(); viter != ivec.end(); ++viter) {
        if (*viter % 2 == 0) {
            ivec.erase(viter);
            --viter;
        }
    }

    return 0;
}
