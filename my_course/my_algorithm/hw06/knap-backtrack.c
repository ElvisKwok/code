#include <stdio.h>

#define MAX 100

int n;                          /* 物品数 n */
double c;                       /* 背包容量 content */
double w[MAX];                  /* 每个物品重量 weight */
double v[MAX];                  /* 每个物品价值 value */
double cw = 0;                  /* 当前背包内物品重量 current weight */
double cv = 0;                  /* 当前背包内物品价值 current value */
double bestv = 0;               /* 当前最优价值 best value */
double v_per_w[MAX];            /* 单位重量价值 */
int id[MAX];                    /* 物品编号id */
int put[MAX];                   /* 是否装入物品i */
int search_count_bound = 0;     /* 有界限算法的搜索量 */
int search_count_unbound = 0;   /* 无界限算法的搜索量 */

/* 按照单位重量价值排序以下数组：v_per_w, v, w, id */
void sort_by_value_per_weight()
{
    int i, j;
    double double_temp;
    int int_temp;

    for (i = 1; i <= n; i++)
        v_per_w[i] = v[i] / w[i];
    
    /* simple selecting sort */
    for (i = 1; i <= n-1; i++) {
        for (j = i+1; j <= n; j++) {
            if (v_per_w[i] < v_per_w[j]) {
                double_temp = v_per_w[i];
                v_per_w[i] = v_per_w[j];
                v_per_w[j] = double_temp;

                double_temp = v[i];
                v[i] = v[j];
                v[j] = double_temp;

                double_temp = w[i];
                w[i] = w[j];
                w[j] = double_temp;

                int_temp = id[i];
                id[i] = id[j];
                id[j] = int_temp;
            }
        }
    } 
}

/* 计算上界 */
double bound(int i) {
    double cleft = c - cw;      /* 剩余容量 */
    double b = cv;
    /* 按照物品单位重量价值递减次序装入物品 */
    while (i <= n && w[i] <= cleft) {
        cleft -= w[i];
        b += v[i];
        i++;
    }
    /* 装满背包 */
    if (i <= n)
        b += v[i] * (cleft / w[i]);
    return b;
}

/* 有界限的回溯函数 */
void backtrack_bound(int i)
{
    search_count_bound++;
    if (i > n) {                /* 到达叶节点 */
        bestv = cv;
        return ;
    }
    if (cw + w[i] <= c) {       /* 进入左子树 */
        cw += w[i];
        cv += v[i];
        put[i] = 1;
        backtrack_bound(i+1);
        cw -= w[i];
        cv -= v[i];
    }
    if (bound(i+1) > bestv) {   /* 进入右子树(有可能包含最优解) */
        put[i] = 0;
        backtrack_bound(i+1);
    }
}

/* 无界限的回溯函数 */
void backtrack_unbound(int i)
{
    search_count_unbound++;
    if (i > n) {                /* 到达叶节点 */
        if (bestv < cv)
            bestv = cv;
        return ;
    }
    if (cw + w[i] <= c) {       /* 进入左子树 */
        cw += w[i];
        cv += v[i];
        put[i] = 1;
        backtrack_unbound(i+1);
        cw -= w[i];
        cv -= v[i];
    }
    /* 进入右子树 */
    put[i] = 0;
    backtrack_unbound(i+1);
    
}
    

int main(int argc, char *argv[])
{
    int i;
    int choose;
    printf("选择测试数据1或2：");
    scanf("%d", &choose);
    if (choose == 1) {
        n = 3;
        c = 50;
        w[1] = 30;
        w[2] = 20;
        w[3] = 10;
        v[1] = 120;
        v[2] = 100;
        v[3] = 60;
    } else {
        n = 4;
        c = 7;
        w[1] = 3;
        w[2] = 5;
        w[3] = 2;
        w[4] = 1;
        v[1] = 9;
        v[2] = 10;
        v[3] = 7;
        v[4] = 4;
    }
    printf("物品数量 = %d\n", n);
    printf("背包容量 = %lf\n", c);
    for (i = 1; i <= n; i++) {
        printf("第%d个物品重量 = %lf, 价值 = %lf\n", i, w[i], v[i]);
        id[i] = i;
    }

    sort_by_value_per_weight();
    
    printf("\n以下是有界限算法的结果：\n");
    backtrack_bound(1);
    printf("最优价值为：%lf\n", bestv);
    printf("需要装入的物品编号是：");
    for (i = 1; i <= n; i++) {
        if (put[i] == 1)
            printf("%d ", id[i]);
    }
    printf("\n搜索量：%d\n", search_count_bound);
    
    cw = 0;
    cv = 0;
    bestv = 0;
    for (i = 1; i <= n; i++)
        put[i] = 0;
    printf("\n以下是无界限算法的结果：\n");
    backtrack_unbound(1);
    printf("最优价值为：%lf\n", bestv);
    printf("搜索量：%d\n", search_count_unbound);

    return 0;
}
