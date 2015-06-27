#include <iostream>

using namespace std;

int main()
{
    int ffCnt = 0, flCnt = 0, fiCnt = 0;
    char preCh = '\0', currCh;

    while (cin >> currCh) {
        if (preCh == 'f') {
            switch (currCh) {
                case 'f':
                    ++ffCnt;
                    break;
                case 'l':
                    ++flCnt;
                    break;
                case 'i':
                    ++fiCnt;
                    break;
            }
        }
        preCh = currCh;
    }
    
    cout << "ffCnt: " << ffCnt << endl;
    cout << "flCnt: " << flCnt << endl;
    cout << "fiCnt: " << fiCnt << endl;

    return 0;
}
