/* 
 * 1. insertSort
 * 2. shellSort
 * 3. bubbleSort (from right to left, from left to right)
 * 4. quickSort  (original, improved using median3() and cutoff) (with partition())
 * 5. selectSort
 * 6. heapSort   (with filterDown())
 * 7. mergeSort  (with merge())
 * 8. countingSort
 * 9. radixSort
 * 10. bucketSort
 */
//#include <algorithm>    // swap
using std::vector;
using std::swap;

// 严版1
template <typename Type>
void insertSort(vector<Type> &vec, int left, int right) 
{
    for (int i = left+1; i <= right; ++i) {
        if (vec[i] < vec[i-1]) {
            Type tmp = vec[i];  // 复制为哨兵，储存待排序元素&&判断数组边界
            int j = i - 1;
            while ((j >= left) && (tmp < vec[j])) {
                vec[j+1] = vec[j];
                --j;
            }
            vec[j+1] = tmp;     // --j后，要把j+1
        }
    }
}

// 严版2同1
//template <typename Type>
//void insertSort(vector<Type> &vec, int left, int right) 
//{
//    for (int i = left+1; i <= right; ++i) {
//        Type tmp = vec[i];  // 复制为哨兵，储存待排序元素&&判断数组边界
//        int j;
//        for (j = i; (j > left) && (tmp < vec[j-1]); --j)
//            vec[j] = vec[j-1];
//        vec[j] = tmp;
//    }
//}


template <typename Type>
void shellInsertSort(vector<Type> &vec, int len, int step) 
{
    for (int i = step; i < len; ++i) {  // 注意：这里i从step开始，不是从left+1开始
        if (vec[i] < vec[i-step]) {
            Type tmp = vec[i];
            int j = i - step;
            while ((j >= 0) && (tmp < vec[j])) { // 注意：j不能越界, j>=0要放前面, 不然vec[j]访问出错（vec[负数下标]）
            //while ((tmp < vec[j]) && (j >= 0)) { // error:段错误，核心已转储
                vec[j+step] = vec[j];
                j -= step;
            }
            vec[j+step] = tmp;
        }
    }
}

/* step = {n/2, n/4, ... , 1}
 * 使用直接插入排序对子序列排序
 */
template <typename Type>
void shellSort(vector<Type> &vec, int left, int right) 
{
    int len = right-left+1;
    int step;
    for (step = len/2; step >= 1; step /= 2)
        shellInsertSort(vec, len, step);
}


//template <typename Type>
//void bubbleSort(vector<Type> &vec, int left, int right) 
//{
//    bool swaped;
//    for (int i = left; i < right; ++i) {
//        swaped = false;
//        for (int j = right; j > i; --j) {
//        // from right to left version, smaller up.
//            if (vec[j] < vec[j-1]) {
//                swap(vec[j], vec[j-1]);
//                swaped = true;
//            }
//        }
//        if (!swaped)
//            return;
//    }
//}

/* 可改进的地方：
 * 正向反向同时找（最大最小），使得趟数几乎减少一半。
 * 注意：while(low<high)，正向之后--high,反向之后++low
 */
template <typename Type>
void bubbleSort(vector<Type> &vec, int left, int right) 
{
    bool swaped;
    for (int i = right; i > left; --i) {
        swaped = false;
        for (int j = left; j < i; ++j) {
        // from left to right version, bigger down.
            if (vec[j] > vec[j+1]) {
                swap(vec[j], vec[j+1]);
                swaped = true;
            }
        }
        if (!swaped)
            return;
    }
}

//// 算法导论版partition改版
//template <typename Type>
//int partition(vector<Type> &vec, int left, int right)
//{
//    Type pivot = vec[left];
//    int i = left;
//    for (int j = left+1; j <= right; ++j) {
//        if (vec[j] <= pivot) {
//            i++;
//            swap(vec[i], vec[j]);
//        }
//    }   // for循环结束后，index<=i的元素都<=pivot
//    swap(vec[i], vec[left]);  // 交换，把pivot放到i的位置 
//    return i; // 返回交换后的pivot位置
//}    

