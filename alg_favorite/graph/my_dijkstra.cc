#include <iostream>
#include <vector>
#include <string>
using namespace std;

#define MAX 100
#define INF (~(0x1<<31))	// 0x7FFFFFFF

class MatrixUDG {
private:
	int mVexNum;			// 顶点数
	int mEdgNum;			// 边数
	string mVexs[MAX];		// 顶点数组
	int mMatrix[MAX][MAX];	// 邻接矩阵

public:
	MatrixUDG() { }
	//MatrixUDG(string vexs[], int vlen, string edges[][2], int elen);
	MatrixUDG(string vexs[], int vlen, int matrix[][9]);
	~MatrixUDG();

	int getPos(string s);
	int firstVertex(int v);
	int nextVertex(int v, int w);

	void DFS(int i, int *visited);
	void DFS();
	void BFS();
	void print();

	void dijkstra(int vs, int vexs[], int dist[]);

};

/*
 * 构造函数
 */
MatrixUDG::MatrixUDG(string vexs[], int vlen, int matrix[][9]) {
	// 初始化顶点数
	mVexNum = vlen;

    // 初始化"顶点"
    //mVexs = new string[mVexNum];
    for(int i=0; i<mVexNum; i++)
        mVexs[i] = vexs[i];
    
    // 初始化"边"
	for (int i = 0; i < mVexNum; ++i) 
		for (int j = 0; j < mVexNum; ++j) 
			mMatrix[i][j] = matrix[i][j];

	// 统计边数
	for (int i = 0; i < mVexNum; ++i) 
		for (int j = 0; j < mVexNum; ++j) 
			if (i != j && matrix[i][j] != INF)
				mEdgNum++;

	mEdgNum /= 2;
}

/*
 * 析构函数
 */
MatrixUDG::~MatrixUDG() {
}

/*
 * 返回str的位置
 */
int MatrixUDG::getPos(string s) {
	for (int i = 0; i < mVexNum; ++i)
		if (mVexs[i] == s)
			return i;
	return -1;
}


int MatrixUDG::firstVertex(int v) {
	if (v < 0 || v >= mVexNum)
		return -1;
	for (int i = 0; i < mVexNum; ++i) {
		//if (mMatrix[v][i] == 1)
		if (mMatrix[v][i] != 0 && mMatrix[v][i] != INF)
			return i;
	}
	return -1;
}

int MatrixUDG::nextVertex(int v, int w) {
	if (v < 0 || v >= mVexNum || w < 0 || w >= mVexNum)
		return -1;
	for (int i = w+1; i < mVexNum; ++i) {
		if (mMatrix[v][i] != 0 && mMatrix[v][i] != INF)
			return i;
	}
	return -1;
}

void MatrixUDG::DFS(int i, int *visited) {
	visited[i] = 1;
	cout << mVexs[i] << " ";
	for (int w = firstVertex(i); w != -1; w = nextVertex(i, w)) {
		if (!visited[w])  {
			DFS(w, visited);
		}
	}
}

void MatrixUDG::DFS() {
	int visited[mVexNum];

	for (int i = 0; i < mVexNum; ++i)
		visited[i] = 0;

	cout << "==DFS: " << endl;
	for (int i = 0; i < mVexNum; ++i) {
		if (!visited[i]) 
			DFS(i, visited);
	}
	cout << endl;
}

void MatrixUDG::BFS() {
	int head = 0;
	int rear = 0;
	int visited[mVexNum];
	int queue[mVexNum];

	for (int i = 0; i < mVexNum; ++i)
		visited[i] = 0;
	
	cout << "==BFS: " << endl;
	for (int i = 0; i < mVexNum; ++i) {
		if (!visited[i]) {
			visited[i] = 1;
			cout << mVexs[i] << " ";
			queue[rear++] = i;
		}
		while (head != rear) {
			int j = queue[head++];
			for (int k = firstVertex(j); k != -1; k = nextVertex(j, k)) {
				if (!visited[k]) {
					visited[k] = 1;
					cout << mVexs[k] << " ";
					queue[rear++] = k;
				}
			}
		}
	}
	cout << endl;
}

void MatrixUDG::print() {
	cout << "==Matrix Graph:" << endl;
	for (int i = 0; i < mVexNum; ++i) {
		for (int j = 0; j < mVexNum; ++j)
			if (mMatrix[i][j] == INF)
				cout << "INF\t";
			else
				cout << mMatrix[i][j] << "\t";
		cout << endl;
	}
}


/* 
 * vs	 源点
 * prev	 vs到i的最短路径中i的prev
 * dist	 vs到i的距离（最终保存最短路径）
 */
void MatrixUDG::dijkstra(int vs, int prev[], int dist[]) {
	int min;
	int tmp;
	int flag[mVexNum];		// 标记：vs到i的最短路径已经得到
	
	// 初始化
	for (int i = 0; i < mVexNum; ++i) {
		flag[i] = 0;
		prev[i] = 0;
		dist[i] = mMatrix[vs][i];
	}

	// 初始化源点
	flag[vs] = 1;
	dist[vs] = 0;

	// 遍历mVexNum-1次，每次找出一个顶点的最短路径
	for (int i = 1; i < mVexNum; ++i) {
		min = INF;
		int k;		//	记录当前“未访问的”最短边的点
		for (int j = 0; j < mVexNum; ++j) {
			if (!flag[j] && dist[j] < min) {
				min = dist[j];
				k = j;
			}
		}

		flag[k] = 1;

		// 试探k的“未访问的”邻接点，若短，则更新(min是vs到k的最短路径)
		for (int j = 0; j < mVexNum; ++j) {
			tmp = (mMatrix[k][j] == INF ? INF : (min + mMatrix[k][j]));
			if (!flag[j] && tmp < dist[j]) {
				dist[j] = tmp;
				prev[j] = k;
			}
		}
	}

	// print 最短路径
	cout << "==dijkstra(" << mVexs[vs] << "): " << endl;
	for (int i = 0; i < mVexNum; ++i)
		cout << "  shortest(" << mVexs[vs] << " => " << mVexs[i] << ")= " << dist[i] << endl;
}

int main()
{
	int prev[MAX] = {0};
	int dist[MAX] = {0};
    string vexs[] = {"AA", "BB", "CC", "DD", "EE", "FF", "GG"};
    int matrix[][9] = {
	            /*A*//*B*//*C*//*D*//*E*//*F*//*G*/
	    /*A*/ {   0,  12, INF, INF, INF,  16,  14},
        /*B*/ {  12,   0,  10, INF, INF,   7, INF},
        /*C*/ { INF,  10,   0,   3,   5,   6, INF},
        /*D*/ { INF, INF,   3,   0,   4, INF, INF},
        /*E*/ { INF, INF,   5,   4,   0,   2,   8},
        /*F*/ {  16,   7,   6, INF,   2,   0,   9},
        /*G*/ {  14, INF, INF, INF,   8,   9,   0}};

    int vlen = 7;

   	MatrixUDG* pG = new MatrixUDG(vexs, vlen, matrix);
	pG->print();
	pG->DFS();
	pG->BFS();
	pG->dijkstra(3, prev, dist);

    return 0;
}
