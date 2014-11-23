/*
 * Solve Traveling Saleman Problem(TSP) by local search.
 * In this program, there are 20 point, and the saleman start traveling at point 0.
 * Bug: haven't implemented random selecting of p[COUNT_P[[N].
 */

#include <stdio.h>
#include <time.h>
#include <math.h>

#define N 20
#define COUNT_P (N-1)*(N-2) / 2

struct point {
    double x;
    double y;
} point[N];

double distance[N][N];
int p[COUNT_P][N];
int tmp[N];
int result[N];
double best_dist;

void init();
double get_dist(int a[N]);
void map();
void tsp();

void init()
{
    srand((unsigned)time(NULL));
    int i, j;
    printf("%d random points are as follows:\n", N);
    for (i = 0; i < N; i++){
        point[i].x = rand()%100;
        point[i].y = rand()%100;
        printf("(%lf,%lf)\n", point[i].x, point[i].y);
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

    for (i = 0; i < N; i++)
        result[i]  = i;
    best_dist = get_dist(result);
    map(result);
}


double get_dist(int a[N])
{
    int i;
    double dist;
    for (i = 1; i < N; i++)
        //dist += sqrt(pow((point[a[i]].x - point[a[i-1]].x), 2) + pow((point[a[i]].y - point[a[i-1]].y), 2));
        //dist += sqrt(pow((point[i].x - point[i-1].x), 2) + pow((point[i].y - point[i-1].y), 2));
        dist += distance[a[i-1]][a[i]];
    dist += distance[a[N-1]][a[0]];
    return dist;
}

void map(int a[N])
{
    int i, j, k, tmp;
    for (i = 0; i < COUNT_P; i++)
        for (j = 0; j < N; j++)
            p[i][j] = a[j];
    for (i = 0; i < COUNT_P; )
        for (j = 1; j < N-1; j++)
            for (k = j+1; k < N; k++) {
                tmp = p[i][j];
                p[i][j] = p[i][k];
                p[i][k] = tmp;
                i++;
            }
    //for (i = 0; i < COUNT_P; i++) {
    //    for (j = 0; j < N; j++)
    //        printf("p[%d][%d] = %d\t", i, j, p[i][j]);
    //    printf("\n");
    //}
 }


void tsp() 
{
    int i, j, random_i, mark[N];
    double tmp;
    for (i = 0; i < COUNT_P; i++) {
        while (mark[random_i = (rand() % N)] == 1)
            random_i = (random_i + 1) % N;
        mark[random_i] = 1;
        tmp = get_dist(p[random_i]);
        //usleep(1);
        //printf("get_dist(p[%d]) = %lf\n", i, tmp);
        if (tmp < best_dist) {
            best_dist = tmp;
            for (j = 0; j < N; j++) {
                result[j] = p[random_i][j];
            }
            map(p[random_i]);
            break;
         }
    }
    if (i < COUNT_P)
        tsp();
    else {
        return;
    }
}
    

int main(int argc, char *argv[])
{
    int i;
    init();
    tsp();
    printf("\nThe best route is:");
    for (i = 0; i < N; i++)
        printf("%d->", result[i]);
    printf("%d\n", result[0]);
    printf("\nThe best distance = %lf\n", best_dist);
    return 0;
}
