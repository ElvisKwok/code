#include <stdio.h>

#define POPULATION 4
#define N 8
int group_survive[POPULATION][N] = {{1,2,3,4,5,6,7,8},
                                    {5,2,3,7,1,8,4,6},
                                    {1,2,3,7,5,8,4,6},
                                    {5,2,8,7,1,3,4,6}};
/* 将路径from复制到to */
void assign_path(int from[N], int to[N])
{
    int i;
    for (i = 0; i < N; i++)
        to[i] = from[i];
}


/* 整数编码的常规交配法*/
void crossover()
{
    int i, j, k1, k2, k3, flag = 0;           /* k1为父代1搜索位置，k2为父代2搜索位置，k3为交配后的基因放置位置*/
    int location = N/2;             /* 交配起始位置 */
    int tmp[N];                     /* 暂存以前的父代1(因为生成子代1时会把父代1抹除) */
    for (i = 0; i < POPULATION/2; i++) {
        /* POPULATION/2对个体(j, j+1)，两两交配 */
        j = i * 2;
        assign_path(group_survive[j], tmp);     /* 暂存父代1 */
        /* 产生子代1 */
        for (k2 = 0, k3 = location; k2 < N && k3 < N; ) {
            for (k1 = 0; k1 < k3; k1++) { 
                if (group_survive[j+1][k2] == group_survive[j][k1])
                    flag = 1;
            }
            if (flag = 0)
                group_survive[j][k3++] = group_survive[j+1][k2++];
            else {k2++; flag = 0;}
        }
        /* 产生子代2 */
        /*for (k1 = 0, k3 = location; k1 < N && k3 < N; k3++) {
            for (k2 = 0; k2 < N; k2++) {
                if (tmp[k1] != group_survive[j+1][k2])
                    break;
                else
                    k1++;

            }
            group_survive[j+1][k3] = tmp[k1++];
        }
        */
        for (k1 = 0, k3 = location; k1 < N && k3 < N; ) {
            for (k2 = 0; k2 < k3; k2++) {
                if (tmp[k1] == group_survive[j+1][k2])
                    flag = 1;
            }
            if (flag = 0)
                group_survive[j+1][k3++] = tmp[k1++];
            else {k1++; flag = 0;}
        }
    }
}

int main(int argc, char *argv[])
{
    int i, j;
    printf("原始:\n");
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 8; j++)
            printf("%d ",group_survive[i][j]);
        printf("\n");
    }
    crossover();
    printf("crossover后:\n");
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 8; j++)
            printf("%d ",group_survive[i][j]);
        printf("\n");
    }
    return 0;
}   
