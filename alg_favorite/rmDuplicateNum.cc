#include <iostream>
#include <set>
using namespace std;

int main() {
	int i;
	set<int> iset;
	while (cin >> i)
		iset.insert(i);
	for (set<int>::iterator it=iset.begin(); it!=iset.end(); ++it)
		cout << *it << " ";
	cout << endl;
	return 0;
}
