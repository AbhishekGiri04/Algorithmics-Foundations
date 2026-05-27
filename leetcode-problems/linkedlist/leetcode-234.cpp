/*
╔══════════════════════════════════════════════════════════════════════════════╗
║                          LEETCODE PROBLEM SOLUTION                           ║
╠══════════════════════════════════════════════════════════════════════════════╣
║ Problem ID    : 234                                                          ║
║ Problem Name  : Palindrome Linked List                                       ║
║ Difficulty    : Easy                                                         ║
║ Topic         : Linked List                                                  ║
╚══════════════════════════════════════════════════════════════════════════════╝

📋 PROBLEM STATEMENT:
Given the head of a singly linked list, return true if it is
a palindrome or false otherwise.

📝 EXAMPLES:
Input: head = [1,2,2,1]
Output: true

Input: head = [1,2]
Output: false

🎯 CONSTRAINTS:
- The number of nodes in the list is in the range [1, 10^5]
- 0 <= Node.val <= 9

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

    bool isPalindrome(ListNode* head) {

        vector<int> arr;

        ListNode* temp = head;

        while(temp != NULL) {

            arr.push_back(temp->val);

            temp = temp->next;
        }

        int left = 0;
        int right = arr.size() - 1;

        while(left < right) {

            if(arr[left] != arr[right]) {
                return false;
            }

            left++;
            right--;
        }

        return true;
    }
};