/*
 * Solve Traveling Saleman Problem(TSP) by local search.
 * In this program, there are 20 point, and the saleman start traveling at point 0.
 */

#include <stdio.h>
#include <time.h>
#include <math.h>

#define N 20
#define COUNT_P (N-1)*(N-2) / 2

struct point {
    double x;
    double y;
};

double distance[N][N];
int p[COUNT_P][N];
int tmp[N];
int result[N];
double best_dist;

void init()
{
    srand((unsigned)time(NULL));
    int i, j;
    struct point point[N];
    for (i = 0; i < N; i++){
        point[i].x = rand()%100;
        point[i].y = rand()%100;
        //printf("(%lf,%lf)\n", point[i].x, point[i].y);
    }
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            if (i == j)
                continue;
            distance[i][j] = sqrt(pow((point[i].x - point[j].x), 2) + pow((point[i].y - point[j].y), 2));
            //printf("distance[%d][%d] = %lf ", i, j, distance[i][j]);
        }
        //printf("\n");
    }
}

double get_dist(int a[N])
{
    int i;
    double dist;
    for (i = 1; i < N; i++)
        dist += sqrt(pow((point[i].x - point[i-1].x), 2) + pow((point[i].y - point[i-1].y), 2));
    return dist;
}

void map(int a[N])
{
    int i, j, k;
    for (i = 0; i < COUNT_P; i++)
        for (

void tsp() 
{
    int i;
    for (i = 0; i < N; i++)
        result[i] = tmp[i] = i;
    best_dist = get_dist(tmp);
    

} 

int main(int argc, char *argv[])
{
    init();
    return 0;
}
