/*
╔══════════════════════════════════════════════════════════════════════════════╗
║                          LEETCODE PROBLEM SOLUTION                           ║
╠══════════════════════════════════════════════════════════════════════════════╣
║ Problem ID    : 75                                                           ║
║ Problem Name  : Sort Colors                                                  ║
║ Difficulty    : Medium                                                       ║
║ Topic         : Array, Two Pointers, Sorting                                 ║
╚══════════════════════════════════════════════════════════════════════════════╝

📋 PROBLEM STATEMENT:
Given an array nums with n objects colored red, white, or blue,
sort them in-place so that objects of the same color are adjacent,
with the colors in the order red, white, and blue.

We use:
- 0 → Red
- 1 → White
- 2 → Blue

You must solve this problem without using the library's sort function.

📝 EXAMPLES:
Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]

Input: nums = [2,0,1]
Output: [0,1,2]

🎯 CONSTRAINTS:
- n == nums.length
- 1 <= n <= 300
- nums[i] is either 0, 1, or 2

⏰ TIME COMPLEXITY: O(n)
💾 SPACE COMPLEXITY: O(1)
*/

class Solution {
public:
    void sortColors(vector<int>& nums) {

        int low = 0;
        int mid = 0;
        int high = nums.size() - 1;

        while (mid <= high) {

            if (nums[mid] == 0) {

                swap(nums[low], nums[mid]);

                low++;
                mid++;
            }

            else if (nums[mid] == 1) {

                mid++;
            }

            else {

                swap(nums[mid], nums[high]);

                high--;
            }
        }
    }
};