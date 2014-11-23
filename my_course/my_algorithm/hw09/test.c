#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MAXN 20
//城市数量
const double MAX = 20.0; //城市数量                             //
const double INIT_T = 3000; //初始温度                                          
const double RATE = 0.95; //温度衰减率
const double FINNAL_T = 1E-10; //终止温度
const int IN_LOOP = 15000; //内循环次数                         //
const int LIMIT = 10000; //概率选择上限                         //
const int FINL_LOOP = 1000; //外层循环                          //
double DD=0;                                                    //
double D_Length[MAXN][MAXN]={0};

struct path
{//定义路线结构
	int citys[MAXN];
	double length;
}D_BestPath;

struct point
{//定义点结构
	double x;
	double y;
}D_Point[MAXN];


//计算点和点之间的距离
void point_dist()
{
	int i, j;
	double x;
	for(i=0; i<MAXN; i++)
	{
		for(j=i+1; j<MAXN; j++)
		{
			x = (D_Point[i].x-D_Point[j].x)*(D_Point[i].x-D_Point[j].x);
			x += (D_Point[i].y-D_Point[j].y)*(D_Point[i].y-D_Point[j].y);
			D_Length[i][j] = sqrt(x);
			D_Length[j][i] = D_Length[i][j];
		}	
	}
}
//初始化
void init()
{
	int i;
	printf("初始状态路径：");
	D_BestPath.length = 0;
	for(i=0; i<MAXN; i++)
	{//初始顺序经过路径
		D_BestPath.citys[i] = i;
		printf("%d--", i);
	}
	for(i=0; i<MAXN-1; i++)
	{//计算路径长度
		D_BestPath.length += D_Length[i][i+1];
	}
	printf("\n路径长度为：%.3lf\n\n", D_BestPath.length);
			
}
void Dprintf(struct path p)
{//用于显示过程变化情况，打印
	int i;
	printf("路径是：");
	for(i=0; i<MAXN; i++)
	{
		printf("%d--", p.citys[i]);
	}
	printf("\n路径长度为：%.3lf\n\n", p.length);
}

//输入城市坐标信息
void input()
{
	int i;
	for(i=0; i<MAXN; i++) {
		D_Point[i].x = rand()%(MAXN*100);
        D_Point[i].y = rand()%(MAXN*100);
    }
}

struct path getnext(struct path p)
{
	struct path ret;
	int i,  x, y;
	int te;
	ret = p;
	do
	{
		x = (int)(MAX*rand()/(RAND_MAX + 1.0));
		y = (int)(MAX*rand()/(RAND_MAX + 1.0));
	}
	while(x == y);
	te = ret.citys[x];
	ret.citys[x] = ret.citys[y];
	ret.citys[y] = te;
	ret.length = 0;
	for(i=0; i<MAXN-1; i++)
	{//计算路径长度
		ret.length += D_Length[ret.citys[i]][ret.citys[i+1]];
	}
	Dprintf(ret);
	DD++;
	return ret;
}

void sa()
{
	int i, P_L=0, P_F=0;;
	struct path curPath, newPath;
	double T = INIT_T;
	double p, delta;
	srand((int)time(0));
	curPath = D_BestPath;
	while(1)
	{
		for(i=0; i<IN_LOOP; i++)
		{
			newPath = getnext(curPath);
			delta = newPath.length - curPath.length;
			if(delta < 0)
			{//更新长度
				curPath = newPath;
				P_L = 0;
				P_F = 0;
			}
			else
			{
				p = (double)(1.0*rand()/(RAND_MAX+1.0));
				if(exp(delta/T) < 1 && exp(delta/T) > p)
				{
					curPath = newPath;
				}
				P_L ++;
			}
			if(P_L > LIMIT)
			{
				P_F ++;
				break;
			}
		}
		if(curPath.length < newPath.length)
		{
			D_BestPath = curPath;
		}
		if(P_F > FINL_LOOP || T<FINNAL_T)
			break;
		T = T * RATE;
	}

}

void main()
{
	input();
	point_dist();
	init();
	sa();
	Dprintf(D_BestPath);
	printf("\n共测试%.0lf次\n", DD);
}

/*
void initi()
{ //测试
	int i;
	D_BestPath.length = 0;
	D_BestPath.citys[0] = 0;
	D_BestPath.citys[1] = 1;
	D_BestPath.citys[2] = 5;
	D_BestPath.citys[3] = 4;
	D_BestPath.citys[4] = 11;
	D_BestPath.citys[5] = 12;
	D_BestPath.citys[6] = 3;
	D_BestPath.citys[7] = 17;
	D_BestPath.citys[8] = 18;
	D_BestPath.citys[9] = 19;
	D_BestPath.citys[10] = 20;
	D_BestPath.citys[11] = 9;
	D_BestPath.citys[12] = 13;
	D_BestPath.citys[13] = 14;
	D_BestPath.citys[14] = 7;
	D_BestPath.citys[15] = 6;
	D_BestPath.citys[16] = 10;
	D_BestPath.citys[17] = 8;
	D_BestPath.citys[18] = 2;
	D_BestPath.citys[19] = 16;
	D_BestPath.citys[20] = 22;
	D_BestPath.citys[21] = 21;
	D_BestPath.citys[22] = 15;
	D_BestPath.citys[23] = 26;
	D_BestPath.citys[24] = 25;
	D_BestPath.citys[25] = 24;
	D_BestPath.citys[26] = 23;
	for(i=0; i<MAXN-1; i++)
	{//计算路径长度
		D_BestPath.length += D_Length[D_BestPath.citys[i]][D_BestPath.citys[i+1]];
	}
	Dprintf(D_BestPath);
}
*/