//// 严版partition
///* 可改进的地方:
// * 1. pivot的选取，数组元素随机选一个（产生随机数也有开销），更好的是median3
// * 2. 降低swap次数，当(vec[left]>pivot)&&(vec[right]<pivot)时再进行swap
// * 3. cutoff（大于2），数组长度<cutoff值时，采用插入排序（小数组的"插排"比"快排"快）
// */
//template <typename Type>
//int partition(vector<Type> &vec, int left, int right)
//{
//    Type pivot = vec[left];
//    while (left < right) {
//        while ((left < right) && (vec[right] >= pivot))
//            --right;
//        swap(vec[left], vec[right]);
//        while ((left < right) && (vec[left] <= pivot))
//            ++left;
//        swap(vec[left], vec[right]);
//    }
//    return left;
//}
//
//// original quickSort
//template <typename Type>
//void quickSort(vector<Type> &vec, int left, int right) 
//{
//    if (left < right) {
//        int q = partition(vec, left, right);
//        quickSort(vec, left, q-1);
//        quickSort(vec, q+1, right);
//    }
//}


template <typename Type>
const Type& median3(vector<Type> &vec, int left, int right)
{
    int center = (left + right) / 2;
    if (vec[center] < vec[left])
        swap(vec[center], vec[left]);
    if (vec[right] < vec[left])
        swap(vec[left], vec[right]);    // left <- min
    if (vec[right] < vec[center])       
        swap(vec[center], vec[right]);  // right <- max
    // 以上代码使得left < center < right

    swap(vec[center], vec[right-1]);    // right肯定比center大，不参与排序比较，把right-1扔到前面
    return vec[right-1];                // return original median of 3 nums.
}

template <typename Type>
int partition(vector<Type> &vec, int left, int right)
{
    Type pivot = median3(vec, left, right);    
    
    int i = left, j = right-1; // begin partitioning
    while(true) {
        /* 分别找出第一个比pivot大的i，第一个比pivot小的j
         * 在median3函数中，已经使得(i<pivot)，不参与比较
         * 也使(right>pivot,right-1==pivot)，也不参与比较
         * 左端从i+1开始(即++i)
         * 右端从pivot-1(即pivot前一位置,j-1,right-2)开始(即--j)
         */
        // 降低original version的swap次数
        while (vec[++i] < pivot) { }  
        while (vec[--j] > pivot) { } 
        if (i < j)
            swap(vec[i], vec[j]);
        else
            break;
    }
    // restore pivot(right-1)，放到当前i的位置(>=j的第一个比pivot大的位置)
    swap(vec[i], vec[right-1]);   
    return i;
}

// improved quickSort
// Uses median-of-three partitioning and a cutoff of 5;
template <typename Type>
void quickSort(vector<Type> &vec, int left, int right) 
{
    int cutoff = 5;
    if (right - left >= cutoff) {
        int q = partition(vec, left, right);
        // recursive calls
        quickSort(vec, left, q-1);    // sort small elements
        quickSort(vec, q+1, right);   // sort large elements
    }
    else
        insertSort(vec, left, right);
}


template <typename Type>
void selectSort(vector<Type> &vec, int left, int right) 
{
    Type minPos;
    for (int i = left; i < right; ++i) {
        minPos = i;
        for (int j = i + 1; j <= right; ++j) {
            if (vec[j] < vec[minPos])
                minPos = j;
        }
        if (i != minPos)
            swap(vec[i], vec[minPos]); 
    }
}


// 堆调整的“渗透函数”, 大顶堆 
// i是待调整的元素位置
template <typename Type>
void filterDown(vector<Type> &vec, int i, int n)
{
    int child;
    Type tmp = vec[i];
    for ( ; 2*i+1 < n; i = child) {          // 每次迭代后，i变成被"掏空"的child
        child = 2*i+1;      // 注意数组下标0开始，孩子是2i+1和2i+2, 父亲是(i-1)/2
        if (child != n-1 && vec[child] < vec[child+1])  // 选较大的child进行比较
            child++;

        if (tmp < vec[child]) {
            vec[i] = vec[child];    // 与child交换，进行下一次迭代，从被“掏空”的child开始
        } else {
            break;
        }
    }
    vec[i] = tmp;   // 这里的i可能是原始i(不变)，也可能是被“掏空”的child
}

template <typename Type>
void heapSort(vector<Type> &vec, int left, int right) 
{
    int n = right - left + 1;

    // 1. 建立“初始堆”(使用“渗透函数”)
    for (int i = (n-1)/2; i >= 0; --i)  // 从第一个非叶子节点开始，进行"初始"堆调整
        filterDown(vec, i, n);

    // 2. 堆顶与最后一个元素换位，然后调整堆
    for (int j = n-1; j > 0; --j) {
        swap(vec[0], vec[j]);       // 当前子序列最大值，放到末尾
        filterDown(vec, 0, j);      // 每次输出最大值后，再调整
    }
}

