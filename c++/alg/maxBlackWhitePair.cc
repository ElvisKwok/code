#include <iostream>
#include <algorithm>
using namespace std;

#define MAXSIZE 100

struct point {
	float x;
	float y;
	bool visited;
};

bool compare(const point &p1, const point &p2) {
	return p1.x < p2.x;
}

int count(point black[], point white[], int n, int m) {
	int cnt = 0;
	int maxY;
	sort(black+1, black+n, compare);
	sort(white+1, white+m, compare);
	for (int i=n; i>=1; --i) {
		black[i].visited = true;
		int maxPoint = 0;
		bool found = false;
		for (int j=m; j>=1; --j) {
			if (white[j].x <= black[i].x
				&& white[j].y <= black[j].y
				&& white[maxPoint].y <= white[j].y
				&& white[maxPoint].visited == false)
			{
				maxPoint = j;
				found = true;
			}
		}
		if (found) {
			white[maxPoint].visited = true;
			++cnt;
		}
	}
	return cnt;	
}

int main() {
	point p[3];
	int N;		// 测试组数
	int n, m;	// 每组黑、白点数
	point black[MAXSIZE], white[MAXSIZE];
	cin >> N;
	cin >> n >> m;
	while (N-- > 0) {
		black[0].x = INT_MIN;
		black[0].y = INT_MIN;
		black[0].visited = false;
		white[0].x = INT_MIN;
		white[0].y = INT_MIN;
		white[0].visited = false;
		for (int i = 1; i <= n; ++i) {
			cin >> black[i].x >> black[i].y;
			black[i].visited = false;
		}
		for (int i = 1; i <= m; ++i) {
			cin >> white[i].x >> white[i].y;
			white[i].visited = false;
		}
		cout << count(black, white, n, m) << endl;
	}
	return 0;
}
