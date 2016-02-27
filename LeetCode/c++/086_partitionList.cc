// Source : https://leetcode.com/problems/partition-list/
// Author : Elvis Kwok
// Date   : 2016-02-25

/********************************************************************************** 
 * 
 * Given a linked list and a value x, partition it such that all nodes less than x come 
 * before nodes greater than or equal to x.
 * 
 * You should preserve the original relative order of the nodes in each of the two 
 * partitions.
 * 
 * For example,
 * Given 1->4->3->2->5->2 and x = 3,
 * return 1->2->2->4->3->5.
 *               
 **********************************************************************************/

// corner case:
//   1. single node

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // soulmachine solution
    ListNode* partition2(ListNode* head, int x) {
        ListNode* leftHead = new ListNode(0);
        ListNode* rightHead = new ListNode(0);
        ListNode* leftCur = leftHead;
        ListNode* rightCur = rightHead;
        for (ListNode* cur = head; cur != NULL; cur = cur->next) {
            if (cur->val < x) {
                leftCur->next = cur;
                leftCur = leftCur->next;
            }
            else {
                rightCur->next = cur;
                rightCur = rightCur->next;
            }
        }

        // link two list and end tail
        leftCur->next = rightHead->next;
        rightCur->next = NULL;      // note!!!

        head = leftHead->next;
        delete leftHead;
        delete rightHead;

        return head;
    }

    // haoel solution
    ListNode* partition(ListNode* head, int x) {
        ListNode* fakeHead = new ListNode(0);
        fakeHead->next = head;
        ListNode* prev = NULL;
        ListNode* cur = fakeHead;
        while (cur != NULL && cur->next != NULL) {  // cur is not the last node & not NULL
            if (prev != NULL && cur->next->val < x) {   
                // prev != NULL makes the beginning of smaller part not change 
                // until meets a num>=x and insert in front of the num,
                // otherwise, nothing to insert in front of.

                // delete cur->next 
                ListNode* target = cur->next;
                cur->next = target->next;

                // insert target(original cur->next) to prev
                target->next = prev->next;
                prev->next = target;
                prev = prev->next;

                continue;
            }
            if (!prev && cur->next->val >= x){      // execute only once when the first one >= x
                prev = cur;
                cur = cur->next;
                continue;
            }
            cur = cur->next;
        }
        head = fakeHead->next;
        delete fakeHead;
        return head;
    }
};

int main(int argc, char **argv)
{
    Solution s;

    if (argc < 2)
        return 0;

    return 0;
}
