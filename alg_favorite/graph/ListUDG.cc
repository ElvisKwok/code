#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 邻接表
class ListUDG {
private:
	// 边表中的结点
	class ENode {
		int ivex;			// 无向边的顶点序号(即在mVexs数组的下标)(UDG每个顶点在边表离散出现两次)
		ENode *nextEdge;	// 下一个具有同样起点的边的终点(A->B, A->C, B是A的firstEgde, C是B的nextEdge) 
		friend class ListUDG;
	};

	// 结点表
	class VNode {
		string data;
		ENode *firstEdge;		 
		friend class ListUDG;
	};

private:
	int mVexNum;		// 顶点数
	int mEdgNum;		// 边数
	VNode *mVexs;		// 顶点数组

public:
	ListUDG() { }
	ListUDG(string vexs[], int vlen, string edges[][2], int elen);
	~ListUDG();

	void DFS();
	void DFS(int i, int *visited);
	void BFS();
	void print();


private:
	int getPos(string s);
	void linkLast(ENode *list, ENode *node);
};

/*
 * 构造函数
 */
ListUDG::ListUDG(string vexs[], int vlen, string edges[][2], int elen) {
	string s1, s2;
	ENode *node1, *node2;

	// 初始化顶点数，边数
	mVexNum = vlen;
	mEdgNum = elen;

    // 初始化"邻接表"的顶点
    mVexs = new VNode[mVexNum];
    for(int i=0; i<mVexNum; i++)
    {
        mVexs[i].data = vexs[i];
        mVexs[i].firstEdge = NULL;
    }
    
    // 初始化"邻接表"的边表
	for (int i = 0; i < mEdgNum; ++i) {
		// 读取边起点、终点
		s1 = edges[i][0];
		s2 = edges[i][1];

		int p1 = getPos(s1);
		int p2 = getPos(s2);

		// 初始化node1
		node1 = new ENode();
		node1->ivex = p2;
		if (mVexs[p1].firstEdge == NULL)
			mVexs[p1].firstEdge = node1;
		else				// 将node1链接到“p1的边表的末尾”
			linkLast(mVexs[p1].firstEdge, node1);

		// 这里比DG多一步
		// 初始化node2
		node2 = new ENode();
		node2->ivex = p1;
		if (mVexs[p2].firstEdge == NULL)
			mVexs[p2].firstEdge = node2;
		else
			linkLast(mVexs[p2].firstEdge, node2);
	}
}

/*
 * 析构函数
 */
ListUDG::~ListUDG() {
	ENode *node;
	for (int i = 0; i < mEdgNum; ++i) {
		node = mVexs[i].firstEdge;
		while (node != NULL) {
			delete node;
			node = node->nextEdge;
		}
	}
	delete[] mVexs;
}

/*
 * 将node链接到“边表”list末尾
 */
void ListUDG::linkLast(ENode *list, ENode *node) {
	ENode *p = list;
	while (p->nextEdge)
		p = p->nextEdge;
	p->nextEdge = node;
}

/*
 * 返回str的位置
 */
int ListUDG::getPos(string s) {
	for (int i = 0; i < mVexNum; ++i)
		if (mVexs[i].data == s)
			return i;
	return -1;
}

void ListUDG::DFS(int i, int *visited) {
	ENode *node;
	visited[i] = 1;
	cout << mVexs[i].data << " ";
	node = mVexs[i].firstEdge;
	while (node != NULL) {
		if (!visited[node->ivex])
			DFS(node->ivex, visited);
		node = node->nextEdge;
	}
}

void ListUDG::DFS() {
	int visited[mVexNum];
	for (int i = 0; i< mVexNum; ++i) 
		visited[i] = 0;

	cout << "==DFS: " << endl;
	for (int i = 0; i < mVexNum; ++i) {
		if (!visited[i])
			DFS(i, visited);
	}
	cout << endl;
}

void ListUDG::BFS() {
	int head = 0;
	int rear = 0;
	int queue[mVexNum];
	int visited[mVexNum];
	ENode *node;

	for (int i = 0; i< mVexNum; ++i) 
		visited[i] = 0;

	cout << "==BFS: " << endl;
	for (int i = 0; i < mVexNum; ++i) {
		if (!visited[i]) {
			visited[i] = 1;
			cout << mVexs[i].data << " ";
			queue[rear++] = i;		// 入队
		}
		while (head != rear) {
			int j = queue[head++];	// 出队
			node = mVexs[j].firstEdge;
			while (node != NULL) {
				int k = node->ivex;
				if (!visited[k]) {
					visited[k] = 1;
					cout << mVexs[k].data << " ";
					queue[rear++] = k;
				}
				node = node->nextEdge;
			}
		}
	}
	cout << endl;
}

void ListUDG::print() {
	ENode *node;
	cout << "==List Graph:" << endl;
	for (int i=0; i<mVexNum; ++i) {
		cout << i << "(" << mVexs[i].data << "): ";
		node = mVexs[i].firstEdge;
		while (node != NULL) {
			cout << node->ivex << "(" << mVexs[node->ivex].data << ") ";
			node = node->nextEdge;
		}
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

   	ListUDG* pG = new ListUDG(vexs, vlen, edges, elen);
	pG->print();
	pG->DFS();
	pG->BFS();


    return 0;
}
