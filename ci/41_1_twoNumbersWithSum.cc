#include <iostream>
using namespace std;

// file description:
// 2Sum

bool findNumbersWithSum(int data[], int length, int sum, int* num1, int* num2) {
    bool found = false;
    if (length < 1 || num1 == NULL || num2 == NULL)
        return found;
    int low = 0;
    int high = length-1;
    while (low < high) {
        long long curSum = data[low] + data[high];
        if (curSum == sum) {
            *num1 = data[low];
            *num2 = data[high];
            found = true;
            break;
        }
        else if (curSum < sum)
            ++low;
        else
            --high;
    }
    return found;
}

// =====================Test Code=====================
void Test(char* testName, int data[], int length, int sum, bool expectedReturn)
{
    if(testName != NULL)
        printf("%s begins: ", testName);
    
    int num1, num2;
    int result = findNumbersWithSum(data, length, sum, &num1, &num2);
    if(result == expectedReturn)
    {
        if(result)
        {
            if(num1 + num2 == sum)
                printf("Passed. \n");
            else
                printf("Failed. \n");
        }
        else
            printf("Passed. \n");
    }
    else
        printf("Failed. \n");
}

void Test1()
{
    int data[] = {1, 2, 4, 7, 11, 15};
    Test("Test1", data, sizeof(data) / sizeof(int), 15, true);
}

void Test2()
{
    int data[] = {1, 2, 4, 7, 11, 16};
    Test("Test2", data, sizeof(data) / sizeof(int), 17, true);
}

void Test3()
{
    int data[] = {1, 2, 4, 7, 11, 16};
    Test("Test3", data, sizeof(data) / sizeof(int), 10, false);
}

void Test4()
{
    Test("Test4", NULL, 0, 0, false);
}

int main()
{
    Test1();
    Test2();
    Test3();
    Test4();

    return 0;
}
