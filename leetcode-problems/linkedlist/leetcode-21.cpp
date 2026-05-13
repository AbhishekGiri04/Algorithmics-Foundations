/*
╔══════════════════════════════════════════════════════════════════════════════╗
║                        LEETCODE PROBLEM SOLUTION                            ║
╠══════════════════════════════════════════════════════════════════════════════╣
║ Problem ID    : 21                                                           ║
║ Problem Name  : Merge Two Sorted Lists                                       ║
║ Difficulty    : Easy                                                         ║
║ Topic         : Linked List                                                  ║
╚══════════════════════════════════════════════════════════════════════════════╝

📋 PROBLEM STATEMENT:
You are given the heads of two sorted linked lists list1 and list2.
Merge them into one sorted linked list by splicing together nodes of both lists.

📝 EXAMPLES:
Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]

Input: list1 = [], list2 = []
Output: []

Input: list1 = [], list2 = [0]
Output: [0]

🎯 CONSTRAINTS:
- 0 <= number of nodes <= 50
- -100 <= Node.val <= 100
- Both lists are sorted in non-decreasing order

⏰ TIME COMPLEXITY: O(N + M)
💾 SPACE COMPLEXITY: O(1)
*/
*/

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;

        while (list1 != NULL && list2 != NULL) {
            if (list1->val <= list2->val) {
                temp->next = list1;
                list1 = list1->next;
            } else {
                temp->next = list2;
                list2 = list2->next;
            }
            temp = temp->next;
        }

        if (list1 == NULL) temp->next = list2;
        if (list2 == NULL) temp->next = list1;

        return dummy->next;
    }
};