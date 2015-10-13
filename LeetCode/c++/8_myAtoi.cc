/* bug:
 * "+", "-+1", "         010", "  -0012a42"(-12)
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        int i=0, len=str.size(), base=0;
        int flag=1;
        int MAX_INT = (-1u)>>1, MIN_INT = (-MAX_INT-1);
        bool base_changed = false;
        while (i < len && str[i]==' ')
            ++i;
        if (len >= 2) {
            int tmp = i;
            if (str[tmp] == '-') {
                i++;
                flag = -1;
            }
            if (str[tmp] == '+')
                i++;
        }
        while (i < len) {
            if (base > MAX_INT/10 || (flag*base) < MIN_INT/10)
                return 0;
            if (str[i] < '0' || str[i] > '9')
                if (!base_changed)
                    return 0;
                else
                    break;
            base = base * 10 + str[i] - '0';
            base_changed = true;
            ++i;
        }
        return base * flag;
    }
};


int main(int argc, char **argv)
{
    Solution s;
    cout << s.myAtoi(argv[1]) << endl;
     
    return 0;
}
