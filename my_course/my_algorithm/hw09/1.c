/*
 * Solve Traveling Saleman Problem(TSP) by Simulated Annnealing(SA).
 * In this program, there are 20 point, and the saleman start traveling at point 0.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define N 20
#define COUNT_P (N-1)*(N-2)/2

struct point {
    double x;
    double y;
} point[N];

double distance[N][N];          /* 保存欧式距离 */
int tmp_path[N];                /* 当前路径*/
int best_path[N];               /* 最优路径 */
double tmp_dist;                /* 当前路径的长度 */
double best_dist;               /* 最优路径的长度 */
double T_init = 100000000000;        /* 初始温度 */
const double T_min = 1;         /* 终止界限，当T<T_min时，停止搜索 */
const int iter_times = N;       /* 每一个温度的迭代次数*/
const double rate = 0.999999;       /* 温度衰减系数 */

int p[COUNT_P][N];              /* 保存映射 */
int tmp_path_rws[N];            /* rws方法的当前路径 */
int best_path_rws[N];           /* rws方法的最优路径 */
double tmp_dist_rws;            /* rws方法的当前路径的长度 */
double best_dist_rws;           /* rws方法的最优路径的长度 */

void init();
double get_dist(int a[N]);
void new_path(int tmp_path[N]);
void print_path(int tmp_path[N]);
void assign_path(int from[N], int to[N]);
void tsp_sa();

void map();
int rws(int a[COUNT_P][N]);
void tsp_rws();

void init()
{
    srand((unsigned)time(NULL));
    int i, j;
    
    /* 随机生成N个点的坐标<x, y> */
    printf("%d random points are as follows:\n", N);
    for (i = 0; i < N; i++){
        point[i].x = rand()%(N*10);
        point[i].y = rand()%(N*10);
        printf("(%lf,%lf)\n", point[i].x, point[i].y);
    }

    /* 计算点与点之间的距离 */
    for (i = 0; i < N; i++) {
        for (j = i+1; j < N; j++) {
            distance[i][j] = sqrt(pow((point[i].x - point[j].x), 2) + pow((point[i].y - point[j].y), 2));
            distance[j][i] = distance[i][j];
        }
    }
    
    /* 初始化路径 */
    printf("初始路径是：");
    for (i = 0; i < N; i++) {
        best_path[i]  = i;
        tmp_path[i] = i;
        printf("%d->", i);

        best_path_rws[i] = i;
    }
    printf("%d\n", 0);
    best_dist = tmp_dist = get_dist(best_path);
    printf("路径长度是：%lf\n", best_dist);

    best_dist_rws = get_dist(best_path_rws);
    map(best_path_rws);
}

/* 计算当前路径a[N]的路径长度 */
double get_dist(int a[N])
{
    int i;
    double dist;
    for (i = 1; i < N; i++)
        dist += distance[a[i-1]][a[i]];
    dist += distance[a[N-1]][a[0]];
    return dist;
}

/* 生成新的路径，暂存在tmp_path[N]中 */
void newpath(int tmp_path[N]) 
{
    int x, y, t;
    /* 从城市1到N-1中随机挑选两个城市交换 */
    do {
        x = (rand() % (N-1)) + 1;
        y = (rand() % (N-1)) + 1;
    } while (x == y);
    t = tmp_path[x];
    tmp_path[x] = tmp_path[y];
    tmp_path[y] = t;
}

/* 打印当前路径、路径长度 */
void print_path(int tmp_path[N])
{
    int i;
    printf("路径：");
    for (i = 0; i < N; i++)
        printf("%d->", tmp_path[i]);
    printf("%d\n", tmp_path[0]);
    printf("路径长度是：%lf\n\n", tmp_dist);
}

/* 将路径from复制到to */
void assign_path(int from[N], int to[N])
{
    int i;
    for (i = 0; i < N; i++)
        to[i] = from[i];
}

/* 采用模拟退火算法解决tsp问题 */ 
void tsp_sa() 
{
    int i;
    double T = T_init;
    double cur_dist, delta, rand_prob, accept_prob;
    int cur_path[N];
    assign_path(best_path, cur_path);
    cur_dist = best_dist;
    while ( T > T_min) {
        for (i = 0; i < iter_times; i++) {          /* 每一温度下的迭代次数iter_times */
            newpath(tmp_path);
            tmp_dist = get_dist(tmp_path);
//            print_path(tmp_path);                   /* 打印当前路径、路径长度 */
            delta = tmp_dist - cur_dist;
            if (delta < 0) {                        /* 遇到更优解 */
                assign_path(tmp_path, cur_path);
                cur_dist = tmp_dist;
            }
            else {                                  /* 否则，按照metropolis准则接受“差解” */
                rand_prob = (double)rand() / RAND_MAX;  /* Random(0, 1) */
                accept_prob = exp(delta / T);
                if (accept_prob < 1 && accept_prob > rand_prob) {
                    assign_path(tmp_path, cur_path);
                    cur_dist = tmp_dist;
                }
            }
        }
        if (cur_dist < best_dist) {
            best_dist = cur_dist;
            assign_path(cur_path, best_path);
        }
        T = T * rate;                               /* 降低温度 */
    }
}

/* 映射当前路径的邻域 */
void map(int a[N])
{
    int i, j, k, tmp;
    for (i = 0; i < COUNT_P; i++)
        for (j = 0; j < N; j++)
            p[i][j] = a[j];
    for (i = 0; i < COUNT_P;)
        for (j = 1; j < N-1; j++)
            for (k = j+1; k < N; k++) {
                tmp = p[i][j];
                p[i][j] = p[i][k];
                p[i][k] = tmp;
                i++;
            }
}

/* 轮盘赌选择邻域 */
int rws(int a[COUNT_P][N])
{
    int i, random;
    double sum[COUNT_P];
    /* 
    double p;
    p = (double)rand() / RAND_MAX;
    */
    sum[0] = get_dist(p[0]);
    for (i = 1; i < COUNT_P; i++)
        sum[i] = sum[i-1] + get_dist(p[i]);
    random = rand() % (int)sum[COUNT_P-1];
    
    for (i = 0; i < COUNT_P; i++)
        if(random <= sum[i])
            return i;
}

/* 轮盘赌改进TSP问题的局部搜索 */
void tsp_rws() 
{
    int i, j;
    double tmp;
    for (i = 0; i < COUNT_P; i++) {
        tmp = get_dist(p[i]);
        usleep(1);
        //printf("get_dist(p[%d]) = %lf\n", i, tmp);
        if (tmp < best_dist_rws) {
            best_dist_rws = tmp;
            for (j = 0; j < N; j++) {
                best_path_rws[j] = p[i][j];
            }
            map(p[i]);
            break;
         }
    }
    if (i < COUNT_P)
        tsp_rws();
    else {
        return;
    }
}
    
int main(int argc, char *argv[])
{
    int i;
    init();
    tsp_sa();
    printf("\n\n最佳路径是：");
    for (i = 0; i < N; i++)
        printf("%d->", best_path[i]);
    printf("%d\n", best_path[0]);
    printf("最佳长度是：%lf\n", best_dist);

    tsp_rws();
    printf("\n\nrws的最佳路径是:");
    for (i = 0; i < N; i++)
        printf("%d->", best_path_rws[i]);
    printf("%d\n", best_path_rws[0]);
    printf("rws最佳长度是：%lf\n", best_dist_rws);

    return 0;
}
