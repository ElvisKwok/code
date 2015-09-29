#include <iostream>
#include <algorithm>
#include <functional>
#include <string>
#include <vector>
using namespace std;

int main()
{
    const int ARR_SIZE = 7;
    int ia[ARR_SIZE] = {1, 1025, 2, 1026, 1030, 3, 1048};
    vector<int> ivec(ia, ia+ARR_SIZE);
    string sa[ARR_SIZE] = {"many", "mach", "that", "pooh", "this", "pooh"};
    vector<string> svec(sa, sa+ARR_SIZE);

    // (a) find all value(s) that are greater than 1024
    cout << "all value(s) that are greater than 1024: " << endl;
    vector<int>::iterator iter = ivec.begin();
    while ((iter = find_if(iter, ivec.end(), bind2nd(greater<int>(), 1024))) != ivec.end())
        cout << *(iter++) << ' ';
    cout << endl;
    
    // (b) find all string(s) that are not equal to "pooh"
    cout << "all string(s) that are not equal to \"pooh\": " << endl;
    vector<string>::iterator s_iter = svec.begin();
    while ((s_iter = find_if(s_iter, svec.end(), bind2nd(not_equal_to<string>(), "pooh"))) != svec.end())
        cout << *(s_iter++) << ' ';
    cout << endl;

    // (c) multiplies all value(s) by 2 by 2 
    transform(ivec.begin(), ivec.end(), ivec.begin(), bind2nd(multiplies<int>(), 2));
    cout << "multiplies all value(s) by 2: " << endl;
    for (vector<int>::iterator iter = ivec.begin(); iter != ivec.end(); ++iter)
        cout << *iter << ' ';
    cout << endl;
    
     
    return 0;
}
