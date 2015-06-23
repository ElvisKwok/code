#include <iostream>
#include <bitset>
using namespace std;

int main()
{
    bitset<64> bitvec1(32);
    bitset<32> bitvec2(1010101);
    
    string bstr;
    cin >> bstr;
    bitset<8> bitvec3(bstr);
    cout << bitvec1 << '\n' << bitvec2 << '\n' << bitvec3 << endl;
    
    return 0;
}
