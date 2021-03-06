// 返回数组第k小的元素
// 线性时间选择SELECT

// 额外知识：
/*
 Top K: 寻找最大的k个数
 解法一：快排，遍历输出前k个
         O(N*logN+k) = O(NlogN)
 解法二：快排的改进
         RANDOMIZED-SELECT，随机选取一个数组元素作为pivot，划分成Sa和Sb两个子数组。
         1. 如果Sa元素个数>k, 则返回Sa中较小的K个元素
         2. 如果Sa元素个数<k，则返回Sa所有元素 + Sb中k-|Sa|个元素
         递归本函数
         线性期望时间O(N) （平均）
         median3的pivot也是平均O(N)
 解法三：N/5个5元组，中位数的中位数作为pivot，若N>75, 则每次能将两个子数组分别缩短1/4，
         O(N) （最坏情形下）
 解法四：堆：(堆、红黑树)由于STL中set和multiset都是基于红黑树实现，详见kLeastNumber.cc文件
         法1): 建立一个k堆，n-k次比较
         维护K个元素的最小堆（堆顶元素k个中最小）。读入k个数，假设它们是Top K，建堆费时O(k)。
         每次遍历一个元素，与堆顶比较，若大于堆顶，更新堆（淘汰堆顶），费时O(logk)
         O(k+(N-k)logk) = O(Nlogk)
         法2): 建立一个N元素堆，k次DeleteMin
         BuildHeap最坏情形O(N)，每次DeleteMin用时O(logN)
         总运行时间O(N+klogN)，若k=O(N/logN)，则总O(N)；对于大的k值，运行时间O(klogN)；如果k=N/2，总O(NlogN)
 解法五：计数排序O(N)，需申请空间。
 */

 #include<iostream>
 #include <vector>
 using namespace std;

 const int num_array = 13;
 const int num_med_array = num_array / 5 + 1;
 int array[num_array];
 int median_array[num_med_array];

 void insert_sort(int array[], int left, int N) {
    for (int j = left+1; j < N; j++) {
        int i, key = array[j];
        for (i=j; i > left && array[i-1] > key; i--) 
            array[i] = array[i-1];
        array[i] = key;
    }
}

int find_median(int array[], int left, int right) {
    if (left == right)
        return array[left];
    
    int index;
    for (index = left; index < right-5; index += 5) {       // O(N)
        insert_sort(array, index, 5);                       // O(1)
        int num = index - left;
        median_array[num/5] = array[index+2];
    }

    // 处理N%5个剩余元素    // O(1)
    int remain_num = right - index + 1;
    if (remain_num > 0) {
        //insert_sort(array, index, remain_num);
        insert_sort(array, index, right);
        int num = index - left;
        median_array[num/5] = array[index + remain_num/2];
    }
    
    // elem_aux_array: 中位数数组的下标(last)
    //int elem_aux_array = (right - left) / 5 - 1;
    int elem_aux_array = (right - left + 1) / 5 - 1;    // 5的倍数（完整）部分下标
    //if ((right - left) % 5 != 0)
    if ((right - left + 1) % 5 != 0)                    // 是否有多出
        elem_aux_array++;

    if (elem_aux_array == 0)
        return median_array[0];
    else
        return find_median(median_array, 0, elem_aux_array);    // 中位数的中位数
        // 这里对N/5个中位数递归调用“选择算法”O(N)。不能采用排序后返回中间元素的做法O(NlogN)
}

int find_index(int array[], int left, int right, int median) {
    for (int i = left; i <= right; ++i) {
        if (array[i] == median)
            return i;
    }
    return -1;
}

int q_select(int array[], int left, int right, int k) {
    int median = find_median(array, left, right);
    int index = find_index(array, left, right, median);

    swap(array[index], array[right]);
    
    int pivot = array[right];

    // 一次快排的划分
    int i = left;
    int j = right-1;
    while (true) {
        while (array[i] < pivot)
            i++;
        while (array[j] > pivot)
            j--;
        if (i < j)
            swap(array[i], array[j]);
        else
            break;
    }
    swap(array[i], array[right]);

    int m = i - left + 1;
    if (m == k)
        return array[i];
    else if (m > k)
        return q_select(array, left, i-1, k);
    else
        return q_select(array, i+1, right, k-m);
}

int main() 
{
    int array[num_array] = {0, 45, 78, 55, 47, 4, 10, 2, 7, 8, 96, 36, 45};
    int k = 8;
    cout << "the " << k << "th num is: ";
    cout << q_select(array, 0, num_array-1, k) << endl;
    int a[num_array] = {0, 45, 78, 55, 47, 4, 10, 2, 7, 8, 96, 36, 45};
    vector<int> vec(a, a+sizeof(a)/sizeof(int));
    sort(vec.begin(), vec.end());
    for (int i=0; i<vec.size(); ++i)
        cout << vec[i] << "  ";
    cout << endl;
    return 0;
}
