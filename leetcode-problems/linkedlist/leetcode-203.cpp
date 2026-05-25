/*
╔══════════════════════════════════════════════════════════════════════════════╗
║                          LEETCODE PROBLEM SOLUTION                           ║
╠══════════════════════════════════════════════════════════════════════════════╣
║ Problem ID    : 203                                                          ║
║ Problem Name  : Remove Linked List Elements                                  ║
║ Difficulty    : Easy                                                         ║
║ Topic         : Linked List                                                  ║
╚══════════════════════════════════════════════════════════════════════════════╝

📋 PROBLEM STATEMENT:
Given the head of a linked list and an integer val, remove all
the nodes of the linked list that has Node.val == val, and
return the new head.

📝 EXAMPLES:
Input: head = [1,2,6,3,4,5,6], val = 6
Output: [1,2,3,4,5]

Input: head = [], val = 1
Output: []

Input: head = [7,7,7,7], val = 7
Output: []

🎯 CONSTRAINTS:
- The number of nodes in the list is in the range [0, 10^4]
- 1 <= Node.val <= 50
- 0 <= val <= 50

⏰ TIME COMPLEXITY: O(N)
💾 SPACE COMPLEXITY: O(1)
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:

    ListNode* removeElements(ListNode* head, int val) {

        if(head == NULL) {
            return head;
        }

        ListNode* dummy = new ListNode(-1);
        dummy->next = head;

        ListNode* slow = dummy;
        ListNode* fast = head;

        while(fast != NULL) {

            if(fast->val == val) {

                slow->next = fast->next;
                fast = fast->next;
            }
            else {

                slow = slow->next;
                fast = fast->next;
            }
        }

        return dummy->next;
    }
};