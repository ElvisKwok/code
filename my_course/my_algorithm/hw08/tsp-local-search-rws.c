/*
 * Solve Traveling Saleman Problem(TSP) by local search.
 * In this program, there are 20 point, and the saleman start traveling at point 0.
 * Furthermore, we improve this program using Roulette Wheel Selection(RWS)
 */

#include <stdio.h>
#include <stdlib.h>
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
    for (i = 0; i < N; i++) {
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

/*
int rws(int a[COUNT_P][N])
{
    int i, random;
    double sum[COUNT_P];
    sum[0] = get_dist(p[0]);
    for (i = 1; i < COUNT_P; i++)
        sum[i] = sum[i-1] + get_dist(p[i]);
    random = rand() % (int)sum[COUNT_P-1];
    for (i = 0; i < COUNT_P; i++)
        if(random <= sum[i])
            return i;
}
*/

int rws(int a[COUNT_P][N])
{
    int i;
    double random_p, prob[COUNT_P], add_prob[COUNT_P], sum, dist[COUNT_P];
    random_p = (double)rand() / RAND_MAX;
    for (i = 0; i < COUNT_P; i++) {
        dist[i] = get_dist(p[i]);
        sum += dist[i];
    }

    for (i = 0; i < COUNT_P; i++)
        prob[i] = (1 - (dist[i] / sum)) / (COUNT_P - 1);

    add_prob[0] = prob[0];
    for (i = 1; i < COUNT_P; i++)
        add_prob[i] = add_prob[i-1] + prob[i];

    for (i = 0; i < COUNT_P; i++)
        if (random_p <= add_prob[i])
            return i;
}


void tsp()
{
    int i, j, random_i, mark[COUNT_P];
    double tmp;
    for (i = 0; i < COUNT_P; i++) {
        random_i = rws(p);
/*        while (mark[random_i] == 1);
        random_i = (random_i + 1) % COUNT_P;
        mark[random_i] = 1;
*/
        tmp = get_dist(p[random_i]);
       
        //usleep(1);
        //printf("get_dist(p[%d]) = %lf\n", random_i, tmp);
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
