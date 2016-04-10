#include <iostream>
#include <vector>
#include <string>
using namespace std;

class GrayCode {
public:
    vector<string> getGray(int n) {
        // write code here
        vector<string> result;
        for (int i=0; i<(1<<n); ++i) {
            int ival = i ^ (i>>1);
            string one = intToNBitString(ival, n);
            result.push_back(one);
        }
        return result;
    }
    string intToNBitString(int ival, int n) {
        string s;
		while (ival > 0) {
            int bit = ival & 0x1;
            s.insert(s.begin(), bit+'0');
            ival >>= 1;
        }
        while (s.size() < n) 
            s.insert(s.begin(), '0');
        return s;
    }
};

int main() {
    GrayCode gc;
    vector<string> result = gc.getGray(3);
    for (int i=0; i<result.size(); ++i) 
        cout << result[i] << endl;
    return 0;
}
