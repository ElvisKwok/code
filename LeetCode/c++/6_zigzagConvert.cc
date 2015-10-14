// Source : https://leetcode.com/problems/zigzag-conversion/
// Author : Elvis Kwok
// Date   : 2015-10-14

/********************************************************************************** 
 * 
 * The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows 
 * like this: (you may want to display this pattern in a fixed font for better 
 * legibility)
 * 
 * P   A   H   N
 * A P L S I I G
 * Y   I   R
 * 
 * And then read line by line: "PAHNAPLSIIGYIR"
 * 
 * Write the code that will take a string and make this conversion given a number of 
 * rows:
 * 
 * string convert(string text, int nRows);
 * 
 * convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
 * 
 *               
 **********************************************************************************/

/* my wrong answer occured:
 * Input: ("A",1)=>Time Limit
 */

#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        const int len = s.size();
        if (numRows <= 1 || len <= 1)
            return s;
// 计算下标法
        string result;
        int index1, index2;
        for (int cur_row = 0; cur_row < numRows; cur_row++) {
            int i = 0;
            index1 = (numRows-1)*i*2 + cur_row;                     // 垂直元素
            index2 = (numRows-1)*(i*2+1) + ((numRows-1)-cur_row);   // 斜对角元素
            while (index1 < len || index2 < len) {
                index1 = (numRows-1)*i*2 + cur_row;
                index2 = (numRows-1)*(i*2+1) + ((numRows-1)-cur_row);
                if (index1 < len)       // 否则末尾会添加“未知元素”("ABC",2)输出"ACB\x00"
                    result += s[index1];
                if (index2 >= len)
                    break;
                if (cur_row != 0 && cur_row != numRows-1)
                    result += s[index2];
                ++i;
            }
        }
        return result;
//// 根据字符串当前字符添加到指定vector<string>法(正反step)
//// 效率略低
//        vector<string> r(numRows);
//        int row = 0, step = 1;
//        for (int i = 0; i < len; ++i) {
//            if (row == numRows-1) step = -1;
//            if (row == 0) step = 1;
//            r[row] += s[i];
//            row += step;
//        }
//
//        string result;
//        for (int i = 0; i < numRows; ++i)
//            result += r[i];
//        return result;
    }
};


int main(int argc, char **argv)
{
    if (argc < 3)
        return 0;
    Solution s;
    cout << s.convert(argv[1], atoi(argv[2])) << endl; 
    return 0;
}
