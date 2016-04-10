#include <iostream>
#include <cmath>
using namespace std;

// file description:
// given n dices, output probability of all possible dices' sum
// sum'range : n~6n
// probability base: 6^n

int g_maxValue = 6;

// =====================solution 1=====================
// recursively
void probability(int number, int* nProbabilities);
void probability(int original, int current, int sum, int* nProbabilities);

void printProbability_1(int number) {
    if (number < 1)
        return;
    int maxSum = number * g_maxValue;
    int* nProbabilities = new int[maxSum - number + 1];
    for (int i = number; i <= maxSum; ++i)
        nProbabilities[i-number] = 0;

    probability(number, nProbabilities);

    int total = pow((double)g_maxValue, number);
    for (int i = number; i <= maxSum; ++i) {
        double ratio = (double)nProbabilities[i-number] / total;
        cout << i << ": " << ratio << endl;
    }
    delete[] nProbabilities;
}

void probability(int number, int* nProbabilities) {
    for (int i=1; i <= g_maxValue; ++i)
        probability(number, number, i, nProbabilities);
}

void probability(int original, int current, int sum, int* nProbabilities) {
    if (current == 1)
        ++nProbabilities[sum-original];
    else {
        for (int i=1; i <= g_maxValue; ++i) 
            probability(original, current-1, i+sum, nProbabilities);
    }
}

// =====================solution 2=====================
// iteratively:
// using two array crossly
// f(n) = f(n-1) + f(n-2) + ... + f(n-6)
// here f(n-1) ... f(n-6) is refer to previous iteration, stored in the other array
// f(n) is stored in the current array

void printProbability_2(int number) {
    if (number < 1)
        return ;
    int* pProbabilities[2];
    pProbabilities[0] = new int[g_maxValue * number + 1];
    pProbabilities[1] = new int[g_maxValue * number + 1];
    for (int i=0; i <= g_maxValue*number; ++i) {
        pProbabilities[0][i] = 0;
        pProbabilities[1][i] = 0;
    } 
    int flag = 0;
    for (int i=1; i <= g_maxValue; ++i)
        pProbabilities[0][i] = 1;
    for (int k=2; k <= number; ++k) {
        for (int i=0; i<k; ++i)
            pProbabilities[1-flag][i] = 0;  // imposssible value;
        for (int i=k; i <= g_maxValue * k; ++i) {
            pProbabilities[1-flag][i] = 0;  // reset 0 for later accumulate +=
            for (int j=1; j<=i && j <= g_maxValue; ++j)  // f(n) = f(n-1) + f(n-2) + ... + f(n-6)
                pProbabilities[1-flag][i] += pProbabilities[flag][i-j];
        }
        flag = 1 - flag;
    }
    double total = pow((double)g_maxValue, number);
    for (int i = number; i <= g_maxValue * number; ++i) {
        double ratio = (double)pProbabilities[flag][i] / total;
        cout << i << ": " << ratio << endl;
    }
    delete[] pProbabilities[0];
    delete[] pProbabilities[1];
}

// =====================Test Code=====================
void Test(int n)
{
    printf("Test for %d begins:\n", n);
    
    printf("Test for solution1\n");
    printProbability_1(n);

    printf("Test for solution2\n");
    printProbability_2(n);

    printf("\n");
}

int main()
{
    Test(1);
    Test(2);
    Test(3);
    Test(4);
    
    Test(11);

    Test(0);

    return 0;
}
