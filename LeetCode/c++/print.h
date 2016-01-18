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

void printStrings(vector<vector<string> >& vv) {
    cout << "[" << endl;
    for (int i = 0; i < vv.size(); ++i) {
        cout << "    [";
        for (int j = 0; j < vv[i].size(); ++j) {
            if (j < vv[i].size()-1)
                cout << "\"" <<vv[i][j] << "\", ";
            else
                cout << "\"" <<vv[i][j] << "\"";
        }
        if (i < vv.size()-1)
            cout << "]," << endl;
        else
            cout << "]" << endl;
    }
    cout << "]" << endl;
}

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL) {}
};

void printList(ListNode* head) {
    if (!head) return;
    while (head->next != NULL) {
        cout << head->val << "->";
        head = head->next;
    }
    cout << head->val << endl;
}

void testPrintList() {
    ListNode *head = new ListNode(0), *p=head;
    for (int i=1; i<=5; ++i) {
        ListNode *node = new ListNode(i);
        p->next = node;
        p = p->next;
    }
    printList(head->next);
    while (head!=NULL) {
        ListNode *tmp = head;
        head = head->next;
        free(tmp);
    }
}

void test() {
    vector<vector<string> > result{{"abc", "efg"}, {"xyz"}};
    printStrings(result);
}
