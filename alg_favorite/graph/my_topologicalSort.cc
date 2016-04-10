#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 邻接表
class ListDG {
private:
	// 边表中的结点
	class ENode {
		int ivex;			// 有向边指向的顶点序号(即在mVexs数组的下标)
		ENode *nextEdge;	// 下一个具有同样起点的边的终点(A->B, A->C, B是A的firstEgde, C是B的nextEdge) 
		friend class ListDG;
	};

	// 结点表
	class VNode {
		string data;
		ENode *firstEdge;		 
		friend class ListDG;
	};

private:
	int mVexNum;		// 顶点数
	int mEdgNum;		// 边数
	VNode *mVexs;		// 顶点数组

public:
	ListDG() { }
	ListDG(string vexs[], int vlen, string edges[][2], int elen);
	~ListDG();

	// 遍历ListDG与ListUDG一样
	void DFS();
	void DFS(int i, int *visited);
	void BFS();
	void print();

	int topologicalSort();

private:
	int getPos(string s);
	void linkLast(ENode *list, ENode *node);
};

/*
 * 构造函数
 */
ListDG::ListDG(string vexs[], int vlen, string edges[][2], int elen) {
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
	}
}

/*
 * 析构函数
 */
ListDG::~ListDG() {
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
void ListDG::linkLast(ENode *list, ENode *node) {
	ENode *p = list;
	while (p->nextEdge)
		p = p->nextEdge;
	p->nextEdge = node;
}

/*
 * 返回str的位置
 */
int ListDG::getPos(string s) {
	for (int i = 0; i < mVexNum; ++i)
		if (mVexs[i].data == s)
			return i;
	return -1;
}

void ListDG::DFS(int i, int *visited) {
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

void ListDG::DFS() {
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

void ListDG::BFS() {
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

void ListDG::print() {
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

/*
 * 返回值: 0成功，1环
 */

int ListDG::topologicalSort() {
	int index = 0;
	int head = 0;					// 辅助队列头
	int rear = 0;					// 辅助队列尾
	vector<int> queue(mVexNum);		// 辅助队列（保存入度为0的点）
	vector<int> ins(mVexNum);		// 入度数组
	vector<string> tops(mVexNum);	// 拓扑排序结果数据，节点排序后的序号
	ENode *node;

	// 统计每个顶点的入度数
	for (int i = 0; i < mVexNum; ++i) {	// 对于每个顶点的边表
		node = mVexs[i].firstEdge;
		while (node != NULL) {
			ins[node->ivex]++;
			node = node->nextEdge;
		}
	}

	// 将所有入度为0的顶点入队
	for (int i = 0; i < mVexNum; ++i) {
		if (ins[i] == 0)
			queue[rear++] = i;			// 入队
	}

	while (head != rear) {				// 队列非空
		int i = queue[head++];			// 出队
		tops[index++] = mVexs[i].data;	// 加入拓扑排序结果

		node = mVexs[i].firstEdge;		// 获取以该顶点为起始点的出边队列

		// 将与“node”关联的点的入度-1
		// 若-1后入度为0，则入队
		while (node != NULL) {
			ins[node->ivex]--;
			if (ins[node->ivex] == 0)
				queue[rear++] = node->ivex;		// 入队

			node = node->nextEdge;
		}
	}
	
	if (index != mVexNum) {
		cout << "ERROR" << endl;
		//cout << "CIRCLE" << endl;
		return 1;
	}

	// print result
	cout << "==TopSort: " << endl;;
	for (int i = 0; i < mVexNum; ++i) 
		cout << tops[i] << " ";
	cout << endl;

	return 0;
}

int main()
{
//    string vexs[] = {"AA", "BB", "CC", "DD", "EE", "FF", "GG"};
//    string edges[][2] = {
//        {"AA", "BB"},
//        {"BB", "CC"},
//        {"BB", "EE"},
//        {"BB", "FF"},
//        {"CC", "EE"},
//        {"DD", "CC"},
//        {"EE", "BB"},
//        {"EE", "DD"},
//        {"FF", "GG"}};
//    int vlen = 7;
//    int elen = 9;
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

   	ListDG* pG = new ListDG(vexs, vlen, edges, elen);
	pG->print();
	pG->DFS();
	pG->BFS();
	pG->topologicalSort();

    return 0;
}
