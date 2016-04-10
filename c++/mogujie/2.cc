#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int maxNumCostMin(vector<int> &v) {
	int min = 0;
	for (size_t i = 0; i < v.size(); ++i) {
		if (v[min] >= v[i])
			min = i;
	}
	return min;
}

int maxNumCost2ndMin(vector<int> &v, int min) {
	int index = 0;
	bool found = false;
	for (size_t i = 0; i < v.size(); ++i) {
        if (v[i] == v[min]) {
            index = i+1;
			continue;
        }
		if (index < v.size() && v[index] >= v[i]) {
			found = true;
			index = i;
		}
	}
	return found ? index : -1;
}

void maxNum(int n, vector<int> &v) {
	vector<int> result;
	int minCostIndex = maxNumCostMin(v);
	if (n < v[minCostIndex]) {
		cout << -1;
		return ;
	}
	while (n >= 2 * v[minCostIndex]) {
		result.push_back(minCostIndex+1);
		n -= v[minCostIndex];
	}
	if (n >= v[minCostIndex] && n < 2*v[minCostIndex]) {
		int secondMinCostIndex = maxNumCost2ndMin(v, minCostIndex);
		if (secondMinCostIndex != -1 && n >= v[secondMinCostIndex]) {
			result.push_back(secondMinCostIndex+1);
		}
		else {
			result.push_back(minCostIndex+1);
		}
	}
	sort(result.begin(), result.end());
	for (int i = result.size()-1; i >= 0; --i) 
		cout << result[i];
	cout << endl;
}
		
    
int main() {
	freopen("input2.txt", "r", stdin);

    int n, a;
	vector<int> v;
	cin >> n;
    for (int i=0; i<9; ++i) {
        cin >> a;
		v.push_back(a);
    }

	maxNum(n, v);

	fclose(stdin);
    return 0;
}
