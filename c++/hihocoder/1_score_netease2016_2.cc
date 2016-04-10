#include <iostream>
#include <vector>
using namespace std;
int getMinIndex(vector<int> vec) {
    int min = INT_MAX;
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
		bVec[index] = INT_MAX;
		curScore += thisAdd;
    }
    
    return timeNeed;
}

int main() {
    int n, upperBound, avg;
    int a, b;
    vector<int> aVec, bVec;
	n = 5; upperBound=10; avg=9;
    aVec.push_back(0);
    bVec.push_back(5);
    aVec.push_back(9);
    bVec.push_back(1);
    aVec.push_back(8);
    bVec.push_back(1);
    aVec.push_back(0);
    bVec.push_back(1);
    aVec.push_back(9);
    bVec.push_back(100);
    //for (int i=0; i<n; ++i) {
    //    cin >> a >> b;
    //    aVec.push_back(a);
    //    bVec.push_back(b);
    //}
    cout << needTime(n, upperBound, avg, aVec, bVec) << endl;
    return 0;
}
