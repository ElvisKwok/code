#include <iostream>
#include <vector>
using namespace std;

//int numsOfWays(int m, int n) {
//	vector<vector<int> > f(m, vector<int>(n, 0));
//	f[0][0] = 1;
//	for (int i=1; i<m; ++i) 
//		f[i][0] = f[i-1][0];
//	for (int j=1; j<n; ++j) 
//		f[0][j] = f[0][j-1];
//	for (int i=1; i<m; ++i) 
//		for (int j=1; j<n; ++j)
//			f[i][j] = f[i-1][j] + f[i][j-1];
//
//	return f[m-1][n-1];
//}

int numsOfWays(int m, int n) {
	vector<int> f(n, 0);
	f[0] = 1;
	for (int i=0; i<m; ++i) {
		for (int j=0; j<n; ++j) {
			if (i==0 && j>0)
				f[j] = f[j-1];
			else if (i>0 && j==0)
				f[j] = f[j];
			else
				f[j] = f[j-1] + f[j];
		}
	}

	return f[n-1];
}

int main(int argc, char **argv) {
	cout << numsOfWays(atoi(argv[1]), atoi(argv[2])) << endl;
	return 0;
}
