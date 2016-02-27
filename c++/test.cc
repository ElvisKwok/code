#include <iostream>
using namespace std;

int sum1(int n) {
    return n<=0 ? 0 : n+sum1(n-1);
}
int sum2(int n) {
    int sum = 0;
    for (int i=1; i<=n; ++i)
        sum += i;
    return sum;
}

        

int main(int argc, char **argv)
{
    int n;
    if (atoi(argv[2]) == 1)
        n = sum1(atoi(argv[1]));
    else
        n = sum2(atoi(argv[1]));
    cout << n << endl;

    return 0;
}
