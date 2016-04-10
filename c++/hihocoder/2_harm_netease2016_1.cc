#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>
using namespace std;

int harm(int R, vector<int> &pos, int x0, int y0) {
    int cnt=0;
    for (size_t i=0; i<pos.size(); i+=2) {
        int x = abs(pos[i]-x0);
        int y = abs(pos[i+1]-y0);
        double dist = sqrt(x*x+y*y);
        if (fabs(dist-R) > 0.00000001)
            ++cnt;
    }
    return cnt;
}

int main() {
    int R;
    vector<int> pos;
    int x, y, x0, y0;
    cin >> R;
    while (cin >> x >> y) {
        pos.push_back(x);
        pos.push_back(y);
    }
    y0 = pos.back();
    pos.pop_back();
    x0 = pos.back();
    pos.pop_back();
    cout << harm(R, pos, x0, y0) << 'x' << endl;
    
    return 0;
}
