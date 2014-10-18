#include <stdio.h>

const int MaxVal = 9999;

const int n = 5;            /* 关键字个数 */

/* 关键字k[i]的概率数组, 关键字个数=n */
/* i范围1~n, p[0]不存在，记为负数-1 */
double p[n + 1] = {-1, 0.15, 0.1, 0.05, 0.1, 0.2};

/* 虚拟结点d[j]概率数组，虚拟结点个数=n+1 */
/* j范围0~n, 因为对于一个“关键字叶子结点”k[i],左右子女分别为虚拟结点d[i-1],d[i] */
double q[n + 1] = {0.05, 0.1, 0.05, 0.05, 0.05, 0.1};  

int root[n+1][n+1];     /* root[i][j]表示关键字{k[i],k[i+1],...,k[j]}对应的子树的根节点位置 */
double w[n+2][n+2];     /* 子树的概率总和, 第一维下标1~n+1，第二维下标0~n */
double e[n+2][n+2];     /* 子树的期望搜索代价 */


void OptimalBST(double *p, double *q, int n)
{
    int i, j, k, len;

    /* 初始化只包含虚拟结点的子树 */
    for (i = 1; i <= n+1; i++) {
        w[i][i-1] = q[i-1];
        e[i][i-1] = q[i-1];
    }
    
    /* 下列3行为计算顺序的控制，类似矩阵连乘问题, 从左到右按照反对角线方向 */
    /* 这是因为计算e[i][j]时，需要先计算e[i][k-1]和e[k+1][j]，其中i≤k≤j */
    for (len = 1; len <= n; len++) {        /* 反对角线方向，当前列入考虑的关键字个数len */
        for (i = 1; i <= n-len+1; i++) {    /* 横坐标i, 给定关键字个数len，对于每一个关键字起始位置i，其总体位置变化范围为i~n-len+1*/
            j = i + len -1;                 /* 纵坐标j，给定对角线和横坐标i，可唯一确定纵坐标j */
            e[i][j] = MaxVal;
            w[i][j] = w[i][j-1] + p[j] + q[j];
            for (k = i; k <= j; k++) {      /* 求解最小搜索代价e[i][j]，并将根k保存到root[i][j], 细分到每一次求解，关键字的根k的位置上限是j */
                double tmp = e[i][k-1] + e[k+1][j] + w[i][j];
                if (tmp < e[i][j]) {
                    e[i][j] = tmp;
                    root[i][j] = k;
                }
            }
        }
    }
}

/* 打印关键字{k[i], k[i+1],...,k[j]}对应的子树，其中，r为根 */
void print_preorder(int i, int j)
{
    int childRoot = root[i][j];

    if (j < i-1)
        return;

    if (j == i-1) {       /* 虚拟结点 */
        printf("# ");
        return;
    }

    else                 /* 关键字 */
        printf("k[%d] ", childRoot);

    print_preorder(i, childRoot-1);
    print_preorder(childRoot+1, j);
}


int main(int argc, char *argv[])
{
    OptimalBST(p, q, n);
    print_preorder(1, n); 
    printf("\n");
    return 0;
}
