#include <iostream>
#include <vector>
using namespace std;

/********************************************************
 * compare in group of 2
 * compare times: 1.5N
 * (a[0], a[1]), (a[2], a[3]), ..., (a[n-2], a[n-1])
 * suppose global maximum and minimum val as 'MAX', 'MIN'
 * in each group, compare 1 time to get 'max' and 'min'
 * then compare 2 more times for (MAX, max) and (MIN, min)
 * so each group needs to compare 3 times.
 *
 *******************************************************/
vector<int> findMaxMin_group(vector<int> &ivec) {
    int maxV, minV;
    vector<int> result;
    result.push_back(INT_MIN);
    result.push_back(INT_MAX);

    for (int i=0; i<ivec.size(); i+=2) {
        if (i<ivec.size()-1) {
            maxV = max(ivec[i], ivec[i+1]);
            minV = min(ivec[i], ivec[i+1]);
        }
        else
            maxV = minV = ivec[i];
        result[0] = max(result[0], maxV);
        result[1] = min(result[1], minV);
    }
    return result;
}

/********************************************************
 *
 * divide-and-conquer
 * compare times: 
 * f(2) = 1
 * f(n) = 2*f(n/2) + 2 = 4*f(n/4) + 4 + 2
 *      = ...
 *      = 1.5N-2
 * max = result[0], min = result[1];
 *
 *******************************************************/
vector<int> findMaxMin(vector<int> &ivec, int low, int high) {
    vector<int> result, resultLeft, resultRight;
    result.push_back(INT_MIN);
    result.push_back(INT_MAX);
    if (high-low <= 1) {
        result[0] = ivec[low] > ivec[high] ? ivec[low] : ivec[high];
        result[1] = ivec[low] < ivec[high] ? ivec[low] : ivec[high];
        return result;
    }
    resultLeft = findMaxMin(ivec, low, low+(high-low)/2);
    resultRight = findMaxMin(ivec, low+(high-low)/2+1, high);
    result[0] = resultLeft[0]>resultRight[0] ? resultLeft[0] : resultRight[0];
    result[1] = resultLeft[1]<resultRight[1] ? resultLeft[1] : resultRight[1];
    return result;
}

int main(int argc, char **argv) {
    vector<int> ivec{5, 2, 6, 8, 4, 1, 3, 7};
    vector<int> result = findMaxMin(ivec, 0, ivec.size()-1);
    cout << "max = " << result[0] << endl;
    cout << "min = " << result[1] << endl;
    vector<int> ivec2{5, 2, 6, 8, 4, 1, 3, 7};
    vector<int> result2 = findMaxMin_group(ivec2);
    cout << "max = " << result2[0] << endl;
    cout << "min = " << result2[1] << endl;

    return 0;
}
