void printVector(vector<int> &v) {
    cout << "{ ";
    for (int i = 0; i < v.size(); ++i)
        cout << v[i] << " ";
    cout << "}" << endl;
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
