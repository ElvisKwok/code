#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;
    
int main() {
	freopen("input.txt", "r", stdin);

    int n, m;
	double sroot, sum=0;
	while (cin >> n >> m) {
		sroot = n;
		sum	= sroot;
		while (--m > 0) {
			sroot = sqrt(sroot);
			sum	+= sroot;
		}
		printf("%.2f\n", sum);
	}

	fclose(stdin);
    return 0;
}
