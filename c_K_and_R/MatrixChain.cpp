#include<iostream>
 using namespace std;
 const int MAX = 100;
//p用来记录矩阵的行列，main函数中有说明
//m[i][j]用来记录第i个矩阵至第j个矩阵的最优解
//s[][]用来记录从哪里断开的才可得到该最优解
int p[MAX+1],m[MAX][MAX],s[MAX][MAX];
int n;//矩阵个数

void matrixChain(){
    for(int i=1;i<=n;i++)m[i][i]=0;

    for(int r=2;r<=n;r++)//对角线循环
        for(int i=1;i<=n-r+1;i++){//行循环
            int j = r+i-1;//列的控制
            //找m[i][j]的最小值，先初始化一下，令k=i
            m[i][j]=m[i][i]+m[i+1][j]+p[i-1]*p[i]*p[j];
            s[i][j]=i;
            //k从i+1到j-1循环找m[i][j]的最小值
            for(int k = i+1;k<j;k++){
                int temp=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
                if(temp<m[i][j]){
                    m[i][j]=temp;
                    //s[][]用来记录在子序列i-j段中，在k位置处
                    //断开能得到最优解
                    s[i][j]=k;
                }
            }
        }
}

//根据s[][]记录的各个子段的最优解，将其输出
void traceback(int i,int j){
    if(i==j)return ;

    traceback(i,s[i][j]);
    traceback(s[i][j]+1,j);
    cout<<"Multiply A"<<i<<","<<s[i][j]<<"and A"<<s[i][j]+1<<","<<j<<endl;
}

int main(){
    int n=6;
    cout<<"intput 6 30 15 5 10 20 35"<<endl;
    for(int i=0;i<=n;i++)cin>>p[i];
    //测试数据可以设为六个矩阵分别为
    //A1[30*35],A2[35*15],A3[15*5],A4[5*10],A5[10*20],A6[20*25]
    //则p[0-6]={30,35,15,5,10,20,25}
    //输入：6 30 35 15 5 10 20 25
    matrixChain();

    traceback(1,n);
    //最终解值为m[1][n];
    cout<<m[1][n]<<endl;
    return 0;
}
