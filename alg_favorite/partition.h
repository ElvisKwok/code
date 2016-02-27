#include <cstdlib>
#include <ctime>
#include <exception>
using namespace std;

int randomInRange(int min, int max) {
    srand(time(NULL));
    int random = rand() % (max-min+1) + min;
    return random;
}

// 算法导论版本
// 先把pivot的值放在high， 然后遍历low到high-1，遇到比pivot小的放在small+1的位置
// 最终low~small区间都是比pivot小的
int partition(int data[], int length, int low, int high) {
    if (data == NULL || length <= 0 || low < 0 || high-low >= length)
        throw new exception();  // invalid parameters
    int pivot = randomInRange(low, high);   // pivot原始位置
    swap(data[pivot], data[high]);
    int small = low - 1;
    for (int i = low; i < high; ++i) {
        if (data[i] < data[high]) {
            ++small;
            if (small != i)
                swap(data[small], data[i]);
        }
    }
    // 此时
    // [low, small] 都小于pivot
    // [small+1, high-1] 都大于pivot
    pivot = small+1;        // 划分后pivot位置
    swap(data[pivot], data[high]);
    return pivot;
}
