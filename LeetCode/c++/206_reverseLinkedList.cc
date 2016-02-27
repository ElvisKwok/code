// Source : https://leetcode.com/problems/reverse-linked-list/
// Author : Elvis Kwok
// Date   : 2016-01-13

/********************************************************************************** 
 * 
 * Reverse a singly linked list.
 * 
 * click to show more hints.
 * 
 * Hint:
 * A linked list can be reversed either iteratively or recursively. Could you implement 
 * both?
 *               
 **********************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    ListNode* reverseList(ListNode* head) {  // put each node next to head
        if (head==NULL || head->next==NULL) return head;
        ListNode *fakeHead = new ListNode(0), *p, *prev=head, *q;
        fakeHead->next = head;
        p = q = head->next;
        while (p != NULL) {
            prev->next = p->next;
            p->next = fakeHead->next;
            fakeHead->next = p;
            p = prev->next;
       }
       ListNode* result = fakeHead->next;
       delete fakeHead;
       return result;
    }
    // haoel solution:
    ListNode* reverseList_iteratively(ListNode* head) { 
        ListNode *reversedHead=NULL, *p=NULL;
        // 1->2->3->4
        // 1st round: 2->3->4, 1, gets head->val=2, h->val=1
        // 2nd round: 3->4, 2->1
        // 3nd round: 4, 3->2->1, after this, head->val=4, h->val=3
        while (head) {
            p = head->next; //(1): (1)&(4) move forward
            head->next = reversedHead;
            reversedHead = head;
            head = p;       //(4)
        }
        return reversedHead;
    }
    // haoel solution:
    // 1->2->3->4:
    // deepest recursion, head->val = 3, call reverseList(4) and gets h->val=4(h is finally modified here), then 4->3->NULL(ignore the h returned)
    // roll back a level, head->val = 2, in original order 2->next is 3, then 4->3->2->NULL(ignore the h returned)
    // roll back again, head->val = 1 now, then 4->3->2->1->NULL, return h, h->val=4
    ListNode* reverseList_recursively(ListNode* head) { 
        if (head==NULL || head->next==NULL) return head;
        ListNode *h = reverseList_recursively(head->next);
        head->next->next = head;
        head->next = NULL;
        return h;
    }
    
    // CI solution
    ListNode* reverseList_CI(ListNode* head) { 
        ListNode* pReversedHead = NULL;
        ListNode* pNode = head;
        ListNode* pPrev = NULL;
        while (pNode != NULL) {
            ListNode* pNext = pNode->next;
            if (pNext == NULL)
                pReversedHead = pNode;
            pNode->next = pPrev;
            pPrev = pNode;
            pNode = pNext;
        }
        return pReversedHead;
    }
};

int main(int argc, char **argv)
{
    Solution s;

    if (argc < 2)
        return 0;

    return 0;
}
