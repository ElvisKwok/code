#include <iostream>
#include <queue>
#include <set>
#include <vector>
using namespace std;

// test k-heap(max & min)
void test(int k) {
    int a[] = {2, 3, 1, 4, 2, 9, 6, 8};
    vector<int> vec(a, a+sizeof(a)/sizeof(int));
    if (k >= vec.size())
        return;

    // test max-heap: priority_queue
    priority_queue<int, vector<int>, greater<int> > qMax;
    for (int i=0; i<vec.size(); ++i)
        qMax.push(vec[i]);
    // test max-heap: red-black tree
    multiset<int, greater<int> > setMax;
    for (int i=0; i<vec.size(); ++i)
        setMax.insert(vec[i]);

    // test min-heap(default): priority_queue 
    priority_queue<int, vector<int> > qMin; // compare=less is default
    //priority_queue<int, vector<int>, less<int> > qMin; 
    for (int i=0; i<vec.size(); ++i)
        qMin.push(vec[i]);
    // test min-heap(default): red-black tree
    multiset<int> setMin;   // compare=less is default
    //multiset<int, less<int> > setMin;
    for (int i=0; i<vec.size(); ++i)
        setMin.insert(vec[i]);

    cout << k << "-max-heap by priority queue is: " << endl;
    for (int i=0; i<k; ++i) {
        cout << qMax.top() << "\t";
        qMax.pop();
    }
    cout << endl;

    cout << k << "-max-heap by multiset is: " << endl;
    for (int i=0; i<k; ++i) {
        cout << *setMax.begin() << "\t";
        setMax.erase(setMax.begin());
    }
    cout << endl;

    cout << k << "-min-heap by priority queue is: " << endl;
    for (int i=0; i<k; ++i) {
        cout << qMin.top() << "\t";
        qMin.pop();
    }
    cout << endl;

    cout << k << "-min-heap by multiset is: " << endl;
    for (int i=0; i<k; ++i) {
        cout << *setMin.begin() << "\t";
        setMin.erase(setMin.begin());
    }
    cout << endl;

    sort(vec.begin(), vec.end());
    cout << "The sorted vector is: " << endl;
    for (int i=0; i<vec.size(); ++i)
        cout << vec[i] << "\t";
    cout << endl;
}

int main() {
    test(5);
    return 0;
}
