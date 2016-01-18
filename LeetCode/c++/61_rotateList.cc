// Source : https://leetcode.com/problems/rotate-list/
// Author : Elvis Kwok
// Date   : 2016-01-13

/********************************************************************************** 
 * 
 * Given a list, rotate the list to the right by k places, where k is non-negative.
 * 
 * For example:
 * Given 1->2->3->4->5->NULL and k = 2,
 * return 4->5->1->2->3->NULL.
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
    // edge case: k % list.size = 0
    // solution: two pointer
    ListNode* rotateRight(ListNode* head, int k) {
        if (head==NULL || k==0)   return head;
        ListNode *fakeHead = new ListNode(0), *p, *q, *oldTail, *newTail;
        fakeHead->next = head;
        p = q = oldTail = head;
        int len = 1;
        while (oldTail->next != NULL) {
            oldTail = oldTail->next;
            ++len;
        }
        k %= len;
        if (k == 0) return head;
        while (k>0) {
            oldTail = p;
            p = p->next;
            --k;
        }
        while (p != NULL) {
            oldTail = oldTail->next;
            newTail = q;
            p = p->next;
            q = q->next;
        }
        oldTail->next = fakeHead->next;
        fakeHead->next = newTail->next;
        newTail->next = NULL;

        return fakeHead->next;
    }
    
    // soulmachine solution: connect and break the circle
    ListNode* rotateRight2(ListNode* head, int k) {
        if (head==NULL || k==0)   return head;
        int len = 1;
        ListNode *p = head;
        while (p->next != NULL) {
            ++len;
            p = p->next;
        }
        p->next = head;     // connect the circle, now p is in the orginal tail pos
        //k %= len;
        k = len - (k%len);  // NOTE: conntinue moving len-(k%len) steps == going back k%len steps
        // like 1->2->3->4->5, k=1, len=5, p points to 5
        // then k=4, to move 4 steps forward to make p stops in 4
        for (int i=0; i<k; ++i) 
            p = p->next;

        // now p is the final tail pos we want, break the circle here;
        head = p->next;
        p->next = NULL;
        return head;
    }


};
    
void printList(ListNode* head) {
    if (!head) return;
    while (head->next != NULL) {
        cout << head->val << "->";
        head = head->next;
    }
    cout << head->val << endl;
}

int main(int argc, char **argv)
{
    Solution s;
    ListNode *head = new ListNode(0), *p=head;
    for (int i=1; i<=atoi(argv[1]); ++i) {
        ListNode *node = new ListNode(i);
        p->next = node;
        p = p->next;
    }
    head->next = s.rotateRight2(head->next, atoi(argv[2]));
    printList(head->next);
    while (head!=NULL) {
        ListNode *tmp = head;
        head = head->next;
        free(tmp);
    }

    return 0;
}
