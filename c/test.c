#include <stdio.h>
#include <stdlib.h>

#define MAX_Length 100;

//点对结构体
typedef struct Point {
    float d;//点对距离
    float x1,x2;//点对坐标
} Pair;

int input(float s[]);//构造S
Pair Cpair(float s[],int left,int right);

int main()
{
    int m;
    float s[100];
    Pair d;
    m=input(s);
    d=Cpair(s,0,m-1);
    printf("%f", d.d);
    //cout<<endl<<"最近点对坐标为： (d1:"<<d.x1<<",d2:"<<d.x2<<")";
    //cout<<endl<<"这两点距离为： "<<d.d<<endl;
    return 0;
}
int input(float s[])
{
    int length, cum, i;
    printf("input length:");
    scanf("%d",&length);
    for(i=0; i < length; i++) {
        scanf("%d", &cum);
        s[i]=cum;
    }
    return length;
}

//返回s[]中的具有最近距离的点对及其距离
Pair Cpair(float s[],int left,int right)
{
    Pair min_d= {99999,0,0}; //最短距离
    Pair d1, d2;
    float p, q;

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

    d1=Cpair(s,left,j);
    d2=Cpair(s,j+1,right);

    p=s[j],q=s[j+1];

    //返回s[]中的具有最近距离的点对及其距离
    if(d1.d<d2.d)
    {
        if((q-p)<d1.d)
        {
            min_d.d=(q-p);
            //min_d.x1=q;
            // min_d.x2=p;
            return min_d;
        }
        else return d1;
    }
    else
    {
        if((q-p)<d2.d)
        {
            min_d.d=(q-p);
            // min_d.x1=q;
            //    min_d.x2=p;
            return min_d;
        }
        else return d2;
    }
}
