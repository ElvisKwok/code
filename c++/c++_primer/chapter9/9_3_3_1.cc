#include <iostream>
#include <list>
#include <deque>
using namespace std;

int main()
{
    int a[] = {0, 1, 2, 3, 4, 5};
    list<int> ilst(a, a+6);
    deque<int> odd_deque, even_deque;
    for (list<int>::iterator iter = ilst.begin(); iter != ilst.end(); ++iter) {
        if (*iter % 2)
            odd_deque.push_back(*iter);
        else 
            even_deque.push_back(*iter);
    }

    deque<int>::iterator it;

    it = odd_deque.begin();
    cout << "odd deque: " << endl;
    while (it != odd_deque.end()) {
        cout << *it << " ";
        ++it;
    }
    cout << endl;

    it = even_deque.begin();
    cout << "even deque: " << endl;
    while (it != even_deque.end()) {
        cout << *it << " ";
        ++it;
    }
    cout << endl;

    return 0;
}
