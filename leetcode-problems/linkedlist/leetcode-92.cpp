/*
╔══════════════════════════════════════════════════════════════════════════════╗
║                          LEETCODE PROBLEM SOLUTION                           ║
╠══════════════════════════════════════════════════════════════════════════════╣
║ Problem ID    : 92                                                           ║
║ Problem Name  : Reverse Linked List II                                       ║
║ Difficulty    : Medium                                                       ║
║ Topic         : Linked List                                                  ║
╚══════════════════════════════════════════════════════════════════════════════╝

📋 PROBLEM STATEMENT:
Given the head of a singly linked list and two integers left and right where
left <= right, reverse the nodes of the list from position left to position
right, and return the reversed list.

📝 EXAMPLES:
Input: head = [1,2,3,4,5], left = 2, right = 4
Output: [1,4,3,2,5]

Input: head = [5], left = 1, right = 1
Output: [5]

🎯 CONSTRAINTS:
- The number of nodes in the list is n
- 1 <= n <= 500
- -500 <= Node.val <= 500
- 1 <= left <= right <= n

⏰ TIME COMPLEXITY: O(N)
💾 SPACE COMPLEXITY: O(N)
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {

        vector<int> arr;

        ListNode* temp = head;

        while(temp != NULL){

            arr.push_back(temp->val);
            temp = temp->next;
        }

        reverse(arr.begin() + left - 1, arr.begin() + right);

        ListNode* newHead = new ListNode(-1);

        ListNode* curr = newHead;

        for(int i = 0; i < arr.size(); i++){

            ListNode* node = new ListNode(arr[i]);

            curr->next = node;

            curr = curr->next;
        }

        return newHead->next;
    }
};