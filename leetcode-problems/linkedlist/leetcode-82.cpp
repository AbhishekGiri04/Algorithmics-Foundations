/*
╔══════════════════════════════════════════════════════════════════════════════╗
║                          LEETCODE PROBLEM SOLUTION                           ║
╠══════════════════════════════════════════════════════════════════════════════╣
║ Problem ID    : 82                                                           ║
║ Problem Name  : Remove Duplicates from Sorted List II                        ║
║ Difficulty    : Medium                                                       ║
║ Topic         : Linked List                                                  ║
╚══════════════════════════════════════════════════════════════════════════════╝

📋 PROBLEM STATEMENT:
Given the head of a sorted linked list, delete all nodes that have duplicate
numbers, leaving only distinct numbers from the original list.
Return the linked list sorted as well.

📝 EXAMPLES:
Input: head = [1,2,3,3,4,4,5]
Output: [1,2,5]

Input: head = [1,1,1,2,3]
Output: [2,3]

🎯 CONSTRAINTS:
- The number of nodes in the list is in the range [0, 300]
- -100 <= Node.val <= 100
- The list is guaranteed to be sorted in ascending order

⏰ TIME COMPLEXITY: O(N log N)
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
    ListNode* deleteDuplicates(ListNode* head) {

        map<int,int> mp;

        while(head != NULL){
            mp[head->val]++;
            head = head->next;
        }

        ListNode* newhead = new ListNode(-1);
        ListNode* temp = newhead;

        for(auto it : mp){

            if(it.second == 1){

                ListNode* node = new ListNode(it.first);

                temp->next = node;
                temp = node;
            }
        }

        return newhead->next;
    }
};