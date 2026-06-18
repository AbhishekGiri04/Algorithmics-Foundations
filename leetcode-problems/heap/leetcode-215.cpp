╔══════════════════════════════════════════════════════════════════════════════╗
║                          LEETCODE PROBLEM SOLUTION                           ║
╠══════════════════════════════════════════════════════════════════════════════╣
║ Problem ID    : 215                                                          ║
║ Problem Name  : Kth Largest Element in an Array                              ║
║ Difficulty    : Medium                                                       ║
║ Topic         : Heap / Priority Queue                                        ║
╚══════════════════════════════════════════════════════════════════════════════╝

📋 PROBLEM STATEMENT:
Given an integer array nums and an integer k, return the kth largest element
in the array.

Note: It is the kth largest element in sorted order (not distinct).

📝 EXAMPLES:
Input: nums = [3,2,1,5,6,4], k = 2
Output: 5

Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
Output: 4

🎯 CONSTRAINTS:
- 1 <= k <= nums.length <= 1e5
- -1e4 <= nums[i] <= 1e4

⏰ TIME COMPLEXITY: O(N log K)
💾 SPACE COMPLEXITY: O(K)
*/

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;

        for (int x : nums) {
            pq.push(x);

            if (pq.size() > k) {
                pq.pop();
            }
        }

        return pq.top();
    }
};