#include <iostream>
#include <list>
using namespace std;

list<int> list1;

void find_factor(int sum, int n)
{
    // 递归出口
    if (n <= 0 || sum <= 0)
        return;
   
    // 输出找到的结果
    if (sum == n) {
        list1.reverse();
        for (list<int>::iterator iter = list1.begin(); iter != list1.end(); ++iter)
            cout << *iter << " + ";
        cout << n << endl;
        list1.reverse();
    }

    list1.push_front(n);        // 0-1背包
    find_factor(sum-n, n-1);    // 放n
    list1.pop_front();
    find_factor(sum, n-1);      // 不放n
}

int main()
{
    int sum, n;
    cout << "input sum = ";
    cin >> sum;
    cout << "input size n of arrary{1, ... , n} = ";
    cin >> n;
    cout << "all results: " << endl;
    find_factor(sum, n);
    return 0;
}