//// 网友版：这里tmp是多余的
//template <typename Type>
//void heapSort(vector<Type> &vec, int left, int right) 
//{
//    int n = right - left + 1;
//    vector<Type> tmp(n);
//    for (int i = 0; i < n; ++i)
//        tmp[i] = vec[left+i];
//
//    for (int i = (n-1)/2; i >= 0; --i)  // 从第一个非叶子节点开始，进行"初始"堆调整
//        filterDown(tmp, i, n);
//    for (int j = n-1; j > 0; --j) {
//        swap(tmp[0], tmp[j]);       // 当前子序列最大值，放到末尾
//        filterDown(tmp, 0, j);      // 每次输出最大值后，再调整
//    }
//
//    for (int i = 0; i < n; ++i)
//        vec[left+i] = tmp[i];
//}


template <typename Type>
void merge(vector<Type> &vec, int left1, int right1, int left2, int right2)
{
    int k = 0, i = left1, j = left2, n1 = right1-left1+1, n2 = right2-left2+1;
    Type *tmp = new Type[n1+n2];

    // merge到tmp
    while (i <= right1 && j <= right2)
        if (vec[i] < vec[j])
            tmp[k++] = vec[i++];
        else
            tmp[k++] = vec[j++];
    while (i <= right1)
        tmp[k++] = vec[i++];
    while (j <= right2)
        tmp[k++] = vec[j++];

    // tmp复制回来vec
    for (int i = 0; i < n1; ++i)
        vec[left1++] = tmp[i];
    for (int i = 0; i < n2; ++i)
        vec[left2++] = tmp[n1+i];

    delete []tmp;
}

/* mergeSort的迭代版 */
template <typename Type>
void mergeSort(vector<Type> &vec, int left, int right) 
{
    int left1, left2, right1, right2;
    int n = right - left + 1;   // vec长度
    int size = 1;               // 两个子序列的长度，size不能从2开始，因为第一趟是相邻两两比较
    while (size < n) {
        left1 = left;           // 左起点
        while (left1 + size < n) { // 当前size的子序列1后，还剩下子序列2(长度>=1)
            left2 = left1 + size;
            right1 = left2 - 1;
            if (left2 + size > n)
                right2 = right;             // 不等长的merge
            else
                right2 = left2 + size - 1;  // 等长的merge
            merge(vec, left1, right1, left2, right2);
            left1 = right2 + 1;
        }
        size *= 2;
    }
}

///* mergeSort的recusive version */
//template <typename Type>
//void mergeSort(vector<Type> &vec, int left, int right) 
//{
//    if (left < right) {
//        int mid = (left+right)/2;   // 这里不能用(right-left)/2
//        mergeSort(vec, left, mid);
//        mergeSort(vec, mid+1, right);
//        merge(vec, left, mid, mid+1, right);
//    }
//}

/* input: vec[left,...,right]
 * output_tmp: output_tmp[left,...,right]
 * counting_tmp: counting_tmp[0,...,max_val]
 */
template <typename Type>
void countingSort(vector<Type> &vec, int left, int right) 
{
    int n = right - left + 1;
    vector<Type> output_tmp(n);
    Type max_val = vec[left];
    for (int i = left+1; i <= right; ++i)
        if (vec[i] > max_val)
            max_val = vec[i];
    vector<Type> counting_tmp(max_val+1);        // 注意：这里的size要设为max_val+1，否则会溢出

    for (int i = left; i <= right; ++i)
        ++counting_tmp[vec[i]];                 // 第j元素包含等于j的元素个数
    for (int i = 1; i <= max_val; ++i)          // i<=max_val (size为max_val+1)
        counting_tmp[i] += counting_tmp[i-1];   // 包含<=j的元素个数
    /* 注意：这里countint_tmp[max_val]的值为vec长度（这只是其中一个例子）
     * 但是output_tmp和vec最后一个元素下标应该是vec长度-1（其他值的下标也要对应前移）
     * 又例如：最小的那个值如只出现一次，而它的counting_tmp的值却是1，所以要-1，放到0下标位置
     * 所以，在下面的for循环要先逐个--counting_tmp[vec[i]]
     */
    for (int i = right; i >= left; --i) {
        --counting_tmp[vec[i]];     // 这里有两个作用：1. 下标迁移；2. 保证排序稳定性（相同元素）
        output_tmp[counting_tmp[vec[i]]] = vec[i];
    }

    for (int i = left; i <= right; ++i)
        vec[i] = output_tmp[i];
}
