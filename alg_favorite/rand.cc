#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

#define MAX 100

int main()
{
    srand((unsigned)time(NULL));
    for (int i = 0; i < 10; ++i)
        cout << rand() % MAX << "\t";
    cout << endl;
    return 0;
}
