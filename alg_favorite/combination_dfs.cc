#include <iostream>
#include <vector>
using namespace std;

//void dfs(vector<vector<int> > &result, vector<int> &path, int start, int cur, int k, int n) {
//    if (cur == k) {
//        result.push_back(path);
//        return ;
//    }
//    for (int i=start; i<=n; ++i) {
//        path.push_back(i);
//        dfs(result, path, i+1, cur+1, k, n); // i+1, not start+1 
//        path.pop_back();
//    }
//}
void dfs(vector<vector<int> > &result, vector<int> &path, int start, int k, int n) {
    if (path.size() == k) {
        result.push_back(path);
        return ;
    }
    for (int i=start; i<=n; ++i) {    // start~n 取值范围
        path.push_back(i);
        dfs(result, path, i+1, k, n); // i+1 not start+1, 取值起始范围比当前大1
        path.pop_back();
    }
}

vector<vector<int> > combine(int n, int k) {
    vector<vector<int> > result;
    if (n<k) return result;
    vector<int> path;
    //dfs(result, path, 1, 0, k, n);
    dfs(result, path, 1, k, n);

    return result;
}

void printMatrix(vector<vector<int> >& vv) {
    for (int i = 0; i < vv.size(); ++i) {
        cout << "[ ";
        for (int j = 0; j < vv[i].size(); ++j) {
            cout << vv[i][j] << " ";
        }
        cout << "]" << endl;
    }
}

int main(int argc, char **argv) {
    vector<vector<int> > result = combine(atoi(argv[1]), atoi(argv[2]));
    printMatrix(result);
    return 0;
}
