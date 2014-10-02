#include <stdio.h>
#include <stdlib.h>

#define MAX 100
#define SIZE 10

/* qsort函数的比较函数 */
int cmp(const void *a, const void *b) 
{
    return *(int *)a - *(int *)b;
}

/* 求3个数的min */
int min(int a, int b, int c)
{
    int m = a;
    if (b < m)
        m = b;
    else if (c < m)
        m = c;
    return m;
}

struct pair {           /* 点对     */
    int distance;       /* 两点距离 */
    int x1, x2;         /* 两点坐标 */
};

/* 返回pair结构的函数Cpair,对于数组a的点，返回最接近点和距离 */
struct pair Cpair(int a[], int low, int high)
{
    int median, distance, p, q, m, i;
    struct pair final;    /* 最终输出的点对，先进行初始化 */
    final.distance = MAX;
    final.x1 = 0;
    final.x2 = 0;
    
    struct pair S1, S2;
 
    if (low >= high) 
        return final;
 
    median = (low + high) / 2;
    S1 = Cpair(a, low, median);     
    S2 = Cpair(a, median+1, high);   

    p = a[median];                  /* max(S1) */
    q = a[median+1];                /* min(S2) */
    
    distance = min(S1.distance, S2.distance, q-p);
    if (S1.distance == distance)
        return S1;
    if (S2.distance == distance)
        return S2;
    else {
        final.distance = distance;
        final.x1 = p;
        final.x2 = q;
        return final;
    }
    
}

int main(int argc, char *argv[])
{
    int a[SIZE], i, j;
    for (i = 0; i < SIZE; i++) {
        a[i] = (rand()+i) % 100;
        for (j = 0; j < i; j++) {
            if (a[j] == a[i]) {
                a[i] = rand() % 100;
                break;
            }
        }
    }
    qsort(a, SIZE, sizeof(a[0]), cmp);
    printf("%d random numbers: ", SIZE);
    for(i = 0; i < SIZE; i++)
        printf("%d ", a[i]);
    printf("\n");
   
    struct pair final_pair = Cpair(a, 0, SIZE-1);
    printf("pair: <%d, %d>, distance: %d\n",  final_pair.x1, final_pair.x2, final_pair.distance);
    

    return 0;
}

