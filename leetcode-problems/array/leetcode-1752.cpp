/*
╔══════════════════════════════════════════════════════════════════════════════╗
║                          LEETCODE PROBLEM SOLUTION                           ║
╠══════════════════════════════════════════════════════════════════════════════╣
║ Problem ID    : 1752                                                         ║
║ Problem Name  : Check if Array Is Sorted and Rotated                         ║
║ Difficulty    : Easy                                                         ║
║ Topic         : Array                                                        ║
╚══════════════════════════════════════════════════════════════════════════════╝

📋 PROBLEM STATEMENT:
Given an array nums, return true if the array was originally sorted 
in non-decreasing order, then rotated some number of positions 
(including zero). Otherwise, return false.

There may be duplicates in the original array.

📝 EXAMPLES:
Input: nums = [3,4,5,1,2]
Output: true

Input: nums = [2,1,3,4]
Output: false

Input: nums = [1,2,3]
Output: true

🎯 CONSTRAINTS:
- 1 <= nums.length <= 100
- 1 <= nums[i] <= 100

⏰ TIME COMPLEXITY: O(n)
💾 SPACE COMPLEXITY: O(1)
*/

class Solution {
public:
    bool check(vector<int>& nums) {

        int n = nums.size();
        int count = 0;

        for (int i = 0; i < n - 1; i++) {

            if (nums[i] > nums[i + 1]) {
                count++;
            }
        }

        if (nums[n - 1] > nums[0]) {
            count++;
        }

        if (count == 0 || count == 1) {
            return true;
        }

        return false;
    }
};