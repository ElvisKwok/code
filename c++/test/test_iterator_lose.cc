#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> vec;
	for (int i=0; i<10; i++)
		vec.push_back(i);
	vector<int>::iterator iter = vec.begin()+2;
	vector<int>::iterator iter2 = vec.begin()+3;
	vector<int>::iterator iter3 = iter+1;

	vec.erase(iter);		// 推荐使用 newIter = vec.erase(iter)
	cout << *iter << endl;
	cout << *iter2 << endl;
	cout << *iter3 << endl;
	for (vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
		cout << *it << endl;
	
	cout << "------------------------" << endl;
	vector<int> vec2;
	for (int i=0; i < 17; ++i) {
		vector<int>::iterator it = vec2.begin();
		vec2.push_back(100);
		cout << "vec2.size(): " << vec2.size() << endl;
		cout << "vec2.capacity(): " << vec2.capacity() << endl;
		//cout << *it << endl;   // 运行时出错：segment fault
	}

	vector<int> vec3;
	for (int i=0; i<10; i++)
		vec.push_back(i);
	vector<int>::iterator it = vec.begin();
	it += 5;
	cout << &(*it) << "\t" << *it << endl;
	it = vec.insert(it, 999);
	cout << &(*it) << "\t" << *it << endl;
	++it;
	cout << &(*it) << "\t" << *it << endl;

	return 0;
}
