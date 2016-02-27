#include <cstdlib>
#include <ctime>
#include <exception>
using namespace std;

int randomInRange(int min, int max) {
    srand(time(NULL));
    int random = rand() % (max-min+1) + min;
    return random;
}

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
    pivot = small+1;        // 划分后pivot位置
    swap(data[pivot], data[high]);
    return pivot;
}
