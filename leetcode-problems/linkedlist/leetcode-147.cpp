/*
╔══════════════════════════════════════════════════════════════════════════════╗
║                          LEETCODE PROBLEM SOLUTION                           ║
╠══════════════════════════════════════════════════════════════════════════════╣
║ Problem ID    : 147                                                          ║
║ Problem Name  : Insertion Sort List                                          ║
║ Difficulty    : Medium                                                       ║
║ Topic         : Linked List, Sorting                                         ║
╚══════════════════════════════════════════════════════════════════════════════╝

📋 PROBLEM STATEMENT:
Given the head of a singly linked list, sort the list using insertion sort,
and return the sorted list's head.

Insertion Sort Algorithm:
- Iterate through the list one element at a time.
- Insert each node into its correct position in the already sorted part.
- Continue until all nodes are sorted.

📝 EXAMPLES:
Input: head = [4,2,1,3]
Output: [1,2,3,4]

Input: head = [-1,5,3,4,0]
Output: [-1,0,3,4,5]

🎯 CONSTRAINTS:
- The number of nodes in the list is in the range [1, 5000]
- -5000 <= Node.val <= 5000

⏰ TIME COMPLEXITY: O(N²)
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

    void insertion(vector<int>& arr){

        int n = arr.size();

        for(int i = 1; i < n; i++){

            int key = arr[i];
            int j = i - 1;

            while(j >= 0 && arr[j] > key){

                arr[j + 1] = arr[j];
                j--;
            }

            arr[j + 1] = key;
        }
    }

    ListNode* insertionSortList(ListNode* head) {

        vector<int> arr;

        while(head != NULL){

            arr.push_back(head->val);
            head = head->next;
        }

        insertion(arr);

        ListNode* newHead = new ListNode(-1);
        ListNode* temp = newHead;

        for(int i = 0; i < arr.size(); i++){

            ListNode* node = new ListNode(arr[i]);

            temp->next = node;
            temp = node;
        }

        return newHead->next;
    }
};