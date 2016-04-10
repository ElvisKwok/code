#include <iostream>
#include <vector>
#include <string>
using namespace std;

#define MAX 100
#define INF (~(0x1<<31))	// 0x7FFFFFFF

class EData {	// help kruskal
public:
	string start;
	string end;
	int weight;
	
	EData() { }
	EData(string s, string e, int w): start(s), end(e), weight(w) { }
};

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

	void kruskal();

	// help kruskal
	EData* getEdges();	// 获取原始图的所有边
	void sortEdges(EData* edges, int elen);
	int getEnd(int vends[], int i);		// 在当前最小生成树中，点i在最远能到达的终点。（用来辅助判断回路）
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
 * 获取原始图的所有边
 */
EData* MatrixUDG::getEdges() {	
	EData *edges = new EData[mEdgNum];
	int index = 0;
	for (int i = 0; i < mVexNum; ++i) {
		for (int j = i+1; j < mVexNum; ++j) {
			if (mMatrix[i][j] != INF) {
				edges[index].start 		= mVexs[i];
				edges[index].end		= mVexs[j];
				edges[index].weight		= mMatrix[i][j];
				index++;
			}
		}
	}
	return edges;
}

/*
 * 简单选择排序：每次选最小
 * 简单起见，没用minPos，会有不必要的交换
 */
void  MatrixUDG::sortEdges(EData* edges, int elen) {
	for (int i = 0; i < elen; ++i) {
		for (int j = i+1; j < elen; ++j) {
			if ( edges[i].weight > edges[j].weight)
				swap( edges[i], edges[j]);
		}
	}
}

/*
 * 在当前最小生成树中，点i在最远能到达的终点。（用来辅助判断回路）
 * 如果加入的一条边（C, D), getEnd(C) == getEnd(D), 则一定是回路（C<->dest, D<->dest, C<->D)
 */
int  MatrixUDG::getEnd(int vends[], int i) {
	while (vends[i] != 0)
		i = vends[i];
	return i;
}

void MatrixUDG::kruskal() {
	int index = 0;			// kruskals数组的下标
	int vends[MAX] = {0};
	EData kruskals[MAX];	// 保存结果的边
	EData *edges;

	// 获取“图中所有边”
	edges = getEdges();
	// 排序
	sortEdges(edges, mEdgNum);

	// 从已经排序的边中找出最小&&不构成回路的边
	for (int i = 0; i < mEdgNum; ++i) {
		int p1 = getPos(edges[i].start);
		int p2 = getPos(edges[i].end);
		int m = getEnd(vends, p1);
		int n = getEnd(vends, p2);

		if (m != n) {	// 不构成回路
			vends[m] = n;	// 设置m的终点为n
			kruskals[index++] = edges[i];
		}
	}
	delete[] edges;

	int sum = 0;
	for (int i = 0; i < index; ++i)
		sum += kruskals[i].weight;
	cout << "==kruskal = " << sum << ": " << endl;
	for (int i = 0; i < index; ++i)
		cout << "(" << kruskals[i].start << ", " << kruskals[i].end << ") ";
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
	pG->kruskal();

    return 0;
}
