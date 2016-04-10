#include <iostream>
#include <vector>
using namespace std;

void insertSort(vector<int> &vec, int left, int right) 
{
    for (int i = left+1; i <= right; ++i) {
        int tmp = vec[i];  // 复制为哨兵，储存待排序元素&&判断数组边界
        int j;
        for (j = i; (j > left) && (tmp < vec[j-1]); --j)
            vec[j] = vec[j-1];
        vec[j] = tmp;
    }
}

int main() {
	vector<int> v;
	int n, i;
	cin >> n;
	
	while (cin >> i) {
		v.push_back(i);
	}
	insertSort(v, 0, n-1);
	for (size_t i = 0; i < v.size(); ++i) {
		cout << v[i];
		while (i < v.size()-1) {
			if (v[i] == v[i+1])
				++i;
			else
				break;
		}
	}
	
	return 0;
}
