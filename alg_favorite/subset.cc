#include <iostream>
#include <vector>
using namespace std;

void subsets(vector<vector<int> > &result, vector<int> &nums) {
	int n = nums.size();
	int max = 1 << n;
	for (int i = 0; i < max; ++i) {
		vector<int> path;
		int index = 0;
		for (int j = i; j > 0; j >>= 1) {
			if (j & 0x1) {
				path.push_back(nums[index]);
			}
			++index;
		}
		result.push_back(path);
	}
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
	vector<int> nums;
	vector<vector<int> > result;
	for (int i = 1; i <= 4; ++i)
		nums.push_back(i);
	subsets(result, nums);
	printMatrix(result);
	return 0;
}
