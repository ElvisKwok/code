#include <iostream>
#include <bitset>
using namespace std;

int main()
{
    bitset<32> bitvec;
    int a=0, b=1, index=a+b;
    while (index <= 21) {
        bitvec.set(index);
        a = b;
        b = index;
        index = a + b;
    }
    cout << bitvec << endl;

    return 0;
}
