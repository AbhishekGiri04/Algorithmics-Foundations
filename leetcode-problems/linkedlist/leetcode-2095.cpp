/*
╔══════════════════════════════════════════════════════════════════════════════╗
║                          LEETCODE PROBLEM SOLUTION                           ║
╠══════════════════════════════════════════════════════════════════════════════╣
║ Problem ID    : 2095                                                         ║
║ Problem Name  : Delete the Middle Node of a Linked List                      ║
║ Difficulty    : Medium                                                       ║
║ Topic         : Linked List                                                  ║
╚══════════════════════════════════════════════════════════════════════════════╝

📋 PROBLEM STATEMENT:
You are given the head of a linked list.

Delete the middle node of the linked list and return the head
of the modified linked list.

The middle node of a linked list of size n is the ⌊n / 2⌋th node
from the start using 0-based indexing.

📝 EXAMPLES:

Input: head = [1,3,4,7,1,2,6]
Output: [1,3,4,1,2,6]

Input: head = [1,2,3,4]
Output: [1,2,4]

Input: head = [2,1]
Output: [2]

🎯 CONSTRAINTS:
- The number of nodes in the list is in the range [1, 10^5]
- 1 <= Node.val <= 10^5

⏰ TIME COMPLEXITY: O(n)
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
    ListNode* deleteMiddle(ListNode* head) {

        if (head == nullptr || head->next == nullptr)
            return nullptr;

        int n = 0;

        ListNode* temp = head;

        while (temp != nullptr) {
            n++;
            temp = temp->next;
        }

        int middle = n / 2;

        temp = head;

        for (int i = 0; i < middle - 1; i++)
            temp = temp->next;

        temp->next = temp->next->next;

        return head;
    }
};