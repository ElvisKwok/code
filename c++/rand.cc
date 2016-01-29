#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(int argc, char **argv)
{
    srand(time(NULL));  // use current time as seed for random generator
    int n=7;
    if (argc == 2)
        n = atoi(argv[1]);
    cout << "rand()%10: changed with seed of time(Work for C and C++)" << endl;
    for (int i=0; i<n; ++i)
        cout << rand()%10 << " ";
    cout << endl;
    cout << "random()%10: do not change(changed in C)" << endl;
    for (int i=0; i<n; ++i)
        cout << random()%10 << " ";
    cout << endl;

    return 0;
}
