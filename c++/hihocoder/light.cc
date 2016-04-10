#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

double light(vector<int> &v) {
	sort(v.begin(), v.end());
	double maxDiff=0;
	for (int i = 0; i < v.size()-1; ++i) {
		double diff= v[i+1] - v[i];
		if (maxDiff < diff)
			maxDiff = diff;
	}
	return maxDiff / 2;
}
	

int main() {
	freopen("input2.txt", "r", stdin);
    int n, i, l;
    vector<int> v;
	while (cin >> n >> l) {
    	for (int j=0; j<n; ++j) {
    	    cin >> i;
    	    v.push_back(i);
    	}
    	v.push_back(l);
    	v.push_back(0);
		//cout << light(v) << endl;
		printf("%.2f\n", light(v));
	}
	fclose(stdin);
    return 0;
}
