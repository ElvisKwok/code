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

	void prim(int start);

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
 * 源点root
 * 加入未访问的点不会构成回路
 * kruskal 加入未访问的边可能会构成回路
 */

void MatrixUDG::prim(int root) {
	int weights[mVexNum];		// 权重，初始化为root到各点的距离，已加入最小生成树的设为0
	int min, sum=0;		// sum是最小树最终的权重和
	int index = 0;		// 最小树prims数组下标
	string prims[MAX];

	// 初始化
	for (int i = 0; i < mVexNum; ++i)
		weights[i] = mMatrix[root][i];
	prims[index++] = mVexs[root];	// 先把root加入
	weights[root] = 0;	

	for (int i = 0; i < mVexNum; ++i) {
		if (root == i)
			continue;	// 跳过root
		int curMin = 0;
		int min = INF;
		for (int j = 0; j < mVexNum; ++j) {
			if (weights[j] != 0 && weights[j] < min) {	// 找到未加入的(weights[j]!=0)，最小权重对应点curMin
				min = weights[j];
				curMin = j;
			}
		}

		prims[index++] = mVexs[curMin];	// 加入curMin
		weights[curMin] = 0;

		// 因为找到curMin，看“未加入”的其他点权重是否需要更新
		for (int j = 0; j < mVexNum; ++j) {
			if (weights[j] != 0 && mMatrix[curMin][j] < weights[j])
				weights[j] = mMatrix[curMin][j];
		}
	}

	// 现在已经得到prims最小生成树了，还需要求最终权重sum
	for (int i = 1; i < index; ++i) {
		min = INF;
		int n = getPos(prims[i]);		// 找出prims[i]字符串对应的mVexs顶点下标
		// 找出mVexs[0...i]中j->i权值最小的点j
		// 因为prims数组生成过程是从0开始，第i个点的加入肯定是由于j<i的最小边对应的j引入，即mMatrix[j][i]
		for (int j = 0; j < i; ++j) {	
			int m = getPos(prims[j]);
			if (mMatrix[m][n] < min)
				min = mMatrix[m][n];
		}
		sum += min;
	}
	cout << "==prim(" << mVexs[root] << ")= " << sum << ": ";
	for (int i = 0; i < index; ++i)
		cout << prims[i] << " ";
	cout << endl;
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
	pG->prim(0);

    return 0;
}
