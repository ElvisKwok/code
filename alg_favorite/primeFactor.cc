#include <iostream>
using namespace std;

void primeFactor(int n) {
    int i=2;
    cout << n << " = ";
    while (i*i <= n) {      // prime <= sqrt(n)
        while (n%i == 0) {
            n /= i;
            if (n == 1)
                cout << i << endl;
            else
                cout << i << " * ";
        }
        ++i;
    }
    if (n>1)    // not prime num <= sqrt(n) is the factor of n
        cout << n << endl;
}

void primeFactor2(int n) {
    cout << n << " = ";
    for (int i=2; i*i<=n; ++i) {
        while (n!=i) {
            if (n%i==0) {
                cout << i << " * ";
                n /= i;
            }
            else    
                break;  // next i
        }
    }
    cout << n << endl;
}

int main(int argc, char **argv) {
    primeFactor(atoi(argv[1]));
    primeFactor2(atoi(argv[1]));
    return 0;
}
