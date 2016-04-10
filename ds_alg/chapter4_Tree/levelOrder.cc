#include <iostream>
#include <vector>
using namespace std;

void levelOrder(Tree T) {
    if (T == NULL)
        return ;
    vector<Node> vec;
    vec.push_back(T);
    int cur = 0;   // level head and move forward
    int last = 1;  // each level's last_pos+1 
    while (cur < vec.size()) {
        last = vec.size();		// update end point
        while (cur < last) {    // each level
            cout << vec[cur]->data << " ";
            if (vec[cur]->lchild) 
                vec.push_back(vec[cur]->lchild);    // enqueue
            if (vec[cur]->rchild)
                vec.push_back(vec[cur]->rchild);    // enqueue
            cur++;                                  // dequeue
        }
        cout << endl;  // cur==last means that level finished
    }
}
