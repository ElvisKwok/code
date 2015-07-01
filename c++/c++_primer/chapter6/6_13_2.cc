#include <iostream>
#include <bitset>
using namespace std;

int main()
{
    bitset<100> bs;
    for (size_t ix = 0; ix != 100; ++ix)
        bs[ix] = 1;
    try {
        bs.to_ulong();
    } catch(overflow_error err) {
    //} catch(runtime_error err) {
        cout << err.what() << endl;
    }

    return 0;
}
