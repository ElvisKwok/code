#include <iostream>
#include <ctime>
#include <unistd.h>
using namespace std;

int main() {
    time_t start = time(NULL);
    sleep(61);
    time_t end = time(NULL);
    cout << (end-start)/60 << " minutes elapsed" << endl;

    return 0;
}
