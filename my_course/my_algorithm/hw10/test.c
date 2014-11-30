/*
 * Solve Traveling Saleman Problem(TSP) by Genetic Algorithm(GA).
 * In this program, there are 20 point, and the saleman start traveling at point 0.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define N 20
//#define COUNT_P (N-1)*(N-2)/2

struct point {
    double x;
    double y;
} point[N];

double distance[N][N];          /* 保存欧式距离 */
int tmp_path[N];                /* 当前路径*/
int best_path[N];               /* 最优路径 */
double tmp_dist;                /* 当前路径的长度 */
double best_dist;               /* 最优路径的长度 */
double T_init = 999999;        /* 初始温度 */
const double T_min = 1;         /* 终止界限，当T<T_min时，停止搜索 */
const int iter_times = N;       /* 每一个温度的迭代次数*/
const double rate = 0.99;       /* 温度衰减系数 */

/* rws部分 */
//int p[COUNT_P][N];              /* 保存映射 */
//int tmp_path_rws[N];            /* rws方法的当前路径 */
//int best_path_rws[N];           /* rws方法的最优路径 */
//double tmp_dist_rws;            /* rws方法的当前路径的长度 */
//double best_dist_rws;           /* rws方法的最优路径的长度 */

void init();
double get_dist(int a[N]);
void new_path(int tmp_path[N]);
void print_path(int tmp_path[N]);
void assign_path(int from[N], int to[N]);
void tsp_sa();

/* rws部分 */
//void map();
//int rws(int a[COUNT_P][N]);
//void tsp_rws();

