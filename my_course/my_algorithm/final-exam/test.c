/*
 * Solve Traveling Saleman Problem(TSP) by Genetic Algorithm(GA).
 * In this program, there are 20 point, and the saleman start traveling at point 0.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

/*-----------------------------------------------常量声明----------------------------------------------*/
#define N               20

/* sa部分 */
#define T_INIT          100000              /* 初始温度 */
#define T_MIN           1                   /* 终止界限，当T<T_MIN时，停止搜索 */
#define SA_ITER         10                  /* 每一个温度的迭代次数*/
#define RATE_SA         0.90                /* 温度衰减系数 */

/* local_search部分 */
//#define COUNT_P (N-1)*(N-2)/2

/* ga部分 */
#define POPULATION      10                  /* 种群规模 */
#define PC              0.9                 /* 交配概率 */
#define PM              0.01                /* 变异概率 */
#define MAX_GA_ITER     5000                /* 终止条件：迭代次数 */

/* ga_sa_hybrid部分 */
#define GA_SA_ITER      1                   /* 每一个温度的迭代次数*/
#define RATE_GA_SA      0.999               /* 温度衰减系数 */

/*-----------------------------------------------变量声明----------------------------------------------*/
struct point {
    double x;
    double y;
} point[N];

double distance[N][N];                      /* 保存欧式距离 */

/* sa部分 */
int tmp_path_sa[N];                         /* 当前路径*/
int best_path_sa[N];                        /* 最优路径 */
double tmp_dist_sa;                         /* 当前路径的长度 */
double best_dist_sa;                        /* 最优路径的长度 */

/* rws部分 */
//int p[COUNT_P][N];                        /* 保存映射 */
//int tmp_path_rws[N];                      /* rws方法的当前路径 */
//int best_path_rws[N];                     /* rws方法的最优路径 */
//double tmp_dist_rws;                      /* rws方法的当前路径的长度 */
//double best_dist_rws;                     /* rws方法的最优路径的长度 */

/* ga部分 */
int best_path_ga[N];                        /* ga方法的最优路径 */
double best_dist_ga;                        /* ga方法的最优路径的长度 */
int group[POPULATION][N];                   /* 选定的群体 */
int group_survive[POPULATION][N];           /* 选择后存活的种群 */

/* ga_sa_hybrid部分 */
int best_path_ga_sa[N];                     /* ga_sa_hybrid方法的最优路径 */
double best_dist_ga_sa;                     /* ga_sa_hybrid方法的最优路径的长度 */
int group_ga_sa[POPULATION][N];             /* 选定的群体 */

/*-----------------------------------------------函数声明----------------------------------------------*/
void init();
double get_dist(int a[N]);

/* sa部分 */
void new_path(int tmp_path_sa[N]);
void print_path(int tmp_path_sa[N]);
void assign_path(int from[N], int to[N]);
void tsp_sa();

/* ga部分 */
void init_group(int a[POPULATION][N], double *dist);
//double get_dist(int a[N]);
int rws_ga(int a[POPULATION][N]);
//void assign_path(int from[N], int to[N]);
void best_ga(int a[POPULATION][N], double *best_dist, int best_path[N]);
void selection(int a[POPULATION][N], int survive[POPULATION][N], double *best_dist, int best_path[N]);
void crossover(int from[POPULATION][N], int to[POPULATION][N], double *best_dist, int best_path[N]);
void mutation(int a[POPULATION][N], double *best_dist, int best_path[N]);
void tsp_ga();

/* ga_sa_hybrid部分 */
//void selection(int a[POPULATION][N], int survive[POPULATION][N], double *best_dist, int best_path[N]);
//void crossover(int from[POPULATION][N], int to[POPULATION][N], double *best_dist, int best_path[N]);
//void mutation(int a[POPULATION][N], double *best_dist, int best_path[N]);
void sel_cros_mut(int from[POPULATION][N], double *best_dist, int best_path[N]);
//double get_dist(int a[N]);
double avg_dist(int a[POPULATION][N]);
void assign_group(int from[POPULATION][N], int to[POPULATION][N]);
void tsp_ga_sa_hybrid();

/*-----------------------------------------------函数实现----------------------------------------------*/
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
        best_path_sa[i]  = i;
        tmp_path_sa[i] = i;
        printf("%d->", i);

