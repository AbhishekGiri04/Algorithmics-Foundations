/*
╔══════════════════════════════════════════════════════════════════════════════╗
║                          LEETCODE PROBLEM SOLUTION                           ║
╠══════════════════════════════════════════════════════════════════════════════╣
║ Problem ID    : 24                                                           ║
║ Problem Name  : Swap Nodes in Pairs                                          ║
║ Difficulty    : Medium                                                       ║
║ Topic         : Linked List                                                  ║
╚══════════════════════════════════════════════════════════════════════════════╝

📋 PROBLEM STATEMENT:
Given a linked list, swap every two adjacent nodes and return its head.

You must solve the problem without modifying the values in the list's nodes.
Only the nodes themselves may be changed.

📝 EXAMPLES:
Input: head = [1,2,3,4]
Output: [2,1,4,3]

Input: head = []
Output: []

Input: head = [1]
Output: [1]

🎯 CONSTRAINTS:
- The number of nodes in the list is in the range [0, 100]
- 0 <= Node.val <= 100

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
    ListNode* swapPairs(ListNode* head) {

        ListNode* dummy = new ListNode(-1);
        dummy->next = head;

        ListNode* prev = dummy;

        while (prev->next != NULL && prev->next->next != NULL) {

            ListNode* A = prev->next;
            ListNode* B = A->next;
            ListNode* C = B->next;

            prev->next = B;
            B->next = A;
            A->next = C;

            prev = A;
        }

        return dummy->next;
    }
};