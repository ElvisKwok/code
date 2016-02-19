// Source : https://leetcode.com/problems/swap-nodes-in-pairs/
// Author : Elvis Kwok
// Date   : 2015-12-20

/********************************************************************************** 
 * 
 * Given a linked list, swap every two adjacent nodes and return its head.
 * 
 * For example,
 * Given 1->2->3->4, you should return the list as 2->1->4->3.
 * 
 * Your algorithm should use only constant space. You may not modify the values in the 
 * list, only nodes itself can be changed.
 * 
 *               
 **********************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL) return head;
        ListNode fakeHead = ListNode(0);
        fakeHead.next = head;
        ListNode *prev=&fakeHead, *p=fakeHead.next, *q;
        while (p != NULL) {
            if (p->next != NULL) {
                q = p->next;
                prev->next = q;
                p->next = q->next;
                q->next = p;
            }
            prev = p;
            p = p->next;
        }
        
        return fakeHead.next;
    }
};

int main(int argc, char **argv)
{
    Solution s;

    if (argc < 2)
        return 0;

    return 0;
}
