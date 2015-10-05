#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL) {}
};

class Solution {
    
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        int x=0, y=0, carry=0, sum=0;
        ListNode *h=NULL, **t=&h;
        
        while (l1!=NULL || l2!=NULL){
            x = getValueAndMoveNext(l1);
            y = getValueAndMoveNext(l2);
            
            sum = carry + x + y;
            
            ListNode *node = new ListNode(sum%10);
            *t = node;
            t = (&node->next);
            
            carry = sum/10;
        }
        
        if (carry > 0) {
            ListNode *node = new ListNode(carry%10);
            *t = node;
        }
        
        return h;
    }
private:
    int getValueAndMoveNext(ListNode* &l){
        int x = 0;
        if (l != NULL){
            x = l->val;
            l = l->next;
        }
        return x;
    }
};

int main()
{
    ListNode *l1 = new ListNode(2), *l2 = new ListNode(5), *result;
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);
    Solution test;
    result = test.addTwoNumbers(l1, l2);
    while (result->next != NULL) {
        cout << result->val << " -> ";
        result = result->next;
    }
    cout << result->val << endl;

    return 0;
}
