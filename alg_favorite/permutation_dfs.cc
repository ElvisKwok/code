#include <iostream>
#include <vector>
using namespace std;

/********************************************************
 *
 * A = {a1, a2, ..., an}
 * Ai = A - {ai}
 * Perm(A) = {a1Perm(A1), a2Perm(A2), ..., anPerm(An)}
 *
 *******************************************************/

/********************************************************
char s[] = "abc"

dfs(s, 0, 2)

    - a开头  -> dfs(s, 1, 2) "abc"	(完成后变回“abc")
	|                _ b开头        ->    dfs(s, 2, 2) 得到"abc"  (完成后变回“abc")
	|           for |_ c开头        ->    dfs(s, 2, 2) 得到"acb"  (完成后变回“abc")
    |
	|
for - b开头  -> dfs(s, 1, 2) "bac"	(完成后变回“abc")   <------------------------------|
	|                _ a开头        ->    dfs(s, 2, 2) 得到"bac"  (完成后变回“bac")    |
	|           for |_ c开头        ->    dfs(s, 2, 2) 得到"bca"  (完成后变回“bac")   -|
	|
	|
	- c开头  -> dfs(s, 1, 2) "cba" 	(完成后变回“abc")   <------------------------------|
	                 _ b开头        ->    dfs(s, 2, 2) 得到"cba"  (完成后变回“cba")    |
	            for |_ a开头        ->    dfs(s, 2, 2) 得到"cab"  (完成后变回“cba")   -|

 *******************************************************/


void dfs(vector<vector<int> > &result, vector<int> &nums, int first, int last) {
    if (first == last) {
        result.push_back(nums);
        return ;
    }
    for (int i=first; i<=last; ++i) {       // first~last, 与first交换的i范围
        swap(nums[first], nums[i]);
        dfs(result, nums, first+1, last);   // first+1 not i+1，下一层dfs被交换的first，子问题
        swap(nums[first], nums[i]);
    }
}

vector<vector<int> > permute(vector<int> &nums) {
    vector<vector<int> > result;
    dfs(result, nums, 0, nums.size()-1);
    //unique(result.begin(), result.end());
    return result;
}

void printMatrix(vector<vector<int> >& vv) {
    for (int i = 0; i < vv.size(); ++i) {
        cout << "[ ";
        for (int j = 0; j < vv[i].size(); ++j) {
            cout << vv[i][j] << " ";
        }
        cout << "]" << endl;
    }
}

int main() {
    int a[] = {1, 2, 3};
    vector<int> nums(a, a+sizeof(a)/sizeof(int));
    vector<vector<int> > result = permute(nums);
    printMatrix(result);
    return 0;
}
