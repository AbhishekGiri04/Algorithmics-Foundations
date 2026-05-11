/*
╔══════════════════════════════════════════════════════════════════════════════╗
║                          LEETCODE PROBLEM SOLUTION                           ║
╠══════════════════════════════════════════════════════════════════════════════╣
║ Problem ID    : 237                                                          ║
║ Problem Name  : Delete Node in a Linked List                                 ║
║ Difficulty    : Medium                                                       ║
║ Topic         : Linked List                                                  ║
╚══════════════════════════════════════════════════════════════════════════════╝

📋 PROBLEM STATEMENT:
There is a singly-linked list and we want to delete a node from it.
You are given only access to the node that should be deleted.

Delete the given node such that:
- The value of the node no longer exists in the list
- The linked list size decreases by one
- Order of remaining nodes stays the same

📝 EXAMPLES:
Input: head = [4,5,1,9], node = 5
Output: [4,1,9]

Input: head = [4,5,1,9], node = 1
Output: [4,5,9]

🎯 CONSTRAINTS:
- Number of nodes is in range [2, 1000]
- -1000 <= Node.val <= 1000
- All node values are unique
- Given node is NOT the last node

⏰ TIME COMPLEXITY: O(1)
💾 SPACE COMPLEXITY: O(1)
*/

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
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        node->next = node->next->next;
    }
};