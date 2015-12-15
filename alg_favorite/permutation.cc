#include <iostream>
using namespace std;

void perm_recursive(int array[], int begin, int end) {
    if (begin == end) {
        for (int i=0; i<=end; ++i)
            cout << array[i];
        cout << endl;
    } else {
        for (int i=begin; i<=end; ++i) {
            //cout <<"(begin, i): " << begin << ", " << i << ";\tswap(" << array[begin] << ", " << array[i] << ")" << endl;
            swap(array[begin], array[i]);
            perm_recursive(array, begin+1, end);
            swap(array[begin], array[i]);
        }
    }
}

int main() {
    int a[] = {0, 1, 2, 3};
    perm_recursive(a, 0, sizeof(a)/sizeof(int)-1);

    return 0;
}