//        best_path_rws[i] = i;
    }
    printf("%d\n", 0);
    best_dist_sa = tmp_dist_sa = get_dist(best_path_sa);
    printf("路径长度是：%lf\n", best_dist_sa);

//    best_dist_rws = get_dist(best_path_rws);
//    map(best_path_rws);
}

/* 计算当前路径a[N]的路径长度 */
double get_dist(int a[N])
{
    int i;
    double dist = 0.0;
    for (i = 1; i < N; i++)
        dist += distance[a[i-1]][a[i]];
    dist += distance[a[N-1]][a[0]];
    return dist;
}

/*-----------------------------------------------sa部分----------------------------------------------*/
/* 生成新的路径，暂存在tmp_path_sa[N]中 */
void newpath(int tmp_path_sa[N])
{
    int x, y, t;
    /* 从城市1到N-1中随机挑选两个城市交换 */
    do {
        x = (rand() % (N-1)) + 1;
        y = (rand() % (N-1)) + 1;
    } while (x == y);
    t = tmp_path_sa[x];
    tmp_path_sa[x] = tmp_path_sa[y];
    tmp_path_sa[y] = t;
}

/* 打印当前路径、路径长度 */
void print_path(int tmp_path_sa[N])
{
    int i;
    printf("路径：");
    for (i = 0; i < N; i++)
        printf("%d->", tmp_path_sa[i]);
    printf("%d\n", tmp_path_sa[0]);
    printf("路径长度是：%lf\n\n", tmp_dist_sa);
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
    double T = T_INIT;
    double cur_dist, delta, rand_prob, accept_prob;
    int cur_path[N];
    assign_path(best_path_sa, cur_path);
    cur_dist = best_dist_sa;
    while ( T > T_MIN) {
        for (i = 0; i < SA_ITER; i++) {          /* 每一温度下的迭代次数SA_ITER */
            newpath(tmp_path_sa);
            tmp_dist_sa = get_dist(tmp_path_sa);
//            print_path(tmp_path_sa);                   /* 打印当前路径、路径长度 */
            delta = tmp_dist_sa - cur_dist;
            if (delta < 0) {                        /* 遇到更优解 */
                assign_path(tmp_path_sa, cur_path);
                cur_dist = tmp_dist_sa;
            }
            else {                                  /* 否则，按照metropolis准则接受“差解” */
                rand_prob = (double)rand() / RAND_MAX;  /* Random(0, 1) */
                accept_prob = exp((-delta) / T);
                if (accept_prob < 1 && accept_prob > rand_prob) {
                    assign_path(tmp_path_sa, cur_path);
                    cur_dist = tmp_dist_sa;
                }
            }
        }
        if (cur_dist < best_dist_sa) {
            best_dist_sa = cur_dist;
            assign_path(cur_path, best_path_sa);
        }
        T = T * RATE_SA;                               /* 降低温度 */
    }
    printf("\n\n【模拟退火】\n最佳路径是：");
    for (i = 0; i < N; i++)
        printf("%d->", best_path_sa[i]);
    printf("%d\n", best_path_sa[0]);
    printf("最佳长度是：%lf\n", best_dist_sa);
//    printf("初始温度 = %d, 温度衰减系数 = %lf\n", T_INIT, RATE_SA);
}

/*-----------------------------------------------rws部分----------------------------------------------*/
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
//        dist[i] = get_dist(a[i]);
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

/*-----------------------------------------------ga部分----------------------------------------------*/
/* 初始化群体、最优长度*dist */
void init_group(int a[POPULATION][N], double *dist)
{
    int i, j, k, temp, flag;
    for (i = 0; i < POPULATION; i++) {
        /* 产生N-1个不同的数字 */
        for (j = 1; j < N; ) {
            temp = (rand() % (N-1)) + 1;
            flag = 1;
            for (k = 1; k < j; k++) {
                if (a[i][k] == temp) {
                    flag = 0;
                    break;
                }
            }
            if (flag == 1) {
                a[i][j] = temp;
                j++;
            }
        }
    }
    *dist = get_dist(a[0]);
}

