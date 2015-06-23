#include <iostream>
#include <vector>
using namespace std;

int main()
{
    const size_t array_size = 10;
    int ia1[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int ia2[array_size];
    for (size_t ix = 0; ix < array_size; ix++) 
        ia2[ix] = ia1[ix];
        
    vector<int> ivec1(10, 20);
    vector<int> ivec2;
    for (vector<int>::iterator iter = ivec1.begin(); iter != ivec1.end(); iter++) 
        ivec2.push_back(*iter);
    for (vector<int>::size_type ix = 0; ix != ivec1.size(); ix++) 
        ivec2.push_back(ivec1[ix]);

    return 0;
}
