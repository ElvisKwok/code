#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
const int MAX = ~(1<<31);
int getMinIndex(vector<int> vec) {
    int min = MAX;
    int index=0;
    for (size_t i=0; i<vec.size(); ++i) {
        if (min > vec[i]) {
            min = vec[i];
            index = i;
        }
    }
    return index;
}

int needTime(int n, int upperBound, int avg, vector<int> &aVec, vector<int> &bVec){
    int needTotalScore = n * avg;
    int curScore = 0;
    int timeNeed = 0;
    for (size_t i=0; i<aVec.size(); ++i)
        curScore += aVec[i];
    for (size_t i=0; i<aVec.size(); ++i) {
        int diff = needTotalScore - curScore;
        if (diff <= 0)
            break;
        int index = getMinIndex(bVec);
		int thisAdd = min(diff, upperBound-aVec[index]);
        timeNeed += bVec[index] * thisAdd;
		aVec[index] += thisAdd;
		bVec[index] = MAX;
		curScore += thisAdd;
    }
    
    return timeNeed;
}

int main() {
	freopen("input.txt", "r", stdin);
    int n, upperBound, avg;
    int a, b;
    vector<int> aVec, bVec;
	cin >> n >> upperBound >> avg;
    for (int i=0; i<n; ++i) {
        cin >> a >> b;
        aVec.push_back(a);
        bVec.push_back(b);
    }
    cout << needTime(n, upperBound, avg, aVec, bVec) << endl;
	fclose(stdin);
    return 0;
}