/* 选择的依据：适应度(轮盘赌) */
int rws_ga(int a[POPULATION][N])
{
    int i;
    double random_p, prob[POPULATION], add_prob[POPULATION], sum = 0.0, dist[POPULATION];
    random_p = (double)rand() / RAND_MAX;
    for (i = 0; i < POPULATION; i++) {
        dist[i] = get_dist(a[i]);
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
    return 0;
}

/* 计算并保存当前群落中的更优解 */
/* 最优长度保存在*best_dist, 最优路径保存在best_path数组 */
void best_ga(int a[POPULATION][N], double *best_dist, int best_path[N])
{
    int i;
    double dist;
    for (i = 0; i < POPULATION; i++) {
        dist = get_dist(a[i]);
        if (dist < *best_dist) {
            *best_dist = dist;
            assign_path(a[i], best_path);
        }
    }
}

/* 根据适应度选择存活的种群(群体a=>种群survive) */
void selection(int a[POPULATION][N], int survive[POPULATION][N], double *best_dist, int best_path[N])
{
    best_ga(group, best_dist, best_path);             /* 计算选择前的最优解 */
    int i, selected;
    for (i = 0; i < POPULATION; i++) {
        selected = rws_ga(a);
        assign_path(a[selected], survive[i]);
    }
    best_ga(survive, best_dist, best_path);             /* 计算选择后的最优解 */
}

/* 整数编码的常规交配法*/
/* 种群from => 新的群体to */
void crossover(int from[POPULATION][N], int to[POPULATION][N], double *best_dist, int best_path[N])
{
    int i, j, t, k1, k2, k3, flag;  /* k1为父代1搜索位置，k2为父代2搜索位置，k3为交配后的基因放置位置*/
    int location = N/2;             /* 交配起始位置 */
    for (i = 0; i < POPULATION/2; i++) {
        /* POPULATION/2对个体(j, j+1)，两两交配 */
        j = i * 2;
        /* 前面部分直接复制 */
        for (t = 0; t < location; t++) {
            to[j][t] = from[j][t];
            to[j+1][t] = from[j+1][t];
        }
        /* 产生子代1 */
        for (k2 = 1, k3 = location; k2 < N && k3 < N; ) {
            flag = 0;
            for (k1 = 1; k1 < k3; k1++)
                if (from[j+1][k2] == to[j][k1])
                    flag = 1;
            if (flag == 0)
                to[j][k3++] = from[j+1][k2++];
            else k2++;
        }
        /* 产生子代2 */
        for (k1 = 1, k3 = location; k1 < N && k3 < N; ) {
            flag = 0;
            for (k2 = 1; k2 < k3; k2++)
                if (from[j][k1] == to[j+1][k2])
                    flag = 1;
            if (flag == 0)
                to[j+1][k3++] = from[j][k1++];
            else k1++;
        }
    }
    best_ga(to, best_dist, best_path);             /* 计算交配后的最优解 */
}

/* 对于种群a，若随机频率random_p < 变异频率PM， 则变异该染色体：随机交换两个城市 */
void mutation(int a[POPULATION][N], double *best_dist, int best_path[N]) 
{
    int i, x, y, temp;
    double random_p;
    for (i = 0; i < POPULATION; i++) {
        random_p = (double)rand() / RAND_MAX;
        if (random_p < PM) {
            do {
                x = (rand() % (N-1)) + 1;
                y = (rand() % (N-1)) + 1;
            } while (x == y);
            temp = a[i][x];
            a[i][x] = a[i][y];
            a[i][y] = temp;
        }
    }
    best_ga(a, best_dist, best_path);             /* 计算变异后的最优解 */
}

void tsp_ga()
{
    int i;
    init_group(group, &best_dist_ga);
    for (i = 0; i < MAX_GA_ITER; i++) {
        selection(group, group_survive, &best_dist_ga, best_path_ga);
        crossover(group_survive, group, &best_dist_ga, best_path_ga);
        mutation(group, &best_dist_ga, best_path_ga);
    }
    printf("\n\n【遗传算法】\n最佳路径是：");
    for (i = 0; i < N; i++)
        printf("%d->", best_path_ga[i]);
    printf("%d\n", best_path_ga[0]);
    printf("最佳长度是：%lf\n", best_dist_ga);
//    printf("迭代次数是：%d\n", MAX_GA_ITER);
}

/*-----------------------------------------------ga_sa_hybrid部分----------------------------------------------*/
/* 一次选择、交配和变异操作 */
void sel_cros_mut(int from[POPULATION][N], double *best_dist, int best_path[N])
{
    int temp_survive[POPULATION][N];
    selection(from, temp_survive, &best_dist_ga_sa, best_path_ga_sa);
    crossover(temp_survive, from, &best_dist_ga_sa, best_path_ga_sa);
    mutation(from, &best_dist_ga_sa, best_path_ga_sa);
}

/* 计算种群的平均长度 */
double avg_dist(int a[POPULATION][N])
{
    int i;
    double sum = 0;
    for (i = 0; i < POPULATION; i++) 
        sum += get_dist(a[i]);
    return sum / POPULATION;
}

/* 种群复制 */
void assign_group(int from[POPULATION][N], int to[POPULATION][N])
{
    int i, j;
    for (i = 0; i < POPULATION; i++) 
        for (j = 0; j < N; j++) 
            to[i][j] = from[i][j];
}

/* 结合遗传算法&&模拟退火解决tsp问题 */
void tsp_ga_sa_hybrid()
{
    init_group(group_ga_sa, &best_dist_ga_sa);

    int i, tmp_group[POPULATION][N], cur_group[POPULATION][N];
    double T = T_INIT;
    double cur_avg, tmp_avg, best_avg, delta, rand_prob, accept_prob;
    assign_group(group_ga_sa, cur_group);
    assign_group(group_ga_sa, tmp_group);
    cur_avg = best_avg = avg_dist(group_ga_sa);
    while (T > T_MIN) {
        for (i = 0; i < GA_SA_ITER; i++) {
            assign_group(group_ga_sa, cur_group);
            sel_cros_mut(tmp_group, &best_dist_ga_sa, best_path_ga_sa);      /* 遗传一代, 暂存起来 */
            tmp_avg = avg_dist(tmp_group);
            delta = tmp_avg - cur_avg;
            if (delta < 0) {                                /* 遇到“更优种群“（平均长度较短） */
                assign_group(tmp_group, cur_group);
                cur_avg = tmp_avg;
            }
            else {                                          /* 否则，按照metropolis准则接受“差种群”(平均长度较长) */
                rand_prob = (double)rand() / RAND_MAX;      /* Random(0, 1) */
                accept_prob = exp((-delta) / T);
                if (accept_prob < 1 && accept_prob > rand_prob) {
                    assign_group(tmp_group, cur_group);
                    cur_avg = tmp_avg;
                }
            }
        }
        if (cur_avg < best_avg) { 
            best_avg = cur_avg;
            assign_group(cur_group, group_ga_sa);
        }
        T = T * RATE_GA_SA;                                 /* 降温 */
    }
    printf("\n\n【遗传算法改进】\n最佳路径是：");
    for (i = 0; i < N; i++)
        printf("%d->", best_path_ga_sa[i]);
    printf("%d\n", best_path_ga_sa[0]);
    printf("最佳长度是：%lf\n", best_dist_ga_sa);
//    printf("初始温度 = %d, 温度衰减系数 = %lf\n", T_INIT, RATE_GA_SA);
}



/*-----------------------------------------------main函数----------------------------------------------*/
int main(int argc, char *argv[])
{
    init();
    time_t start1, start2, start3, end1, end2, end3;
//    time(&start1);
    tsp_sa();
//    time(&end1);

/* rws部分 */
//    tsp_rws();
//    printf("\n\n轮盘赌的最佳路径是:");
//    for (i = 0; i < N; i++)
//        printf("%d->", best_path_rws[i]);
//    printf("%d\n", best_path_rws[0]);
//    printf("轮盘赌的最佳长度是：%lf\n", best_dist_rws);

//    time(&start2);
    tsp_ga();
//    time(&end2);

//    time(&start3);
    tsp_ga_sa_hybrid();
//    time(&end3);
    
    //printf("%lf\t%lf\t%lf\n", best_dist_ga_sa, best_dist_ga, best_dist_sa);
    if (best_dist_ga_sa < best_dist_ga)
        printf("g\n");
    if (best_dist_ga_sa < best_dist_sa)
        printf("s\n");
    printf("\n");
    //    printf("模拟退火：\t%f sec(s)\n", difftime(end1, start1));
    //    printf("遗传算法：\t%f sec(s)\n", difftime(end2, start2));
    //    printf("遗传算法改进：\t%f sec(s)\n", difftime(end3, start3));
    return 0;
}
