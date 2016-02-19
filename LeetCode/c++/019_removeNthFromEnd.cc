// Source : https://leetcode.com/problems/remove-nth-node-from-end-of-list/
// Author : Elvis Kwok
// Date   : 2015-10-14

/********************************************************************************** 
 * 
 * Given a linked list, remove the nth node from the end of list and return its head.
 * 
 * For example,
 * 
 *    Given linked list: 1->2->3->4->5, and n = 2.
 * 
 *    After removing the second node from the end, the linked list becomes 1->2->3->5.
 * 
 * Note:
 * Given n will always be valid.
 * Try to do this in one pass.
 * 
 *               
 **********************************************************************************/

/* my wrong answer occured:
 * input:   ([1], 1)
 * output:  Runtime Error
 * important case: delete the HEAD(if target==head, then head=head->next;)
 */

#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *prev=head, *target=head, *curr=head;
        for (int i = 0; i < n; ++i)
            curr = curr->next;
        while (curr != NULL) {
            prev = target;
            curr = curr->next;
            target = target->next;
        }
        if (target==head)
            head = head->next;
        prev->next = target->next;
        delete target;
        return head;
    }
};

int main(int argc, char **argv)
{
    if (argc < 2)
        return 0;
    Solution s;

    return 0;
}
