/*
╔══════════════════════════════════════════════════════════════════════════════╗
║                          LEETCODE PROBLEM SOLUTION                           ║
╠══════════════════════════════════════════════════════════════════════════════╣
║ Problem ID    : 1721                                                         ║
║ Problem Name  : Swapping Nodes in a Linked List                              ║
║ Difficulty    : Medium                                                       ║
║ Topic         : Linked List                                                  ║
╚══════════════════════════════════════════════════════════════════════════════╝

📋 PROBLEM STATEMENT:
You are given the head of a linked list and an integer k.

Return the head of the linked list after swapping the values of
the kth node from the beginning and the kth node from the end
(the list is 1-indexed).

📝 EXAMPLES:

Input: head = [1,2,3,4,5], k = 2
Output: [1,4,3,2,5]

Input: head = [7,9,6,6,7,8,3,0,9,5], k = 5
Output: [7,9,6,6,8,7,3,0,9,5]

🎯 CONSTRAINTS:
- The number of nodes in the list is n
- 1 <= k <= n <= 10^5
- 0 <= Node.val <= 100

⏰ TIME COMPLEXITY: O(n)
💾 SPACE COMPLEXITY: O(n)
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
    ListNode* swapNodes(ListNode* head, int k) {

        vector<int> arr;

        ListNode* temp = head;

        while (temp != nullptr) {
            arr.push_back(temp->val);
            temp = temp->next;
        }

        swap(arr[k - 1], arr[arr.size() - k]);

        ListNode* newHead = new ListNode(-1);
        temp = newHead;

        for (int i = 0; i < arr.size(); i++) {

            ListNode* node = new ListNode(arr[i]);

            temp->next = node;
            temp = node;
        }

        return newHead->next;
    }
};