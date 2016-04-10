#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// 使用一个辅助stack，输出从大到小的排序
// 插入排序:
// 每次从stack A pop一个元素data，如果辅助stack B的top < data, 则直接push到stack B
// 否则把stack B中比data大的元素pop到stack A，然后才把data push到stack B，然后再把刚才pop到A的元素push回stack B
// note: stack B一直维持有序, 类似于插入排序的已排部分

stack<int> stackSort(stack<int>& sA) {
	stack<int> sB;
	while (!sA.empty()) {
		int data = sA.top();
		sA.pop();
		while (!sB.empty() && data < sB.top()) {
			sA.push(sB.top());
			sB.pop();
		}
		sB.push(data);
	}
	return sB;
}

int main() {
	int a[] = {3, 1, 4, 2};
	const int n = sizeof(a)/sizeof(int);
	stack<int> sA, sB;
	for (int i = 0; i < n; ++i)
		sA.push(a[i]);
	sB = stackSort(sA);
	for (int i = 0; i < n; ++i) {
		cout << sB.top() << " ";
		sB.pop();
	}
	cout << endl;
	return 0;
}
