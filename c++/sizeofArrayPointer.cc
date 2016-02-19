#include <iostream>
using namespace std;

int getSize(int a[]) {
    return sizeof(a);
}

int main() {
    int a[] = {1, 2, 3, 4};
    int size1 = sizeof(a);

    int *pa = a;
    int size2 = sizeof(pa);

    int size3 = getSize(a);
    cout << size1 << "\t" << size2 << "\t" << size3 << endl;
    return 0;
}
