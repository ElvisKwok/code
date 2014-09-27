#include <stdio.h>
#include <stdlib.h>

#define MAX_Length 10;
#define MAX 1000000;

//点对结构体
typedef struct Point {
    float d;//点对距离
    float x1,x2;//点对坐标
} Pair;


/* qsort函数的比较函数 */
float cmp(const void *a, const void *b) 
{
    return *(float *)a - *(float *)b;
}

//返回s[]中的具有最近距离的点对及其距离
Pair Cpair(float s[],int left,int right)
{
    Pair min_d= {MAX,0,0}; //最短距离

    if(right-left<1) return min_d;
    float m1=s[left],m2=s[right];
    float m=(m1+m2)/2;//找出点集中的中位数
    int j,i;
    for(i=left; i < right; i++)
        if(s[i]<=m&&s[i+1]>m)
        {
            j=i;
            break;
        }
    Pair d1=Cpair(s,left,j),d2=Cpair(s,j+1,right);//递归
    float p=s[j],q=s[j+1];

    //返回s[]中的具有最近距离的点对及其距离
    if(d1.d<d2.d)
    {
        if((q-p)<d1.d)
        {
            min_d.d=(q-p);
            min_d.x1=q;
            min_d.x2=p;
            return min_d;
        }
        else return d1;
    }
    else
    {
        if((q-p)<d2.d)
        {
            min_d.d=(q-p);
            min_d.x1=q;
            min_d.x2=p;
            return min_d;
        }
        else return d2;
    }
}


int main()
{
    
    float a[MAX_Length];
    int i;
    for (i = 0; i < MAX_Length; i++)
        a[i] = rand()%100;
    qsort(a, MAX_Length, sizeof(a[0]), cmp);
    for(i = 0; i < MAX_Length; i++)
        printf("%f\n", a[i]);
   

    Pair d;
    d=Cpair(a,0,MAX_Length-1);
    printf("最近点对坐标为：<%f,%f>", d.x1, d.x2);
    printf("这两点距离为： %f", d.d);
    return 0;
}





