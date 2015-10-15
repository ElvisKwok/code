// Source : https://leetcode.com/problems/merge-two-sorted-lists/
// Author : Elvis Kwok
// Date   : 2015-10-15

/********************************************************************************** 
 * 
 * Merge two sorted linked lists and return it as a new list. The new list should be 
 * made by splicing together the nodes of the first two lists.
 *               
 *               
 * 
 *               
 **********************************************************************************/



#include <iostream>
#include <vector>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode fakeHead = ListNode(0), *curr=&fakeHead;
        while (l1 != NULL && l2 != NULL) {
            if (l1->val <= l2->val) {
                curr->next = l1;
                l1 = l1->next;
            }
            else {
                curr->next = l2;
                l2 = l2->next;
            }
            curr = curr->next;
        }
        curr->next = (l1 != NULL) ? l1 : l2;
        return fakeHead.next;
    }
    // haoel version: merge the 2nd list into 1st list
    ListNode* mergeTwoLists2(ListNode* l1, ListNode* l2) {
        ListNode *p1 = l1, *p2 = head2;
        static ListNode dummy(0);
        dummy.next = p1;
        ListNode *prev = &dummy;    // prev->next initiate as p1
        // always regard prev->next as p1 except p2->val is smaller.
        while (p1 && p2) {
            if (p1->val < p2->val) {
                prev = p1;
                p1 = p1->next;
            }
            else {
                prev->next = p2;
                p2 = p2->next;
                prev = prev->next;  // insert p2
                prev->next = p1;    // keep p1 as prev->next;
            }
        }
        if (p2)     // rest
            prev->next = p2;
        return dummy.next;
};

int main(int argc, char **argv)
{
    if (argc < 2)
        return 0;
    Solution s;

    return 0;
}
