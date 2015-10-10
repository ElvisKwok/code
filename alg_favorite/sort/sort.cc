using std::vector;

template <typename Type>
const Type& median3(vector<Type> &vec, int left, int right)
{
    int center = (left + right) / 2;
    if (vec[center] < vec[left])
        swap(vec[center], vec[left]);
    if (vec[right] < vec[left])
        swap(vec[left], vec[right]);
    if (vec[right] < vec[center])
        swap(vec[center], vec[right]);
    swap(vec[center], vec[right-1]);
    return vec[right-1];
}

// 堆调整, 大顶堆 
template <typename Type>
void filterDown(vector<Type> &vec, int i, int n)
{
    int child;
    Type tmp;
    for (tmp = vec[i]; 2*i+1 < n; i = child) {          // 每次迭代后，i变成被"掏空"的child
        child = 2*i+1;
        if (child != n-1 && vec[child] < vec[child+1])  // 选较大的child进行比较
            child++;

        if (tmp < vec[child]) {
            vec[i] = vec[child];
        } else {
            break;
        }
    }
    vec[i] = tmp;   // for初始值tmp一直不变，这里的i可能是原始i，也可能是被“掏空”的child
}

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

    delte []tmp;

}


template <typename Type>
void insertSort(vector<Type> &vec, int left, int right) 
{
    for (int p = left+1; p <= right; ++p) {
        Type tmp = vec[p];
        int j;
        for (j = p; (j > left) && (tmp < vec[j-1]); --j)
            vec[j] = vec[j-1];
        vec[j] = tmp;
    }
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

template <typename Type>
void quickSort(vector<Type> &vec, int left, int right) 
{
    int cutoff = 5;
    if (right - left >= cutoff) {
        Type pivot = median3(vec, left, right);    
        int low = left, high = right-1;
        for ( ; ; ) {
            while (vec[++low] < pivot) { }
            while (vec[--high] > pivot) { }
            if (low < high)
                swap(vec[low], vec[high]);
            else
                break;
        }
        swap(vec[low], vec[right-1]);
        quickSort(vec, left, low-1);
        quickSort(vec, low+1, right);
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

template <typename Type>
void heapSort(vector<Type> &vec, int left, int right) 
{
    int n = right - left + 1;
    vector<Type> tmp(n);
    for (int i = 0; i < n; ++i)
        tmp[i] = vec[left+i];

    for (int i = n/2; i >= 0; --i)  // 从第一个非叶子节点开始，进行"初始"堆调整
        filterDown(tmp, i, n);
    for (int j = n-1; j > 0; --j) {
        swap(tmp[0], tmp[j]);       // 当前子序列最大值，放到末尾
        filterDown(tmp, 0, j);      // 每次输出最大值后，再调整
    }

    for (int i = 0; i < n; ++i)
        vec[left+i] = tmp[i];
}

template <typename Type>
void mergeSort(vector<Type> &vec, int left, int right) 
{

}
