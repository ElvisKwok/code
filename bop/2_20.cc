#include <iostream>
#include <ctime>
#include <unistd.h>
using namespace std;

int main() {
    time_t start = time(NULL);
    int rg[30];
    for (int i=0; i<30; ++i) 
        rg[i] = i+2;
    for (long i=1; i<LONG_MAX; ++i) {
        int hit = 0;
        int hit1 = -1;
        int hit2 = -1;
        for (int j=0; j<30 && hit<=2; ++j) {
            if (i % rg[j] != 0) {
                hit++;
                if (hit == 1)
                    hit1 = j;
                else if (hit == 2)
                    hit2 = j;
                else 
                    break;
            }
        }
        if ((hit == 2) && (hit1 + 1 == hit2)) {
            cout << "find: " << i << endl;
            time_t end = time(NULL);
            cout << (end-start)/60 << " minutes elapsed" << endl;
        }
    }
    return 0;
}
