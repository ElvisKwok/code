#include <iostream>
#include <vector>
#include <string>
using namespace std;

#define MAX 100

class MatrixUDG {
private:
	int mVexNum;			// 顶点数
	int mEdgNum;			// 边数
	string mVexs[MAX];		// 顶点数组
	int mMatrix[MAX][MAX];	// 邻接矩阵

public:
	MatrixUDG() { }
	MatrixUDG(string vexs[], int vlen, string edges[][2], int elen);
	~MatrixUDG();

	int getPos(string s);
	int firstVertex(int v);
	int nextVertex(int v, int w);

	void DFS(int i, int *visited);
	void DFS();
	void BFS();
	void print();

};

/*
 * 构造函数
 */
MatrixUDG::MatrixUDG(string vexs[], int vlen, string edges[][2], int elen) {
	// 初始化顶点数，边数
	mVexNum = vlen;
	mEdgNum = elen;

    // 初始化"顶点"
    //mVexs = new string[mVexNum];
    for(int i=0; i<mVexNum; i++)
        mVexs[i] = vexs[i];
    
    // 初始化"边"
	for (int i = 0; i < mEdgNum; ++i) {
		// 读取边起点、终点
		string s1 = edges[i][0];
		string s2 = edges[i][1];

		int p1 = getPos(s1);
		int p2 = getPos(s2);

		mMatrix[p1][p2] = 1;
		mMatrix[p2][p1] = 1;
	}
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
		if (mMatrix[v][i] == 1)
			return i;
	}
	return -1;
}

int MatrixUDG::nextVertex(int v, int w) {
	if (v < 0 || v >= mVexNum || w < 0 || w >= mVexNum)
		return -1;
	for (int i = w+1; i < mVexNum; ++i) {
		if (mMatrix[v][i] == 1)
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
			cout << mMatrix[i][j] << " ";
		cout << endl;
	}
}


int main()
{
    string vexs[] = {"AA", "BB", "CC", "DD", "EE", "FF", "GG"};
    string edges[][2] = {
        {"AA", "CC"},
        {"AA", "DD"},
        {"AA", "FF"},
        {"CC", "BB"},
        {"FF", "GG"},
        {"GG", "EE"},
        {"CC", "DD"}};
    int vlen = 7;
    int elen = 7;

    //int vlen = sizeof(vexs)/sizeof(vexs[0]);
    //int elen = sizeof(edges)/sizeof(edges[0]);

   	MatrixUDG* pG = new MatrixUDG(vexs, vlen, edges, elen);
	pG->print();
	pG->DFS();
	pG->BFS();

    return 0;
}
