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
        ListNode *result_h = NULL, **result_t = &result_h;
        int bit_sum = 0, carry_bit = 0;
        while (l1 != NULL && l2 != NULL) {
            *result_t = new ListNode(0);
            bit_sum = l1->val + l2->val + carry_bit;
            if (bit_sum >= 10) {
                (*result_t)->val = bit_sum - 10;
                carry_bit = 1;
            }
            else {
                (*result_t)->val = bit_sum;
                carry_bit = 0;
            }
            l1 = l1->next;
            l2 = l2->next;
            (*result_t) = (*result_t)->next;
        }
        ListNode *remain;
        if (l1 != NULL)
            remain = l1;
        else
            remain = l2;
        if (carry_bit = 1)
            remain->val += 1;
        while (remain != NULL) {
            *result_t = new ListNode(0);
            (*result_t)->val = remain->val;
            remain = remain->next;
            (*result_t) = (*result_t)->next;
        }
        return result_h;
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
