/*
╔══════════════════════════════════════════════════════════════════════════════╗
║                          LEETCODE PROBLEM SOLUTION                           ║
╠══════════════════════════════════════════════════════════════════════════════╣
║ Problem ID    : 148                                                          ║
║ Problem Name  : Sort List                                                    ║
║ Difficulty    : Medium                                                       ║
║ Topic         : Linked List, Merge Sort                                      ║
╚══════════════════════════════════════════════════════════════════════════════╝

📋 PROBLEM STATEMENT:
Given the head of a linked list, return the list after sorting it
in ascending order.

The follow-up asks for:
- Time Complexity  : O(N log N)
- Space Complexity : O(1) (excluding recursion stack)

📝 EXAMPLES:
Input: head = [4,2,1,3]
Output: [1,2,3,4]

Input: head = [-1,5,3,4,0]
Output: [-1,0,3,4,5]

Input: head = []
Output: []

🎯 CONSTRAINTS:
- The number of nodes in the list is in the range [0, 5 * 10^4]
- -10^5 <= Node.val <= 10^5

⏰ TIME COMPLEXITY: O(N log N)
💾 SPACE COMPLEXITY: O(log N) [Recursion Stack]
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

    ListNode* merge(ListNode* left, ListNode* right) {

        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;

        while(left != NULL && right != NULL) {

            if(left->val <= right->val) {

                temp->next = left;
                left = left->next;
            }
            else {

                temp->next = right;
                right = right->next;
            }

            temp = temp->next;
        }

        if(left != NULL) {
            temp->next = left;
        }

        if(right != NULL) {
            temp->next = right;
        }

        return dummy->next;
    }

    ListNode* findMid(ListNode* head) {

        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast != NULL && fast->next != NULL) {

            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    ListNode* sortList(ListNode* head) {

        if(head == NULL || head->next == NULL) {
            return head;
        }

        ListNode* mid = findMid(head);

        ListNode* rightHead = mid->next;
        mid->next = NULL;

        ListNode* left = sortList(head);
        ListNode* right = sortList(rightHead);

        return merge(left, right);
    }
};