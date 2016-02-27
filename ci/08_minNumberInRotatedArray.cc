#include <iostream>
#include <exception>
using namespace std;

// file description:
// find min num in rotated array
// a rotated array is a rotated increasing sequence which smaller part is move to the end.
// note that an increasing sequence itself is a rotated array as well.
// solution: a transforming version of binary search O(logN)

// noted that this algorithm is unavailable when index1, index2, and indexMid is equal.
// eg. 1 0 1 1 1 (indexMid should belong to 2nd part)
//     *   *   *
// eg. 1 1 1 0 1 (indexMid should belong to 1st part)
//     *   *   *
// but former algorithm all assign indexMid to 1st part
// in this case, a full sequential search is needed. O(N)

int minSequentialSearch(int* nums, int index1, int index2);

int minBinarySearch(int* nums, int length) {
    if (nums == NULL || length <= 0)
        throw new exception();
    int index1 = 0;
    int index2 = length-1;
    int indexMid = 0;   // default as 0, work when rotated array itself is an increasing sequence
    while (nums[index1] >= nums[index2]) {
        // 若index1和index2相邻
        // 则index1指向第一个递增子数组的最后一个数字
        // index1指向第二个子数组的第一个数字，也就是min
        if (index1 + 1 == index2) {
            indexMid  = index2;
            break;
        }
        indexMid = index1 + (index2-index1)/2;
        // index1, index2, indexMid is equal
        if (nums[index1] == nums[index2] && nums[index1] == nums[indexMid])
            return minSequentialSearch(nums, index1, index2);
        if (nums[indexMid] >= nums[index1])
            index1 = indexMid;
        else if (nums[indexMid] <= nums[index2])
            index2 = indexMid;
    }
    return nums[indexMid];
}


int minSequentialSearch(int* nums, int index1, int index2) {
    int result = nums[index1];
    for (int i = index1; i <= index2; ++i) {
        if (result > nums[i])
            result = nums[i];
    }
    return result;
}

// =====================Test Code=====================
void test(int* nums, int length, int expected) {
    int result = 0;
    try {
        result = minBinarySearch(nums, length);
        for (int i = 0; i < length; ++i)
            cout << nums[i] << " ";
        if (result == expected)
            cout << "\tpassed." << endl;
        else
            cout << "\tfailed." << endl;
    } catch (...) {
        if (nums == NULL)
            cout << "test passed." << endl;
        else
            cout << "test failed." << endl;
    }
}

int main() {
    // 普通输入
    int a1[] = {3, 4, 5, 1, 2};
    test(a1, sizeof(a1)/sizeof(int), 1);

    // 含重复元素, 则该元素最小
    int a2[] = {3, 4, 5, 1, 1, 2};
    test(a2, sizeof(a2)/sizeof(int), 1);

    // 含重复元素, 则该元素不是最小
    int a3[] = {3, 4, 5, 1, 2, 2};
    test(a3, sizeof(a3)/sizeof(int), 1);

    // 含重复元素, 则该元素刚好是首尾元素
    int a4[] = {1, 0, 1, 1, 1};
    test(a4, sizeof(a4)/sizeof(int), 0);

    // 旋转0个元素
    int a5[] = {1, 2, 3, 4, 5};
    test(a5, sizeof(a5)/sizeof(int), 1);

    int a6[] = {2};
    test(a6, sizeof(a6)/sizeof(int), 2);

    // NULL
    test(NULL, 0, 0);
    return 0;
}
