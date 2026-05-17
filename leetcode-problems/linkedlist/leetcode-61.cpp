/*
╔══════════════════════════════════════════════════════════════════════════════╗
║                          LEETCODE PROBLEM SOLUTION                           ║
╠══════════════════════════════════════════════════════════════════════════════╣
║ Problem ID    : 61                                                           ║
║ Problem Name  : Rotate List                                                  ║
║ Difficulty    : Medium                                                       ║
║ Topic         : Linked List                                                  ║
╚══════════════════════════════════════════════════════════════════════════════╝

📋 PROBLEM STATEMENT:
Given the head of a linked list, rotate the list to the right by k places.

📝 EXAMPLES:
Input: head = [1,2,3,4,5], k = 2
Output: [4,5,1,2,3]

Input: head = [0,1,2], k = 4
Output: [2,0,1]

🎯 CONSTRAINTS:
- The number of nodes in the list is in the range [0, 500]
- -100 <= Node.val <= 100
- 0 <= k <= 2 * 10^9

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
    ListNode* rotateRight(ListNode* head, int k) {

        if(head == NULL || head->next == NULL)
            return head;

        vector<int> nums;

        while(head != NULL){
            nums.push_back(head->val);
            head = head->next;
        }

        k = k % nums.size();

        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());

        ListNode* newhead = new ListNode(nums[0]);
        ListNode* temp = newhead;

        for(int i = 1; i < nums.size(); i++){

            ListNode* newNode = new ListNode(nums[i]);

            temp->next = newNode;
            temp = newNode;
        }

        return newhead;
    }
};