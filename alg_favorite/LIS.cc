#include <iostream>
#include <vector>
using namespace std;

// 最长递增子序列Longest Increasing Subsequence

// solution1: DP
// 返回len
int LIS_1(int a[], int n) {
	int *d = new int[n];
	int maxLen = 1;
	for (int i=0; i < n; ++i) {
		d[i] = 1;
		for (int j=0; j<i; ++j) {
			if (a[j] <= a[i] && d[j] + 1 > d[i])
				d[i] = d[j] + 1;
		}
		if (maxLen < d[i])
			maxLen = d[i];
	}
	delete[] d;
	return maxLen;
}

// solution2: sort + LCS
// X, Y=sort(X), maxLen = LCS(X, Y) 

// solution3: solution 1 + binarySearch O(nlogn)
// 使用一个数组B来存储当前"子序列"的LCS的最后元素
// B[d[i]] = a[i]
int upper_bound(int a[], int low, int high, int v);
int LIS_3(int a[], int n) {
	int maxLen = 0;	// maxLen是B数组下标，同时最大长度是maxLen+1
	int *B = new int[n];
	B[0] = a[0];
	for (int i=1; i<n; ++i) {	
		int pos = upper_bound(B, 0, maxLen, a[i]);	// 找到插入位置
		B[pos] = a[i];
		if (maxLen < pos)
			maxLen = pos;
	}
	return maxLen+1;
}

int upper_bound(int a[], int low, int high, int v) {
	if (a[high] <= v)
		return high+1;
	while (low <= high) {
		int mid = low + (high-low)/2;
		if (v >= a[mid])
			low = mid+1;
		else
			high = mid-1;
	}
	return low;
}

int main() {
	int a[] = {5, 3, 4, 8, 6, 7};
	cout << LIS_1(a, 6) << endl;
	cout << LIS_3(a, 6) << endl;
	int b[] = {2, 1, 5, 3, 6, 4, 8, 9, 7};
	cout << LIS_1(b, 9) << endl;
	cout << LIS_3(b, 9) << endl;
	return 0;
}
