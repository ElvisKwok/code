#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct node {
	friend bool operator < (const node &n1, const node &n2) {
		return n1.priority > n2.priority;	// greater: 对于priority_queue是从小到大，sort是从大到小
		//return n1.priority < n2.priority;	// less: 从大到小
	}
	int priority;
	int val;
	node() { }
	node(int p, int v): priority(p), val(v) { }
};

int main() {
	int a[] = {2, 4, 1, 3};
	vector<int> ivec(a, a+sizeof(a)/sizeof(int));
	priority_queue<int, vector<int>, greater<int> > heap;
	for (int i=0; i<ivec.size(); ++i)
		heap.push(ivec[i]);
	while (!heap.empty()) {
		cout << heap.top() << " ";
		heap.pop();
	}
	cout << endl;

	node b[5];
	node n1(6, 1);
	node n2(9, 5);
	node n3(2, 3);
	node n4(8, 2);
	node n5(1, 4);
	b[0] = n1;
	b[1] = n2;
	b[2] = n3;
	b[3] = n4;
	b[4] = n5;
	priority_queue<node> heap2;
	for (int i = 0; i < 5; ++i)
		heap2.push(b[i]);
	cout << "prior\tval" << endl;
	while(!heap2.empty()) {
		cout << heap2.top().priority << "\t" << heap2.top().val << endl;
		heap2.pop();
	}
	
	cout << "\nprior\tval" << endl;
	sort(b, b+sizeof(b)/sizeof(b[0]));
	for (int i = 0; i < 5; ++i)
		cout << b[i].priority << "\t" << b[i].val << endl;

	return 0;
}
