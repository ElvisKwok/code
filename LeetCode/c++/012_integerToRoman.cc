// Source : https://leetcode.com/problems/integer-to-roman/
// Author : Elvis Kwok
// Date   : 2015-12-02

/********************************************************************************** 
 * 
 * Given an integer, convert it to a roman numeral.
 * 
 * Input is guaranteed to be within the range from 1 to 3999.
 *               
 **********************************************************************************/

/********************************************************************************** 
 * I = 1
 * V = 5
 * X = 10
 * L = 50
 * C = 100
 * D = 500
 * M = 1000
 * 
 * If a lower value symbol is before a higher value one, it is subtracted. 
 * Otherwise it is added.
 * Lower value symbol in the front only occurs once.(XXL is undefined)
 * So 'IV' is '4' and 'VI' is '6'.
 **********************************************************************************/


#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string thousands(int num) {
        int n = num / 1000;
        return string(n, 'M');
    }

    string hundreds(int num) {
        int newNum = num % 1000;
        int n = newNum / 100;
        if (n == 0)
            return "";
        else if (n<=3)
            return string(n, 'C');
        else if (n == 4)
            return "CD";
        else if (n<=8)
            return "D" + string((n-5), 'C');
        else
            return "CM";
    }

    string tens(int num) {
        int newNum = num % 100;
        int n = newNum / 10;
        if (n == 0)
            return "";
        else if (n<=3)
            return string(n, 'X');
        else if (n == 4)
            return "XL";
        else if (n<=8)
            return "L" + string((n-5), 'X');
        else
            return "XC";
    }

    string units(int num) {
        int n = num % 10;
        if (n == 0)
            return "";
        else if (n<=3)
            return string(n, 'I');
        else if (n == 4)
            return "IV";
        else if (n<=8)
            return "V" + string((n-5), 'I');
        else
            return "IX";
    }

    string intToRoman(int num) {
        string result;
        if (num >= 0 && num <= 3999)
            result = thousands(num) + hundreds(num) + tens(num) + units(num);
        return result;
    }

    // haoel solution:
    string intToRoman2(int num) {
        string symbol[] =  {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};    
        int value[]     =  {1000,900,500,400, 100, 90,  50, 40,  10, 9,   5,  4,   1}; 
        string result;
    
        for(int i=0; num!=0; i++){
            while(num >= value[i]){
                num -= value[i];
                result+=symbol[i];
            }
        }
    
        return result;
    }

    // soulmachine solution:
    string intToRoman3(int num) {
        const string symbol[] =  {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};    
        const int value[]     =  {1000,900,500,400, 100, 90,  50, 40,  10, 9,   5,  4,   1}; 
        string result;
    
        for(size_t i=0; num>0; i++){
            int count = num / value[i];
            num %= value[i];
            for (; count > 0; --count)
                result += symbol[i];
        }
        return result;
    }
};

int main(int argc, char** argv)
{
    Solution s;
    int num = 1234;
    if (argc>1){
        num = atoi(argv[1]);
    }    

    cout << num << " : " << s.intToRoman(num) << endl;
    cout << num << " : " << s.intToRoman2(num) << endl;
    cout << num << " : " << s.intToRoman3(num) << endl;
    return 0;
}
