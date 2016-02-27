// Source : https://leetcode.com/problems/remove-duplicates-from-sorted-list/
// Author : Elvis Kwok
// Date   : 2015-10-18

/********************************************************************************** 
 * 
 * Given a sorted linked list, delete all duplicates such that each element appear only 
 * once.
 * 
 * For example,
 * Given 1->1->2, return 1->2.
 * Given 1->1->2->3->3, return 1->2->3.
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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL) return NULL;
        ListNode *prev = head, *p = prev->next;
        while (p != NULL) {
            if (prev->val == p->val) { // skip same val, until meet the first different value.
                p = p->next;
                continue;
            }
            prev->next = p;            // p is the first different value.
            prev = prev->next;
        }
        prev->next = NULL;    // beware if remaining same values like ->val->val->val, cut them.
        return head;
    }
       
    // haoel solution: simple and clean.
    ListNode* deleteDuplicates1(ListNode* head) {
        for (ListNode *p = head; p && p->next; ) {
            if (p->val == p->next->val) {   // skip same val, until meet the first different value.
                p->next = p->next->next;    // also cuts same values at the tail.
                continue;
            }
            p = p->next;                    // p->next is the first different value.
        }
        return head;
    }
    // soulmachine solution:
    ListNode* deleteDuplicates2(ListNode* head) {
        if (head == NULL) return NULL;
        for (ListNode *prev = head, *cur = head->next; cur; cur = cur->next) {
            if (prev->val == cur->val) {
                prev->next = cur->next;
                delete cur;
            }
            else
                prev = cur;
        }
        return head;
    }
};

ListNode* createList(int a[], int n)
{
    ListNode *head = NULL, *p = NULL;
    for (int i = 0; i < n; ++i) {
        if (head == NULL)
            head = p = new ListNode(a[i]);
        else {
            p->next = new ListNode(a[i]);
            p = p->next;
        }
    }
    return head;
}

void printList(ListNode *h)
{
    while (h->next != NULL) {
        cout << h->val << "->";
        h = h->next;
    }
    cout << h->val << endl;
}


int main(int argc, char **argv)
{
    Solution s;
    int a[] = {1,1,2,3,3};
    ListNode *head = createList(a, sizeof(a)/sizeof(int)), *p=head;
    printList(p);
    head = s.deleteDuplicates(head);
    printList(head);

    ListNode *head1 = createList(a, sizeof(a)/sizeof(int)), *p1=head1;
    printList(p1);
    head = s.deleteDuplicates1(head1);
    printList(head1);

    ListNode *head2 = createList(a, sizeof(a)/sizeof(int)), *p2=head2;
    printList(p2);
    head = s.deleteDuplicates2(head2);
    printList(head2);


    return 0;
}