void init()
{
    srand((unsigned)time(NULL));
    int i, j;

    /* 随机生成N个点的坐标<x, y> */
    printf("随机生成如下%d个点:\n", N);
    for (i = 0; i < N; i++) {
        point[i].x = rand()%(N*10);
        point[i].y = rand()%(N*10);
        printf("%d:\t(%.0lf,\t%.0lf)\n", i, point[i].x, point[i].y);
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

//        best_path_rws[i] = i;
    }
    printf("%d\n", 0);
    best_dist = tmp_dist = get_dist(best_path);
    printf("路径长度是：%lf\n", best_dist);

//    best_dist_rws = get_dist(best_path_rws);
//    map(best_path_rws);
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
                accept_prob = exp((-delta) / T);
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

/* rws部分 */
//void map(int a[N])
//{
//    int i, j, k, tmp;
//    for (i = 0; i < COUNT_P; i++)
//        for (j = 0; j < N; j++)
//            p[i][j] = a[j];
//    for (i = 0; i < COUNT_P;)
//        for (j = 1; j < N-1; j++)
//            for (k = j+1; k < N; k++) {
//                tmp = p[i][j];
//                p[i][j] = p[i][k];
//                p[i][k] = tmp;
//                i++;
//            }
//}
//
//int rws(int a[COUNT_P][N])
//{
//    int i;
//    double random_p, prob[COUNT_P], add_prob[COUNT_P], sum, dist[COUNT_P];
//    random_p = (double)rand() / RAND_MAX;
//    for (i = 0; i < COUNT_P; i++) {
//        dist[i] = get_dist(p[i]);
//        sum += dist[i];
//    }
//
//    for (i = 0; i < COUNT_P; i++)
//        prob[i] = (1 - (dist[i] / sum)) / (COUNT_P - 1);
//
//    add_prob[0] = prob[0];
//    for (i = 1; i < COUNT_P; i++)
//        add_prob[i] = add_prob[i-1] + prob[i];
//
//    for (i = 0; i < COUNT_P; i++)
//        if (random_p <= add_prob[i])
//            return i;
//}
//
//
//void tsp_rws()
//{
//    int i, j, random_i, mark[COUNT_P];
//    double tmp;
//    for (i = 0; i < COUNT_P; i++) {
//        random_i = rws(p);
//        /*        while (mark[random_i] == 1);
//                random_i = (random_i + 1) % COUNT_P;
//                        mark[random_i] = 1;
//                        */
//        tmp = get_dist(p[random_i]);
//
//        //usleep(1);
//        //printf("get_dist(p[%d]) = %lf\n", random_i, tmp);
//        if (tmp < best_dist_rws) {
//            best_dist_rws = tmp;
//            for (j = 0; j < N; j++) {
//                best_path_rws[j] = p[random_i][j];
//            }
//            map(p[random_i]);
//            break;
//        }
//    }
//    if (i < COUNT_P)
//        tsp_rws();
//    else {
//        return;
//    }
//}

#define POPULATION  20      /* 种群规模 */
#define PC          0.9     /* 交配概率 */
#define PM          0.01    /* 变异概率 */
#define MAX_ITER    1000    /* 终止条件：迭代次数 */


/* ga部分 */
int tmp_path_ga[N];                 /* ga方法的当前路径 */
int best_path_ga[N];                /* ga方法的最优路径 */
double tmp_dist_ga;                 /* ga方法的当前路径的长度 */
double best_dist_ga;                /* ga方法的最优路径的长度 */
int group[POPULATION][N];           /* 选定的群体 */
int group_survive[POPULATION][N];   /* 存活的种群 */

void init_group();
int rws(int a[POPULATION][N]);
void assign_path(int from[N], int to[N]);
void selection();
void crossover();
void tsp_ga();

/* 初始化群体 */
void init_group()
{
    int i, j, k, temp, flag;
    for (i = 0; i < POPULATION; i++) {
        /* 产生N-1个不同的数字 */
        for (j = 1; j < N; ) {
            temp = (rand() % (N-1)) + 1;
            flag = 1;
            for (k = 1; k < j; k++) {
                if (group[i][k] == temp) {
                    flag = 0;
                    break;
                }
            }
            if (flag == 1) {
                group[i][j] = temp;
                j++;
            }
        }
    }
}

/* 选择的依据：适应度(轮盘赌) */
int rws(int a[POPULATION][N])
{
    int i;
    double random_p, prob[POPULATION], add_prob[POPULATION], sum, dist[POPULATION];
    random_p = (double)rand() / RAND_MAX;
    for (i = 0; i < POPULATION; i++) {
        dist[i] = get_dist(p[i]);
        sum += dist[i];
    }

    for (i = 0; i < POPULATION; i++)
        prob[i] = (1 - (dist[i] / sum)) / (POPULATION - 1);

    add_prob[0] = prob[0];
    for (i = 1; i < POPULATION; i++)
        add_prob[i] = add_prob[i-1] + prob[i];

    for (i = 0; i < POPULATION; i++)
        if (random_p <= add_prob[i])
            return i;
}

/* 根据适应度选择存活的种群(群体=>种群) */
void selection(int a[POPULATION][N])
{
    int i, j, selected;
    for (i = 0; i < POPULATION; i++) {
        selected = rws(group);
        assign_path(group[selected], group_survive[i]);
    }
}

/* 整数编码的常规交配法*/
/* 种群group_survive => 新的群体group */
void crossover()
{
    int i, j, t, k1, k2, k3;        /* k1为父代1搜索位置，k2为父代2搜索位置，k3为交配后的基因放置位置*/
    int location = N/2;             /* 交配起始位置 */
    for (i = 0; i < POPULATION/2; i++) {
        /* POPULATION/2对个体(j, j+1)，两两交配 */
        j = i * 2;
        /* 前面部分直接复制 */
        for (t = 0; t < location; t++) {
            group[j][t] = survive[j][t];
            group[j+1][t] = survive[j+1][t];
        }
        /* 产生子代1 */
        for (k2 = 1, k3 = location; k2 < N && k3 < N; k3++) {
            for (k1 = 1; k1 < location; k1++)
                if (group_survive[j+1][k2] == group[j][k1])
                    k2++;
            group[j][k3] = group_survive[j+1][k2];
        }
        /* 产生子代2 */
        for (k1 = 1, k3 = location; k1 < N && k3 < N; k3++) {
            for (k2 = 1; k2 < location; k2++)
                if (group_survive[j][k1] == group[j+1][k2])
                    k1++;
            group[j+1][k3] = group_survive[j][k1];
        }
    }
}

void mutation() 
{
}

void tsp_ga()
{
}


int main(int argc, char *argv[])
{
    int i;
    init();
    tsp_sa();
    printf("\n\n模拟退火的最佳路径是：");
    for (i = 0; i < N; i++)
        printf("%d->", best_path[i]);
    printf("%d\n", best_path[0]);
    printf("模拟退火的最佳长度是：%lf\n", best_dist);
    printf("初始温度 = %lf, 温度衰减系数 = %lf\n", T_init, rate);

/* rws部分 */
//    tsp_rws();
//    printf("\n\n轮盘赌的最佳路径是:");
//    for (i = 0; i < N; i++)
//        printf("%d->", best_path_rws[i]);
//    printf("%d\n", best_path_rws[0]);
//    printf("轮盘赌的最佳长度是：%lf\n", best_dist_rws);

    return 0;
}
