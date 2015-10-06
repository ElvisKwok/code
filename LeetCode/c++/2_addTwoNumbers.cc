#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = new ListNode(0), *p = head;
        int bit_sum = 0, carry_bit = 0, x = 0, y = 0;
        while (l1 != NULL || l2 != NULL) {
            x = getValueAndMoveNext(l1);
            y = getValueAndMoveNext(l2);
            bit_sum = x + y + carry_bit;
            carry_bit = bit_sum / 10;
            p->next = new ListNode(bit_sum%10);
            p = p->next;
        }
        if (carry_bit == 1) 
            p->next = new ListNode(carry_bit);
          
        return head->next;

/* bug when input ([1], [9]->[9]->[9] */
/*
        while (l1 != NULL && l2 != NULL) {
            bit_sum = l1->val + l2->val + carry_bit;
            carry_bit = bit_sum / 10;
            //p = new ListNode(bit_sum%10);     // error
            //p = p->next;      
            p->next = new ListNode(bit_sum%10);
            p = p->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        ListNode *remain = new ListNode(0);
        if (l1 != NULL)
            remain = l1;
        if (l2 != NULL)         // can not use "else" here, input ([5], [5]) cause segment fault
            remain = l2;
        if (carry_bit == 1)
            remain->val += 1;
        if ((l1 == NULL) && (l2 == NULL) && (carry_bit == 1))
            p->next = new ListNode(remain->val);
        while ((remain != NULL) && ((l1 != NULL) || (l2 != NULL))) {
        //while ((remain != NULL) && ((l1 != NULL) || (l2 != NULL))) {
            p->next = new ListNode(remain->val);
            p = p->next;
            remain = remain->next;
        }
*/ 
    }
private:
    int getValueAndMoveNext(ListNode* &l) {
        int x = 0;
        if (l != NULL) {
            x = l->val;
            l = l->next;
        }
        return x;
    }
};


int main()
{
      ListNode *l1 = new ListNode(1), *l2 = new ListNode(9), *result;
//    ListNode *l1 = new ListNode(2), *l2 = new ListNode(5), *result;
//      l1->next = new ListNode(4);
//    l1->next->next = new ListNode(3);
      l2->next = new ListNode(9);
      l2->next->next = new ListNode(9);
//    l2->next->next->next = new ListNode(9);
    Solution test;
    result = test.addTwoNumbers(l1, l2);
    while (result->next != NULL) {
        cout << result->val << " -> ";
        result = result->next;
    }
    cout << result->val << endl;

    return 0;
}
