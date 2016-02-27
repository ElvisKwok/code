// Source : https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/
// Author : Elvis Kwok
// Date   : 2016-02-25

/********************************************************************************** 
 * 
 * Given a sorted linked list, delete all nodes that have duplicate numbers, leaving 
 * only distinct numbers from the original list.
 * 
 * For example,
 * Given 1->2->3->3->4->4->5, return 1->2->5.
 * Given 1->1->1->2->3, return 2->3.
 *               
 **********************************************************************************/

// related problem 083_removeDuplicatesFromSortedList.cc
#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(NULL) {}
};

class Solution {
public:
    // soulmachine solution: iteratively
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL) return NULL;
        ListNode *fakeHead = new ListNode(0);
        fakeHead->next = head;
        ListNode *prev = fakeHead, *cur = head;
        while (cur != NULL) {
            bool isDuplicate = false;
            while (cur->next != NULL && cur->val == cur->next->val) {    // until (cur->val != cur->next->val)
                isDuplicate = true;
                ListNode* tmp = cur;
                cur = cur->next;
                delete tmp;
            }
            if (isDuplicate) {       // delete the last duplicate
                ListNode* tmp = cur;
                cur = cur->next;
                delete tmp;
            }
            else {
                prev->next = cur;
                prev = prev->next;
                cur = cur->next;
            }
        }
        prev->next = NULL;
        cur = fakeHead->next;
        delete fakeHead;
        return cur;
    }
    // soulmachine solution: recursively
    ListNode* deleteDuplicates2(ListNode* head) {
        if (!head || !head->next)   // not NULL & not tail
            return head;
        ListNode* p = head->next;
        if (head->val == p->val) {
            while (p && head->val == p->val) {
                ListNode* tmp = p;
                p = p->next;
                delete tmp;
            }
            delete head;
            return deleteDuplicate2(p);
        }
        else {
            head->next = deleteDuplicates2(head->next);
            return head;
        }
    }
};

int main(int argc, char **argv)
{
    Solution s;

    if (argc < 2)
        return 0;

    return 0;
}
