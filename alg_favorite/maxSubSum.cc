/*********************************************************************************
 * 
 * From:
 * << beauty of programming >> & << Data Structure and Algorithm Analysis in C >>
 * Things to clarify:
 * 1) all-negative nums?
 * 2) circle array? What if we can choose A[n-1] and then choose A[0] continuously
 * 3) should we return the index range?
 * 
 *********************************************************************************/


#include <iostream>
using namespace std;

// solution1: brute-force
// O(N^3)
int maxSubSum_1(int *A, int n) {
    int maxVal = INT_MIN; 
    for (int i=0; i<n; ++i) {
        for (int j=i; j<n; ++j) {
            int sum=0;
            for (int k=i; k<=j; ++k) {
                sum += A[k];
            }
            maxVal = max(maxVal, sum);
        }
    }
    return maxVal;
}

// solution2: brute-force improved
// O(N^2)
int maxSubSum_2(int *A, int n) {
    int maxVal = INT_MIN;
    for (int i=0; i<n; ++i) {
        int sum=0;
        for (int j=i; j<n; ++j) {
            sum += A[j];
            maxVal = max(maxVal, sum);
        }
    }
    return maxVal;
}

// solution3: divide-and-conquer
// O(NlogN)
int max3(int a, int b, int c)
{
    int tmp;
    tmp = a > b ? a : b;
    return c > tmp ? c : tmp;
}

static int maxSubSum(const int a[], int left, int right)
{
    int maxLeftSum, maxRightSum;
    int maxLeftBorderSum, maxRightBorderSum;
    int leftBorderSum, rightBorderSum;
    int center, i;

    if (left == right) {      /* Base Case*/
        if (a[left] > 0)
            return a[left];
        else
            return 0;
    }

    center = (left + right) / 2;
    maxLeftSum = maxSubSum(a, left, center);
    maxRightSum = maxSubSum(a, center+1, right);

    maxLeftBorderSum = 0;
    leftBorderSum = 0;
    for (i = center; i >= left; --i) {
        leftBorderSum += a[i];
        if (leftBorderSum > maxLeftBorderSum)
            maxLeftBorderSum = leftBorderSum;
    }

    maxRightBorderSum = 0;
    rightBorderSum = 0;
    for (i = center+1; i <= right; ++i) {
        rightBorderSum += a[i];
        if (rightBorderSum > maxRightBorderSum)
            maxRightBorderSum = rightBorderSum;
    }

    return max3(maxLeftSum, maxRightSum, maxLeftBorderSum+maxRightBorderSum);
}

int maxSubSum_3(int *A, int n) {
    return maxSubSum(A, 0, n-1);
}

// solution4: dynamic programming
// from high=n-2 to low=0
// start[i] means the maxSubSum containing A[i], for help, not final result.
// all[i] means the maxSubSum for A[i] to A[n-1]
// all[0] is the final result.
// we record start[i] to compare with all[i+1] so as to decide choosing a[i] or not
// O(N), O(N)
int maxSubSum_4(int *A, int n) {
    int start[n], all[n];
    start[n-1] = A[n-1];
    all[n-1] = A[n-1];
    for (int i=n-2; i>=0; --i) {
        start[i] = max(A[i], A[i]+start[i+1]);
        all[i] = max(start[i], all[i+1]);
    }
    return all[0];
}

// solution5: fake dynamic programming -- space improved
// because in solution4, start[k+1] only used for start[k] ONCE, all[k+1] for all[k] as well
// so we need only two variable:
// nStart, maxVal
// O(N), O(1)
int maxSubSum_5(int *A, int n) {
    int nStart = A[n-1];
    int maxVal = A[n-1];    // nAll
    for (int i=n-2; i>=0; --i) {
        nStart = max(A[i], nStart+A[i]);    
        maxVal = max(nStart, maxVal);   // the right maxVal is the value of last iteration
    }
    return maxVal;
}
// other version:
int maxSubSum_6(int *A, int n) {
    int nStart = A[n-1];
    int maxVal = A[n-1];    // nAll
    for (int i=n-2; i>=0; --i) {
        if (nStart<0)
            nStart=0;
        nStart += A[i];
        maxVal = max(nStart, maxVal);   // the right maxVal is the value of last iteration
    }
    return maxVal;
}
// other version: from low=1 to high=n-1
int maxSubSum_7(int *A, int n) 
{
    int maxSum=A[0], thisSum=A[0], i;
    for (i = 1; i < n; i++) {
        if (thisSum < 0)
            thisSum = 0;
        thisSum += A[i];
        if (thisSum > maxSum)
            maxSum = thisSum;
    }
    return maxSum;
}

// circle array: 2 situation
// 1) result don't across A[n-1] to A[0] 
//    same as the original problem
// 2) result across A[n-1] to A[0]
//    get maxSubSum_1 start from A[0] (0 ~ i)
//    get maxSubSum_2 end with A[n-1] (j ~ n-1)
//    then m = A[0]+...+A[i]+A[j]+...+A[n-1]
//    if i>=j, then maxVal = A[0]+...+A[n-1]  (0 ~ n-1)
//    else maxVal = maxSubSum_1 + maxSubSum_2
// the final result is max(situation1, situation2)
int maxSubSum_circle(int *A, int n) 
{
    int maxVal1 = maxSubSum_7(A, n);    // situation 1
    int maxVal2 = 0;
    int m1=A[0], sum1=A[0], i=0;
    for (int k=1; k<n; ++k) {
        sum1 += A[k];   // must contain A[0], do whatever sum1<0
        if (sum1 > m1) {
            m1 = sum1;
            i = k;
        }
    }
    int m2=A[n-1], sum2=A[n-1], j=n-1;
    for (int k=n-2; k>=0; --k) {
        sum2 += A[k];   // must contain A[n-1]
        if (sum2 > m2) {
            m2 = sum2;
            j = k;
        }
    }
    if (i >= j) {
        for (int k=0; k<n; ++k) {
            maxVal2 += A[k];
        }
    }
    else
        maxVal2 = m1 + m2;

    return max(maxVal1, maxVal2);
}

int main(int argc, char **argv)
{
    int a[] = {4, -3, 5, -2, -1, 2, 6, -2};
    int n = sizeof(a) / sizeof(int);
    if (argc == 3) {
        a[n-2] = atoi(argv[1]);
        a[n-1] = atoi(argv[2]);
    }
    cout << "A[] = ";
    for (int i=0; i<n; i++) {
        cout << a[i] << "\t";
    }
    cout << endl;
    cout << "max sub sum: " << maxSubSum_1(a, n) << endl;
    cout << "max sub sum: " << maxSubSum_2(a, n) << endl;
    cout << "max sub sum: " << maxSubSum_3(a, n) << endl;
    cout << "max sub sum: " << maxSubSum_4(a, n) << endl;
    cout << "max sub sum: " << maxSubSum_5(a, n) << endl;
    cout << "max sub sum: " << maxSubSum_6(a, n) << endl;
    cout << "max sub sum: " << maxSubSum_7(a, n) << endl;

    cout << "max cicle sub sum: " << maxSubSum_circle(a, n) << endl;

    return 0;
}
