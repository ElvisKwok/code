#include <iostream>
#include <cstdio>
using namespace std;

const int MAX = 100;

struct person{
	int h;
	int w;
};

person p[MAX];

bool cmp(person A, person B) {
	if (A.h == B.h)
		return A.w < B.w;
	return A.h < B.h;
}


// 返回len
int LIS(person a[], int n) {
	int *d = new int[n];
	int maxLen = 1;
	for (int i=0; i < n; ++i) {
		d[i] = 1;
		for (int j=0; j<i; ++j) {
			if (a[j].w <= a[i].w && d[j] + 1 > d[i])
				d[i] = d[j] + 1;
		}
		if (maxLen < d[i])
			maxLen = d[i];
	}
	delete[] d;
	return maxLen;
}

int main() {
	freopen("input.txt", "r", stdin);
	int n;
	cin >> n;
	for (int i=0; i<n; ++i)
		cin >> p[i].h >> p[i].w;
	sort(p, p+n, cmp);
	cout << LIS(p, n) << endl;
	fclose(stdin);
	return 0;
}
