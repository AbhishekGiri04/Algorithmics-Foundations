/*
╔══════════════════════════════════════════════════════════════════════════════╗
║                          LEETCODE PROBLEM SOLUTION                           ║
╠══════════════════════════════════════════════════════════════════════════════╣
║ Problem ID    : 83                                                           ║
║ Problem Name  : Remove Duplicates from Sorted List                           ║
║ Difficulty    : Easy                                                         ║
║ Topic         : Linked List                                                  ║
╚══════════════════════════════════════════════════════════════════════════════╝

📋 PROBLEM STATEMENT:
Given the head of a sorted linked list, delete all duplicates such that each
element appears only once.
Return the linked list sorted as well.

📝 EXAMPLES:
Input: head = [1,1,2]
Output: [1,2]

Input: head = [1,1,2,3,3]
Output: [1,2,3]

🎯 CONSTRAINTS:
- The number of nodes in the list is in the range [0, 300]
- -100 <= Node.val <= 100
- The list is guaranteed to be sorted in ascending order

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
    ListNode* deleteDuplicates(ListNode* head) {

        if(head == NULL){
            return head;
        }

        ListNode* slow = head;
        ListNode* fast = head->next;

        while(slow->next != NULL && fast != NULL){

            if(slow->val == fast->val){

                slow->next = fast->next;
                fast = fast->next;
            }
            else{

                slow = slow->next;
                fast = fast->next;
            }
        }

        return head;
    }
};